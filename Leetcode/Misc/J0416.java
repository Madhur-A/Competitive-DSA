



public class Solution {
    public Map<Long, Boolean> seen;

    public boolean topDown(int[] nums, int target, int current, int index) {
    	long key = index * target + current;
    	if (current ==     target) { return true;  }
    	if (seen.containsKey(key)) { return seen.get(key);     }
    	if (index  == nums.length) { return current == target; }
    	if (index   > nums.length) { return false; }
    	if (current >      target) { return false; }

        // [!] this is dangerous (not advisable)
    	seen.put(key, topDown(nums, target, current + nums[index], index + 1) || topDown(nums, target, current, index + 1));

    	return seen.getOrDefault(key, false);
    }


    public boolean bottomUp(int[] nums) { 
    	final int n = nums.length, sigma = Arrays.stream(nums).sum();
    	if ((sigma & 1) == 1) { return false; }
    	final int target = sigma / 2;
    	boolean[] dp = new boolean[target + 1];
    	dp[0] = true;

    	for (int i = 0; i < n; ++i) {
    		for (int subTarget = target; subTarget >= nums[i]; --subTarget) {
    			if (dp[subTarget] == false && dp[subTarget - nums[i]] == true) {
    				if (subTarget == target) { return true; }
    				dp[subTarget] = true;
    			}
    		}
    	}

    	return dp[target];
    }

    public boolean canPartition(int[] nums) {
        final int sigma = Arrays.stream(nums).sum();
        if ((sigma & 1) == 1) { return false; }
        final int target = sigma / 2;
        seen = new HashMap<>();
        return topDown(nums, target, 0, 0);
    }
}
