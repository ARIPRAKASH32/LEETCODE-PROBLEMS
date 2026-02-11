#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> a, int x);

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    cout << linearSearch(a, x);
}
