class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        if (groupSize == 1) return true;

        unordered_map<int, int> store;
        for (int card : hand) {
            store[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& getted : store) {
            minHeap.push(getted.first);
        }

        while (!minHeap.empty()) {
            int firsted = minHeap.top();
            if (store[firsted] == 0) {
                minHeap.pop();
                continue;
            }

            for (int i = 0; i < groupSize; i++) {
                int nextCard = firsted + i;

                if (store[nextCard] == 0) {
                    return false; 
                }

                store[nextCard]--;
            }
        }

        return true;
    }
};
