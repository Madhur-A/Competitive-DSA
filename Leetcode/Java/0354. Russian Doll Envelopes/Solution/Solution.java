



import java.util.*;

class Solution {
    public int findLeft(List<Integer> nums, int target) {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums.get(mid) < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public int maxEnvelopes(int[][] dolls) {
        int n = dolls.length;
        Arrays.sort(dolls, (a, b) -> {
            return (a[0] == b[0]) ?
                Integer.compare(-a[1], -b[1]) : // if lasts are equal then
                Integer.compare(a[0], b[0]); // then sort on firsts
        });

        List<Integer> bs = new ArrayList<>();
        bs.add(dolls[0][1]);

        for (int i = 1; i < n; ++i) {
            int w = dolls[i][0], h = dolls[i][1];
            int last = bs.get(bs.size() - 1);
            if (h > last) {
                bs.add(h);
            } else {
                bs.set(findLeft(bs, h), h);
            }
        }


        return bs.size();
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
