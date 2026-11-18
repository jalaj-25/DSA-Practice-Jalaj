// 3364-min-positive-sum-subarray.cpp;math-matrix;leetcode

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;

                if(len >= l && len <= r) {
                    if(sum > 0) {
                        if(sum < ans) {
                            ans = sum;
                        }
                    }
                }

                if(len > r) break;
            }
        }

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};