class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        lst = [0]*max(arr)
        n = len(arr)
        
        for x in arr:
            lst[x-1] += 1
        
        lst.sort()
        lst.reverse()
        t = int(0)
        ans = int(0)
        
        for f in lst:
            t += f
            ans += 1
            if t >= (n+1)//2:
                return ans
        
        