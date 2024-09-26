class MyCalendar {
private:
    vector<pair<int, int>> events; 
    
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        // Check if the new event overlaps with any existing event
        for (const auto& event : events) {
            int bookedStart = event.first;
            int bookedEnd = event.second;
            
            
            if (start < bookedEnd && end > bookedStart) {
                return false;
            }
        }
        
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
