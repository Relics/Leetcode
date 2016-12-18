MAX_NODE = 50010

isis = [False for i in range(50010)]
ch = [[0 for i in range(26)] for i in range(50010)]
dp = [0 for i in range(50010)]


class Trie(object):
    tot = 0
    def __init__(self):
        tot = 0
        for i in range(26):
            ch[0][i] = -1
            
    def insert(self, s):
        rt = 0
        for c in s:
            id = c - 'a'
            if ch[rt][id] == -1:
                ch[rt][id] = ++ tot
                for i in range(26):
                    ch[tot][i] = -1
            rt = ch[rt][id]
        isis[rt] = True
    
    def search(self, s, i):
        rt = 0
        n = len(s)
        
        if i >= n: 
            return 1
        if dp[i] != -1: 
            return dp[i]
            
        for j in xrange(i, n):
            if i == 0 and j == n - 1:
                dp[i] = 0
                return 0
            id = ord(s[j]) - ord('a')
            if ch[rt][id] == -1:
                dp[i] = 0
                return 0
            rt = ch[rt][id]
            if isis[rt] and search(s, j + 1):
                dp[i] = 1
                return 1
        dp[i] = 0
        return 0


a = Trie()

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        ans = []
        for s in words:
            if len(s) > 0 and self.check(s): 
                ans.append(s)
        return ans
        
    def check(self, s):
        n = len(s)
        for i in xrange(n):
            dp[i] = -1
        if a.search(s, 0) == 1:
            return True
        else:
            return False
    