import java.util.*;
class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        if(n==1) return 0;
        int l = 0 , r = n-1;
        while(l<r && directions.charAt(l)=='L') l++;
        while(l<r && directions.charAt(r)=='R') r--;
        if(l>=r) return 0;
        int col = 0;
        for(; l<=r ; l++){
            col+=(directions.charAt(l)!='S'?1:0);
        }
        return col;

    }
}
public class Leetcode2211{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		Solution sol = new Solution();
		System.out.println(sol.countCollisions(s));

	}
}