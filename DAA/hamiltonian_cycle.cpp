#include <iostream>
#include <vector>
#include <algorithm>
class HamiltonianCycle {
public:
    HamiltonianCycle(int vertices);

    void addEdge(int src, int dest);
    void findHamiltonianCycle();

private:
    int vertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<int> path;

    bool isSafe(int v, int pos);
    bool hamiltonianCycleUtil(int pos);
};

HamiltonianCycle::HamiltonianCycle(int vertices) : vertices(vertices) {
    adjacencyMatrix.resize(vertices, std::vector<int>(vertices, 0));
    path.resize(vertices, -1);
}

void HamiltonianCycle::addEdge(int src, int dest) {
    adjacencyMatrix[src][dest] = 1;
    adjacencyMatrix[dest][src] = 1; // Assuming the graph is undirected
}

void HamiltonianCycle::findHamiltonianCycle() {
    path[0] = 0;

    if (hamiltonianCycleUtil(1)) {
        std::cout << "Hamiltonian Cycle found: ";
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << path[0] << std::endl;
    } else {
        std::cout << "No Hamiltonian Cycle exists in the given graph.\n";
    }
}

bool HamiltonianCycle::isSafe(int v, int pos) {
    if (!adjacencyMatrix[path[pos - 1]][v]) {
        return false;
    }

    for (int i = 0; i < pos; ++i) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool HamiltonianCycle::hamiltonianCycleUtil(int pos) {
    if (pos == vertices) {
        return adjacencyMatrix[path[pos - 1]][path[0]] == 1;
    }
    for (int v = 1; v < vertices; ++v) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    HamiltonianCycle graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.findHamiltonianCycle();

    return 0;
}

