class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weekdays{"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
        if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
            days[1] = 29;
        long totdays = day;
        for(int yr = 1971; yr < year; ++yr)
        {
            if((yr%4 == 0 && yr%100 != 0) || (yr%400 == 0))
                totdays += 366;
            else
                totdays += 365;
        }
        for(int i = 0; i < month-1; ++i)
            totdays += days[i];
        int ans = totdays%7;
        if(ans == 0)
            return weekdays[6];
        return weekdays[ans - 1];
    }
};
