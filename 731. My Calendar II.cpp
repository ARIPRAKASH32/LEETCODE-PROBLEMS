class MyCalendarTwo {
public:
    vector<pair<int, int>> track;
    vector<pair<int, int>> doubleBook;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
          for (auto data : doubleBook) {
            if (max(start, data.first) < min(end, data.second)) {
                return false;
            }
        }
        for (auto data : track) {
            if (max(start, data.first) < min(end, data.second)) {
                doubleBook.push_back({max(start, data.first), min(end, data.second)});
            }
        }
        track.push_back({start, end});
        return true;
    }
};
