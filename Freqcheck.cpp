#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    map<char,int>mp;
    for(char c:s){
        if(c==' '){
            continue;
        }
        mp[c]++;
    }
    for(auto val:mp){
        cout<<val.first<<"  "<<val.second<<endl;
    }

    return 0;
}
