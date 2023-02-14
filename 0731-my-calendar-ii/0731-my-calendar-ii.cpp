class MyCalendarTwo {
public:
    vector<pair<int,int>> calendar;
    vector<pair<int,int>> overlap;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        for(auto cur : overlap)
            if(start < cur.second && end > cur.first)
                return false;
        
        for(auto cur : calendar)
            if(start < cur.second && end > cur.first)
                overlap.push_back({max(start, cur.first), min(end, cur.second)});
        
        calendar.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */