
#include <bits/stdc++.h>
using namespace std;
bool Amstrongnum(int num){
    int dig=to_string(num).size();
    int temp=num;
    int sum=0;
    while(num!=0){
        sum+=(pow(num%10,dig));
        num/=10;
    }
    return sum==temp;
}
set<int> getDivisord(int n){
    set<int> vc;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            vc.insert(i);
        }
        if(i!=n/i){
            vc.insert(n/i);
        }
    }
    return vc;
}
int main() {
    int n;
    cin>>n;
    set<int> vc=getDivisord(n);
    
    for(int val:vc){
        cout<<val<<" ";
    }

    return 0;
}
