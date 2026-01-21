class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        Collections.sort(events, (a,b)-> {
            int x = Integer.parseInt(a.get(1));
            int y = Integer.parseInt(b.get(1));

            int m1 = a.get(0).equals("OFFLINE") ? 0 : 1;
            int m2 = b.get(0).equals("OFFLINE") ? 0 : 1;
            return x==y ? m1-m2 : x-y; }
        );

        int[] ans = new int[numberOfUsers];   
        int[] online = new int[numberOfUsers];
        int allCount = 0;    

        for(List<String> event : events){
            String type = event.get(0);
            if(type.equals("MESSAGE")){
                int time=Integer.parseInt(event.get(1));

                String mention = event.get(2);
                if(mention.equals("ALL")){
                    for(int i=0; i<numberOfUsers; i++) ans[i]++;
                }
                else if(mention.equals("HERE")){
                    for(int i=0; i<numberOfUsers; i++){
                        if(time>=online[i]) ans[i]++;
                    }
                }
                else{
                    String[] users = mention.split(" ");
                    for(String user : users){
                        int id = Integer.parseInt(user.substring(2,user.length()));
                        ans[id]++;
                    }
                }
            }

            else{
                int id = Integer.parseInt(event.get(2));
                int time = Integer.parseInt(event.get(1));
                online[id]=time+60;
            }
        }

        return ans;
    }
}