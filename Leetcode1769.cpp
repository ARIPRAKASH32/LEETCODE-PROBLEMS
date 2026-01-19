class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length(),0);
        int o=0;
        int c=0;
        for(int i=0 ; i<boxes.length() ; i++){
            res[i] +=o;
            if(boxes[i] == '1') c++;
            o += c; 
           
        }
        c=0;
        o=0;
        for(int i=boxes.length()-1 ; i>=0 ; i--){
            res[i] +=o;
            c += boxes[i] == '1'?1:0;
            o += c; 
           
        }
        return res;
    }
};