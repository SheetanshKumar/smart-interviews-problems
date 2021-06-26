
#  https://leetcode.com/problems/verifying-an-alien-dictionary/

# 953. Verifying an Alien Dictionary
# Easy

# 1848

# 739

# Add to List

# Share
# In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

# Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

# Example 1:

# Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
# Output: true
# Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
# Example 2:

# Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
# Output: false
# Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
# Example 3:

# Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
# Output: false
# Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

# Constraints:

# 1 <= words.length <= 100
# 1 <= words[i].length <= 20
# order.length == 26
# All characters in words[i] and order are English lowercase letters.

from functools import cmp_to_key
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        chord = dict()
        for i in range(len(order)):
            chord[order[i]] = i
        
        def compare(b, a):
            
            for i in range(min(len(a), len(b))):
                if a[i] in chord and b[i] in chord:
                    if chord[a[i]] < chord[b[i]]:
                        return 1
                    elif chord[a[i]] == chord[b[i]]:
                        continue
                    else:
                        return -1
                else:
                    return -1
            return 1 if len(a) < len(b) else -1

        return sorted(words, key=cmp_to_key(compare)) == words
        
        