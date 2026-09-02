#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y, W;
    cin >> Y >> W;

    int good = 6 - max(Y, W) + 1;
    int g = gcd(good, 6);

    cout << good / g << "/" << 6 / g;

    return 0;
}
