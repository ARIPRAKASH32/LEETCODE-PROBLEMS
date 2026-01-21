class Solution {
    public int candy(int[] num) {
        int n = num.length;
        int [] l = new int[n]; 
        l[0] = 1;
        int [] r = new int[n]; 
        r[n-1] = 1;
        for(int i =1 ; i<n ; i++){
            if(num[i]>num[i-1]){
                l[i]=l[i-1]+1;
            }
            else{
                l[i]=1;
            }
        }
        for(int i =n-2 ; i>=0 ; i--){
            if(num[i]>num[i+1]){
                r[i]=r[i+1]+1;
            }
            else{
                r[i]=1;
            }
        }
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum=sum+Math.max(l[i],r[i]);
        }
        return sum;
    }
}