class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long sum = 0;
        for(int i=0 ; i<batteries .length ; i++){
            sum+=batteries[i];
        }
        long left = 1;
        long right = sum;

        while(left<right){
            long target = right - (right-left)/2;
            long t = 0;
            for(long i : batteries){
               t+=Math.min(i,target);

            }
            if(t>=n*target){
                left = target;
            }
            else{
                right = target-1;
            }
        }
        return right;
    }
}