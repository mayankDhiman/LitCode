# 1018. Binary Prefix Divisible By 5

class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ret = []
        c = 0;
        for each in A:
            c = c * 2 + (each == 1)
            ret.append(c % 5 == 0)
        return ret
