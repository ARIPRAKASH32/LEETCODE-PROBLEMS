class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {

        int x = (tomatoSlices - 2*cheeseSlices)/2;
        int y = (cheeseSlices - x);
        vector<int> ans;
        if(x>=0 && y>=0 && 4*x+2*y == tomatoSlices){
            ans.push_back(x);
            ans.push_back(y);
        }
        return ans;
    }
};
