import copy

def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("---------")

def is_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def is_draw(board):
    # Check if the board is full
    return all(board[i][j] != ' ' for i in range(3) for j in range(3))

def get_possible_moves(board):
    moves = []
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                moves.append((i, j))
    return moves

def apply_move(board, move, player):
    i, j = move
    new_board = [row.copy() for row in board]
    new_board[i][j] = player
    return new_board

def minimax(board, depth, maximizing_player):
    if is_winner(board, 'O'):
        return 1
    elif is_winner(board, 'X'):
        return -1
    elif is_draw(board):
        return 0

    if maximizing_player:
        max_eval = float('-inf')
        for move in get_possible_moves(board):
            new_board = apply_move(board, move, 'O')
            eval = minimax(new_board, depth + 1, False)
            max_eval = max(max_eval, eval)
        return max_eval
    else:
        min_eval = float('inf')
        for move in get_possible_moves(board):
            new_board = apply_move(board, move, 'X')
            eval = minimax(new_board, depth + 1, True)
            min_eval = min(min_eval, eval)
        return min_eval

def find_best_move(board):
    best_val = float('-inf')
    best_move = None

    for move in get_possible_moves(board):
        new_board = apply_move(board, move, 'O')
        move_val = minimax(new_board, 0, False)

        if move_val > best_val:
            best_val = move_val
            best_move = move

    return best_move

def play_tic_tac_toe():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    user_turn = True

    while True:
        print_board(board)

        if user_turn:
            user_row = int(input("Enter row (0, 1, or 2): "))
            user_col = int(input("Enter column (0, 1, or 2): "))
            if board[user_row][user_col] != ' ':
                print("Invalid move. Cell already occupied. Try again.")
                continue
            board[user_row][user_col] = 'X'
        else:
            print("Computer's move:")
            computer_move = find_best_move(board)
            board[computer_move[0]][computer_move[1]] = 'O'

        if is_winner(board, 'X'):
            print_board(board)
            print("You win!")
            break
        elif is_winner(board, 'O'):
            print_board(board)
            print("Computer wins!")
            break
        elif is_draw(board):
            print_board(board)
            print("It's a draw!")
            break

        user_turn = not user_turn

# Run the game
play_tic_tac_toe()
