#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    multiset<long long> ms = {a, b, c, d};
    set<long long> s(ms.begin(), ms.end());

    int first;
    if (s.size() == 4) {
        first = 2;
    } else if (s.size() == 2) {
        auto it = s.begin();
        long long x = *it;
        ++it;
        long long y = *it;
        if (ms.count(x) == 2 && ms.count(y) == 2)
            first = 2;
        else
            first = 1;
    } else {
        first = 1;
    }

    long long mx = *ms.rbegin();
    int second = (ms.count(mx) > 1 ? 1 : 0);

    long long third = mx - *ms.begin();

    cout << first << " " << second << " " << third;
    return 0;
}
