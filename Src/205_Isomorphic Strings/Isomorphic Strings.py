class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        sDict=dict()
        tDict=dict()
        for i in range(len(s)):
            if(sDict.get(s[i])!=None and t[i]!=sDict.get(s[i])):
                return False
            if(tDict.get(t[i])!=None and s[i]!=tDict.get(t[i])):
                return False
            sDict[s[i]]=t[i]
            tDict[t[i]]=s[i]
        return True