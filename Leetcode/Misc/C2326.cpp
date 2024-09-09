



class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::vector<int>> res;
    ListNode* root;
public:
    bool is_valid(int i, int j) {
        return 0 <= i and 0 <= j and i < res.size() and j < res[0].size() and res[i][j] == -1;
    }

    void remap(int i, int j, int fix=0) {
        if(root and is_valid(i, j)) {
            res[i][j] = root->val;
            int const h = dirs[fix].first + i, k = dirs[fix].second + j;
            if(root) {
                root = root->next;
                if(is_valid(h, k)) {
                    remap(h, k, fix);
                } else {
                    int const nd = (fix + 1) % 4;
                    remap(i + dirs[nd].first, j + dirs[nd].second, nd);
                }
            }
        }
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        res.resize(m, std::vector<int>(n, -1));
        root = head;
        remap(0, 0);

        return res;
    }
};
