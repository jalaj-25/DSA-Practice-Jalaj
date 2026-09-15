# 6-zizag-conversion.py;string;help;leetcode

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        rows = [""] * numRows
        row = 0
        goDown = False
        for c in s:
            rows[row] += c
            if row == 0 or row == numRows - 1:
                goDown = not goDown

            if goDown:
                row += 1
            else:
                row -= 1

        result = ""
        for r in rows:
            result += r

        return result