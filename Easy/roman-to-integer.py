class Solution:
    def romanToInt(self, s: str) -> int:
        romanToInt = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        integer = 0
        for i in range(len(s) - 1):            
            if romanToInt[s[i]] < romanToInt[s[i + 1]]:
                integer -= romanToInt[s[i]]
            else:
                integer += romanToInt[s[i]]
        integer += romanToInt[s[-1]]        
        return integer
        
