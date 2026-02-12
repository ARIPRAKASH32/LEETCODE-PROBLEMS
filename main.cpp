#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main() {
    vector<int> nums;
    int n, x;
    cin >> n;
    while (cin >> x) nums.push_back(x);
    cout << (isSorted(nums, n) ? "True" : "False");
}
