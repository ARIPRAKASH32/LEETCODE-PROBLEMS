class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<>();
        StringBuilder res = new StringBuilder();
        String [] pa = path.split("/");
        for(int i=0 ; i<pa.length ; i++){
            if(!s.isEmpty() && pa[i].equals("..")) s.pop();
            else if(!pa[i].equals("") && !pa[i].equals(".") && !pa[i].equals("..")) 
                s.push(pa[i]);
        }
        if(s.isEmpty()) return "/";
        while(!s.isEmpty()){
            res.insert(0, s.pop()).insert(0,"/");
        }
        return res.toString();
    }
}