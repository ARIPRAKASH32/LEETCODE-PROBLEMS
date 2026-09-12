class Solution {
public:


    int findInverse(int level, int value) {
        int x = value - (1<<level);
        int inv = (1<<(level+1)) - 1 - x;
        return inv;
    }

    vector<int> pathInZigZagTree(int label) {
        if (label == 1) return {1};

        int level = log2(label);
        vector<int> path;
        while(level > 0) {
            path.push_back(label);
            if (level % 2 == 0) {
                int parent = label/2;
                int inv = findInverse((int)log2(parent), parent);
                label = inv;
            }
            else {
                int h = log2(label);
                int inverse = findInverse(h, label);
                int parent = inverse/2;
                label = parent;
            }
            level--;
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
