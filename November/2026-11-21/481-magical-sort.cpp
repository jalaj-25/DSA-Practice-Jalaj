// 481-magical-sort.cpp;leetcode;two-pointer;self

class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;

        vector<int> s(n, 0);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int count = 1;
        int i = 2;
        int num = 1;

        for (int j = 3; j < n; j++) {
            for (int k = 0; k < s[i]; k++) {
                if (j >= n) break;

                s[j] = num;

                if (num == 1) {
                    count++;
                }

                j++;
            }

            j--;
            num = 3 - num;
            i++;
        }

        return count;
    }
};