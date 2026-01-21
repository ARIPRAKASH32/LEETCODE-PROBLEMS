class Solution {
    public long maxSpending(int[][] values) {
        
        ArrayList<Integer> al = new ArrayList<Integer>();
        for(int i=0;i<values.length;i++){
            for(int j=0; j<values[0].length;j++)
                 al.add(values[i][j]);     
        }
        
        Collections.sort(al);
        long k=1, result=0;
        for(int a: al) result+=a*(k++);
        return result;   
        
    }
}
public class Leetcode2931 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int n = sc.nextInt();
        int[][] arr = new int[n][m];
	for(int i=0 ; i<n ; i++)
	{
		for(int  j =0 ; j<m ; j++
		{
			arr[i] = sc.nextInt();
		}
	}
        Solution sol = new Solution();
	
        System.out.println(sol.countPermutations(arr));      }
}