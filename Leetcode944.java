import java.util.*;
class Solution {
    public int minDeletionSize(String[] strs) {
        int res = 0;
        for (int j = 0; j < strs[0].length(); j++)
            res += isUnsorted(strs, j);
        return res;
    }

    private int isUnsorted(String[] strs, int j) {
        for (int i = 1; i < strs.length; i++)
            if (strs[i].charAt(j) < strs[i - 1].charAt(j))
                return 1;
        return 0;
    }
}
public class Leetcode944{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] arr = new int[n];
		for(int i=0 ; i<n; i++){
			arr[i]=sc.nextInt();
		}
	} 
}