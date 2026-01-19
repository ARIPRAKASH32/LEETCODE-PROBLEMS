class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int count = 0;
        int line = matrix.length;
        int column = matrix[0].length + 1;
        int[][] sum = new int[line][column];
        
        for (int i = 0; i < sum.length; i++){
            for (int j = 1; j < sum[0].length; j++){
                sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
            }
        }
        
        
        for (int start = 0; start < column; start++){
            for (int end = start + 1; end < column; end++ ){
                
                int sumOfSubMatrix = 0;
                Map<Integer, Integer> map = new HashMap<Integer, Integer>();
                map.put(0, 1);
                for(int l = 0; l < line; l++){
                    sumOfSubMatrix += sum[l][end] - sum[l][start];
                    if (map.containsKey(sumOfSubMatrix - target))
                        count += map.get(sumOfSubMatrix - target);
                    map.put(sumOfSubMatrix, map.getOrDefault(sumOfSubMatrix, 0) + 1);
                    
                }
            }
        }
        
        return count;
    }
}
public class Leetcode1027{
	public static void main(){
		Scanner sc = new Scanner(System.in);
		int target = sc.nextInt();
		int n = sc.nextInt();
		int [][]arr = new int[n][n];
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				arr[i][j] = sc.nextInt();

			}
		}
		Solution sol = new Solution();
		System.out.println(sol.Solution(count));
		
	}
}