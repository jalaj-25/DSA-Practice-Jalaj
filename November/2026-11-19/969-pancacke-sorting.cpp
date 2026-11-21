// 969-pancacke-sorting.cpp;math-2p;leetcode;sself

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for (int size = n; size > 1; size--) {
            int maxIdx = 0;
            for (int i = 1; i < size; i++) {
                if (arr[i] > arr[maxIdx]) {
                    maxIdx = i;
                }
            }

            if (maxIdx == size - 1) {
                continue;
            }

            if (maxIdx != 0) {
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
                ans.push_back(maxIdx + 1);
            }

            reverse(arr.begin(), arr.begin() + size);
            ans.push_back(size);
        }

        return ans;
    }
};
