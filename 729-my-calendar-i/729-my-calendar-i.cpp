class MyCalendar {
    set<pair<int,int>> st;
public:
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        end--;
        if(st.size() == 0 || st.rbegin()->second < start || end < st.begin()->first) {
            st.insert({start, end});
            return true;
        } else if(st.size() == 1) return false;
         
        auto it = st.upper_bound({start, -1});
        auto it2 = it;  it--;
        if(it->second < start && end < it2->first) {
            st.insert({start, end});
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */