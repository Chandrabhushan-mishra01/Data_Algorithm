#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    uint32_t rev = 0;

    for (int i = 0; i < 32; i++) {
        rev <<= 1;      // Left shift 'rev' by 1
        if (n & 1)
            rev |= 1;   // Set the least significant bit of 'rev' if the least significant bit of 'n' is 1
        n >>= 1;        // Right shift 'n' by 1
    }

    cout << rev;

    return 0;
}
