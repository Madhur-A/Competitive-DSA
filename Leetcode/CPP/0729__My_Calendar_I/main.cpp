



#include <bits/stdc++.h>

class MyCalendar {
public:
    using element = std::pair<int, int>;
public:
    std::set<element> listings;
public:
    bool book(int start, int end) {
        std::set<element>::const_iterator res = listings.upper_bound({start, INT_MIN});
        if(res != listings.begin()) {
            --res;
            if(res->second > start) { return false; }
        }
        for(; res != listings.end() && res->first < end; ++res) {
            if(res->second > start) { return false; }
        }
        listings.insert({start, end});
        return true;
    }
};

int main() {
    MyCalendar cal;
    std::cout.setf(std::ios::boolalpha);

    std::cout << cal.book(10, 20) << '\n';
    std::cout << cal.book(15, 25) << '\n';
    std::cout << cal.book(20, 30) << '\n';


    return 0;
}
