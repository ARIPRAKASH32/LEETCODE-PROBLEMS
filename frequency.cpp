#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    unordered_map<char, int> h;
    for (int i = 0; i < s.length(); i++) {
        h[i]++;
    }
    for (auto i : h) {
        cout << i.first << " -> " << i.second << endl;
    }
}