#include <iostream>
#include <set>
using namespace std;

int maxIntegersInPot(int n, int* a) {
    set<int> pot;

    for (int i = 0; i < n; ++i) {
        pot.insert(a[i]);

        for (int j = 0; j < i; ++j) {
            int diff = a[i] - a[j];
            pot.insert(diff);
        }
    }

    return pot.size();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int result = maxIntegersInPot(n, a);
        cout << result << endl;
    }

    return 0;
}
