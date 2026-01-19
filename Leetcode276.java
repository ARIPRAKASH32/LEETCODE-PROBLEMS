class Solution {
    public int hIndex(int[] citations) {
        int papers = citations.length;
        int[] citationBuckets = new int[papers + 1];

        for (int citation : citations) {
            citationBuckets[Math.min(citation, papers)]++;
        }

        int cumulativePapers = 0;
        for (int hIndex = papers; hIndex >= 0; hIndex--) {
            cumulativePapers += citationBuckets[hIndex];
            if (cumulativePapers >= hIndex) {
                return hIndex;
            }
        }
        return 0;        
    }
}
public class Leetcode274{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int low = sc.nextInt();
		int [] arr = new int[low];
		for(int i=0 ; i<low ; i++){
			arr[i]= sc.nextInt();
		}		
		Solution sol = new Solution();
		System.out.println(sol.evalRPN(arr));
	}
}