class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        if len(colors) <= 2:
            return False
        
        cnta, cntb = 0, 0

        for i in range(1, len(colors)-1):
            if colors[i-1] == colors[i] == colors[i+1]:
                if colors[i] == 'A':
                    cnta += 1
                else:
                    cntb += 1
        
        return cnta > cntb
