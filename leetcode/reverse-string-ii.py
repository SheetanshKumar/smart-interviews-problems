# https://leetcode.com/problems/reverse-string-ii/submissions/
'''541. Reverse String II
Easy

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:

    The string consists of lower English letters only.
    Length of the given string and k will in the range [1, 10000]
'''


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res, temp = "", ""

        is_rev = True
        count = 0
        for i in s:
            count += 1
            if is_rev:
                temp = i + temp
            else:
                temp = temp + i

            if count == k:
                res = res + temp
                temp = ""
                count = 0
                is_rev = not is_rev
        res += temp
        return res
