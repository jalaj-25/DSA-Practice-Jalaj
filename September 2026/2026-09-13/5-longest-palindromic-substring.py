# 5-longest-palindromic-substring.py;2p;help;leetcode

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range(len(s)):
            low = i
            high = i
            while low >= 0 and high < len(s) and s[low] == s[high]:
                if high - low + 1 > len(ans):
                    ans = s[low:high + 1]

                low -= 1
                high += 1

            low = i - 1
            high = i
            while low >= 0 and high < len(s) and s[low] == s[high]:
                if high - low + 1 > len(ans):
                    ans = s[low:high + 1]

                low -= 1
                high += 1

        return ans