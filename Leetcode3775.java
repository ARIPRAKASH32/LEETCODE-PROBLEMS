class Solution {
    public String reverseWords(String s) {
        String[] word = s.split(" ");
        int target = countVowels(word[0]);

        for(int i=1 ; i<word.length ; i++){
            if(countVowels(word[i])==target){
                word[i]=new StringBuilder(word[i]).reverse().toString();
            }
        }
        return String.join(" ",word);
    }
        
    private int countVowels(String word){
        int count = 0;
        for(char c : word.toCharArray()){
            if(c=='a'||c=='e' ||c=='i'||c=='o'||c=='u'){
                count++;
            }
        }
        return count;
    }
}
public class Leetcode3775{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		Solution sol = new Solution();
		System.out.println(sol.numberOfWays(s));
	}
}