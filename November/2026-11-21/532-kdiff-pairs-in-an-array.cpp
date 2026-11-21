// 532-kdiff-pairs-in-an-array.cpp;leetcode;2p;self


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        int count = 0;
        for (auto it : mp) {
            int x = it.first;
            if (k == 0) {
                if (it.second >= 2) {
                    count++;
                }
            }
            else {
                if (mp.find(x + k) != mp.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};
