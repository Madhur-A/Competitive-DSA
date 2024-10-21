



class Solution {
    public Set<String> seen = new HashSet<>();
    public int res = 0;

    public void rx(String s, int index, int count) {
        if (s.length() <= index) { res = Math.max(res, count); return; }
        for (int j = index + 1; j < s.length() + 1; ++j) {
            String sub = s.substring(index, j);
            if (!seen.contains(sub)) {
                seen.add(sub);
                rx(s, j, count + 1);
                seen.remove(sub);
            }
        }
    }

    public int maxUniqueSplit(String s) {
        rx(s, 0, 0);
        return res;
    }
}
