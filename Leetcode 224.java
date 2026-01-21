class Solution {
    int i;
    public int calculate(String s) {
        i=0;
        return cal(s);
    }
    private int cal(String s){
        int res = 0, num = 0, sign = 1;
        while (i < s.length()) {
            char c = s.charAt(i++);
            if (Character.isDigit(c)) {
                num = num*10+(c - '0');
            }
            else if (c == '(') {
                num = cal(s);   
            }
            else if (c == ')') {
                return res + sign * num; 
            }
            else if (c == '+' || c == '-'){  
                res += sign * num;
                num = 0;
                sign = (c == '-') ? -1 : 1;
            }
        }
        return res + sign * num;
    }
}