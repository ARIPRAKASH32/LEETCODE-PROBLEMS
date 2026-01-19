class Solution {

    
        private final String [] ones = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        private final String [] tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        private final String [] hund = {"","Thousand","Million","Billion"};
    
    public String numberToWords(int num) {
        if(num ==0) return "Zero";
        int i=0;
        String s = "";
        while(num>0){
            if(num%1000!=0){
                s = help(num%1000)+hund[i]+" "+ s;
            }
            num/=1000;
            i++;
        }
        return s.trim();
    }
    private String help(int num){
        if(num==0) return "";
        else if(num<20) return ones[num] + " ";
        else if(num<100) return tens[num/10]+ " "+help(num%10);
        else return ones[num/100]+" Hundred "+ help(num%100);
    }
}