class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> open;
        stack<int> close;
        vector<int> temp;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open.push(i);
            }else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else{
                    close.push(i);
                }
            }
        }

        while(!open.empty() && !close.empty()){
            if(open.top() > close.top()){
                temp.push_back(open.top());
                open.pop();
            }else if(open.top() < close.top()){
                open.pop();
                close.pop();
            }
        }

        while(!open.empty()){
            temp.push_back(open.top());
            open.pop();
        }

        while(!close.empty()){
            temp.push_back(close.top());
            close.pop();
        }

        sort(temp.begin(), temp.end());

        string p = "";
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(count < temp.size() && i == temp[count]){
                count++;
            }else{
                p += s[i];
            }
        }

        return p;
    }
};
