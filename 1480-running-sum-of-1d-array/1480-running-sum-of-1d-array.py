class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        lt = list()
        for x in nums:
            if len(lt):
                lt.append(lt[-1]+x)
            else:
                lt.append(x)
        return lt