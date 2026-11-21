// 321-create-max-number.cpp;math-2p-stack;leetcode;help

class Solution {
public:
    vector<int> maxSubSequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for(int num : nums) {
            while(!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            } 

            st.push_back(num);
        }

        st.resize(k);

        return st;
    } 

    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while(i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if(j == b.size()) return true; 
        if(i == a.size()) return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        while(i < a.size() || j < b.size()) {
            if(greater(a, i, b, j)) {
                result.push_back(a[i]);
                i++;
            } else {
                result.push_back(b[j]);
                j++;
            }
        }    

        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans(k, 0);
        for(int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> a = maxSubSequence(nums1, i);
            vector<int> b = maxSubSequence(nums2, k - i);

            vector<int> candidate = merge(a, b);

            if(greater(candidate, 0, ans, 0)) {
                ans = candidate;
            }
        }

        return ans;
    }
};