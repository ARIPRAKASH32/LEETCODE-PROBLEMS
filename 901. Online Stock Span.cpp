class StockSpanner {
private:
    int idx;
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        idx = -1;
        while (!st.empty()) {
            st.pop();
        }
    }

    int next(int price) {
        idx = idx + 1;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans;
        if (st.empty()) {
            ans = idx - (-1);
        } else {
            ans = idx - st.top().second;
        }
        st.push({price, idx});

        return ans;
    }
};
