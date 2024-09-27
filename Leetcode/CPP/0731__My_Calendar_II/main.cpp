



#include <bits/stdc++.h>

class MyCalendarTwo {
public:
public:
    std::map<int, int> listings;
public:
    bool book(int start, int end) {
        listings[start] += 1;
        listings[end]   -= 1;
        int times = 0;
        for(std::pair<int const, int> const &booking: listings) {
            times += booking.second;
            if(times > 2) {
                listings[start] -= 1;
                listings[end]   += 1;
                return false;
            }
        }

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
