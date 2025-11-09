



import java.util.*;

class Solution {
    public int uniqueLetterString(String s) {
        int n = s.length(); char[] sc = s.toCharArray();

        // the idea is simple; consider any index `i` at which some character `c` occurs,
        // then, its contribution would be `(i - previous_occurrence_of_c) x (last_occurrence_of_c - i)`;
        // indeed, as it is common in substring related problems, `(curr_length - prev_length)` is a very
        // familiar metric for such scenarios, which in its usual meaning gives the number of possible
        // substrings (when summed over whole range of `curr_length`s). please note the default values are
        // usually taken as `-1` and `n`, to compensate by-one-error, which arises due to indexing starting
        // from `0` instead of `1`.

        int[] prev = new int[n], next = new int[n];
        int[] front = new int[26], back = new int[26];

        Arrays.fill(front, -1); Arrays.fill(back, n);

        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            prev[i] = front[sc[i] - 'A'];
            next[j] = back[sc[j] - 'A'];
            front[sc[i] - 'A'] = i;
            back[sc[j] - 'A']  = j;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += (i - prev[i]) * (next[i] - i);
        }

        return res;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
