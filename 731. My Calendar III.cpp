class MyCalendarTwo {
public:
    map<int, int> diff;

    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        diff[startTime]++;
        diff[endTime]--;

        int cur = 0;

        for (auto& [time, a] : diff) {
            cur += a;

            if (cur >= 3) {
                diff[startTime]--;
                diff[endTime]++;
                return false;
            }
        }

        return true;
    }
};
