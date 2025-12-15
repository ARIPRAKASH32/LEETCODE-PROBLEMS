#include <bits/stdc++.h>
using namespace std;

string toLetters(int c){
    string s;
    while(c){
        c--;
        s += char('A' + c % 26);
        c /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
}

int toNumber(string s){
    int v = 0;
    for(char c : s) v = v * 26 + (c - 'A' + 1);
    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;

        if(s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos){
            int pos = s.find('C');
            int row = stoi(s.substr(1, pos - 1));
            int col = stoi(s.substr(pos + 1));
            cout << toLetters(col) << row << "\n";
        } else {
            int i = 0;
            while(isalpha(s[i])) i++;
            string col = s.substr(0, i);
            int row = stoi(s.substr(i));
            cout << "R" << row << "C" << toNumber(col) << "\n";
        }
    }
}
