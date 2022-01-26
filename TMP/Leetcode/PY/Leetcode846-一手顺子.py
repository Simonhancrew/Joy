class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        st,n = defaultdict(int),len(hand)
        if n % groupSize != 0: return False
        hand.sort()
        for hd in hand:
            st[hd] += 1
        for hd in hand:
            if st[hd] == 0: continue
            for t in range(hd,hd + groupSize):
                if st[t] == 0: return False
                st[t] -= 1
        return True
         
        