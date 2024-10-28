



#include <bits/stdc++.h>

using longest = long long;

class pooer_solber {
public:
    using element = std::pair<longest, longest>;
public:
    inline static void insert_forward(std::map<longest, longest> &g, int const &d) {
        if(not g.count(d + 1)) { g[d + 1] = 0; }
    }

    inline static void solb(std::map<longest, longest> &g, longest &m, longest &k) {
        std::deque<element> t;
        int res = 0;

        for(std::pair<longest const, longest> const &node: g) {
            longest const d = node.first, q = node.second;
            if(m <= q) {
                if(m < q) {
                    t.push_back({d, q - m});
                }
                insert_forward(g, d);
                res += 1;
            } else {
                longest needed = m - q;
                while(not t.empty() and 0 < needed) {
                    element const popped = t.back(); t.pop_back();
                    longest const e_d = popped.first, e_r = popped.second;
                    if(d - k + 1 <= e_d) {
                        if(e_r <= needed) {
                            if(e_r == needed) {
                                res += 1;
                                insert_forward(g, d);
                                break;
                            } else {
                                needed = needed - e_r;
                            }
                        } else {
                            longest const diff = e_r - needed;
                            t.push_back({e_d, diff});
                            res += 1;
                            insert_forward(g, d);
                            break;
                        }
                    }
                }
            }
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
        pooer_solber::solb(diary, m, k);
    }



    return 0;
}

// 6
// 1 1 3 - case i
// 1 5
// 2 3 3 - case ii
// 1 5
// 2 7
// 4 5 2 - case iii
// 1 9
// 2 6
// 4 9
// 5 6
// 5 2 4 - case iv
// 4 7
// 5 3
// 7 1
// 11 2
// 12 1
// 4 1 3 - case v
// 5 10
// 9 4
// 14 8
// 15 3
// 5 5 5 - case vi
// 8 9
// 10 7
// 16 10
// 21 5
// 28 9
