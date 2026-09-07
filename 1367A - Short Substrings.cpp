#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string b;
        cin >> b;

        string a;
        a += b[0];

        for (int i = 1; i < b.size(); i += 2) {
            a += b[i];
        }

        cout << a << '\n';
    }

    return 0;
}
