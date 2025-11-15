class RandomizedCollection {
    unordered_map<int,unordered_set<int>>mpp;
    vector<int>arr;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mpp[val].insert(arr.size());
        arr.push_back(val);
        if(mpp[val].size()>=2) return false;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end() || mpp[val].empty()){
            return false;
        }
        auto it=mpp[val].begin();
        int inx=*(it);
        mpp[val].erase(inx);
        mpp[arr.back()].insert(inx);
        mpp[arr.back()].erase(arr.size()-1);
        arr[inx]=arr.back();
        arr.pop_back();
        if(mpp[val].empty()) mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
