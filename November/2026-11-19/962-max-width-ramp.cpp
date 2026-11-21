// 962-max-width-ramp.cpp;math-2p-stack;leetcode;help

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int ans = 0;
        for(int j = n - 1; j >= 0; j--) {
            while(!st.empty() && nums[j] >= nums[st.top()]) {
                int i = st.top();
                st.pop();

                ans = max(ans, j - i);
            }
        }

        return ans;
    }
};