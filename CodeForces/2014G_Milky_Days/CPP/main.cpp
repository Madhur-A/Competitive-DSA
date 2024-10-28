



#include <bits/stdc++.h>

int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

using longest = long long;

class pooer_solber {
public:
    template <typename __tp>
    struct __slow {
    public:
        inline static constexpr __tp fox() noexcept(false) { return __tp(); }
    };
public:
    using element = std::pair<longest, longest>;
public:
    inline static void solb(std::map<longest, longest> &g, longest &m, longest &k) {
        std::vector<element> t;
        longest res = 0, valid_day = 1, available = 0;
        // pivoting on days is necessary; since there's no priori information about whether the day
        // determined by q - m is the valid day, as there could be days inbetween
        for(std::pair<longest const, longest> const &node: g) {
            while(not t.empty() and valid_day < node.first) {
                longest const entry_day = t.back().first, delivered = t.back().second; t.pop_back();
                if(entry_day > valid_day - k) {
                    available = available * (not (valid_day < entry_day)); // no point in keeping score if valid_day < entry_day
                    valid_day = std::max(valid_day, entry_day);
                    if(m > available + delivered) {  // need more and can be added w/o overstepping m
                        available += delivered;
                    } else {
                        longest const lowerbound = std::min(entry_day + k, node.first); // lower bound notwithstanding satisfaction
                        longest const total_days = valid_day + (delivered + available) / m; // concerning satisfcation
                        longest const days_count = std::min(lowerbound, total_days) - valid_day; // actual count of days
                        longest const remainings = delivered + available - (days_count * m); // something is left (or not) to carry-over
                        (remainings) ? t.push_back({entry_day, remainings}) : __slow<void>::fox(); // if yes, then carry forward

                        valid_day += days_count;
                        res       += days_count;
                        available  = 0;
                    }
                }
            }
            t.push_back(node);
        }

        std::cout << res << '\n';
    }
};

int main() {
    int cases;
    std::cin >> cases;
    std::map<longest, longest> diary;
    longest n, m, k, day, amount;
    while(cases--) {
        std::cin >> n >> m >> k;
        diary.clear();
        for(longest i = 0; i < n; ++i) {
            std::cin >> day >> amount;
            diary[day] = amount;
        }
        diary[LLONG_MAX] = 0;
        pooer_solber::solb(diary, m, k);
    }


    return 0;

}
