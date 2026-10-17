class TopVotedCandidate {
private:
    vector<int> lead;
    vector<int> time; 
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        time = move(times);
        lead.assign(n , 0);
        unordered_map<int, int> voteCount;
        int leader = -1, maxVotes = 0;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            if (++voteCount[p] >= maxVotes) {
                leader = p;
                maxVotes = voteCount[p];
            }
            lead[i] = leader;
        }
    }
    int q(int t) {
        int idx = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;
        return lead[idx];
    }
};
