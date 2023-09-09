class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        mins=float('inf')
        dicts={}
        for i in range(len(cards)):
            if cards[i] not in dicts:
                dicts[cards[i]]=-1
            else:
                # if dicts[cards[i]]==-1:
                dicts[cards[i]]=i
        # print(dicts)
        dicts2={}
        for i in range(len(cards)):
            if dicts[cards[i]]==-1:
                continue
            else:
                m=abs(dicts[cards[i]]-i)
                if m!=0:
                    mins=min(mins,m+1)
                if cards[i] in dicts2:
                    mins=min(mins,abs(dicts2[cards[i]]-i)+1)
                # print(p)
                dicts2[cards[i]]=i
                
        if mins==float('inf'):
            return -1
        return mins
