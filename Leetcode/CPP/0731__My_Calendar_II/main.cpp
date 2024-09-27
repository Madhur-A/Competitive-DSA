



#include <bits/stdc++.h>

class MyCalendarTwo {
public:
    using element = std::pair<int, int>;
public:
    std::set<element> overlaps;
    std::set<element> events;
public:
    bool book(int start, int end) {
        std::set<element>::const_iterator search = overlaps.upper_bound({start, INT_MIN});
        for(; search != overlaps.end() and search->first < end; ++search) {
            if(search->second > start) { return false; }
        }

        search = events.upper_bound({start, INT_MIN});
        for(; search != events.end() and search->first < end; ++search) {
            if(search->second > start) {
                overlaps.insert({std::max(start, search->first), std::min(end, search->second)});
            }
        }

        events.insert({start, end});
        return true;
    }
};

int main() {
    MyCalendarTwo sol;
    std::vector<MyCalendarTwo::element> bookings = {{10,20},{50,60},{10,40},{5,15},{5,10},{25,55}};
    std::cout.setf(std::ios::boolalpha);
    for(MyCalendarTwo::element const &booking: bookings) {
        std::cout << sol.book(booking.first, booking.second) << '\n';
    }


    return 0;
}
