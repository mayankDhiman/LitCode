class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        num = bin(n)[2:]
        for i in range(1, len(num)):
            if num[i] == num[i - 1]:
                return 0;
        return 1;
