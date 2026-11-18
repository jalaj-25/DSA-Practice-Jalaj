// 3789-min-cost-to-acquire-req-items.cpp3789-min-cost-to-acquire-req-items.cpp;help;leetcode;math

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        int common = min(need1, need2);
        long long ans2 = 1LL * common * costBoth + 1LL * (need1 - common) * cost1 + 1LL * (need2 - common) * cost2;

        int total = max(need1, need2);

        long long ans3 = 1LL * total * costBoth;

        return min(ans1, min(ans2, ans3));
    }
};