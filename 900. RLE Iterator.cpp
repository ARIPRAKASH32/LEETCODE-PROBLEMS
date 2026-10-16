class RLEIterator {
private:
    vector<int> encoding;
    int index = 0;
public:
    RLEIterator(vector<int>& encoding){
        this->encoding = encoding;
    }
    int next(int n) {
        while (index < encoding.size() && n > encoding[index]) {
            n -= encoding[index];
            index += 2;
        }
        if (index >= encoding.size()) return -1;
        encoding[index] -= n;
        return encoding[index + 1];
    }
};
