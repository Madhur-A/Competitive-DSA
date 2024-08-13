



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using course = std::vector<int>;
public:
    std::priority_queue<int> t;
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int const n = courses.size();
        std::ranges::sort(courses, [&](course const &a, course const &b){ return a[1] < b[1]; });
        int total_time = 0;
        for(int i = 0; i < n; ++i) {
            int const day = courses[i][0], limit = courses[i][1];
            t.push(day);
            total_time += day;
            if(total_time > limit) {
                total_time = total_time - t.top();
                t.pop();
            }
        }
        return t.size();
    }
};

int main() {
    std::vector<std::vector<int>> courses = {{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    Solution sol;
    std::fprintf(stdout, "ans is [%d]\n", sol.scheduleCourse(courses));


    return 0;
}
