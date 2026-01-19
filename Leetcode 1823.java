class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> cir = new ArrayList<>();
        for(int i=1 ; i<=n ; i++){
            cir.add(i);
        }
        int in = 0;
        while(cir.size() > 1){
            int index = (in+k-1)%cir.size();
            cir.remove(index);
            in = index;
        }
        return cir.get(0);
    }
}