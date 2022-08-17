class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
                        
        partition_len = len(nums) // k        
                
        @functools.lru_cache(maxsize=None)
        def recurse(nums):            
            if not nums: return 0      
            
            result = float('inf')
            
            for combo in itertools.combinations(nums, partition_len):                
                
                if len(set(combo)) < partition_len: continue
                                                 
                updated_nums = list(nums) 
                for i in combo:
                    updated_nums.remove(i)
                                    
                result = min(
                    result,
                    max(combo) - min(combo) + recurse(tuple(updated_nums))
                )
                
            return result
        
        result = recurse(tuple(nums))
        
        return result if result != float('inf') else -1

# class Solution:
#     def minimumIncompatibility(self, nums: List[int], k: int) -> int:
#         n = len(nums)
#         subsets_size = n // k
        
#         @lru_cache(None)
#         def dfs(mask):
#             if(mask == (1<<n)-1):
#                 return 0
            
#             ans = float("inf")
#             remaining = [i for i in range(n) if mask & (1<<i) == 0]
#             comb = list(combinations(remaining, subsets_size))
            
#             for c in comb:
#                 cur_nums = set([nums[i] for i in c])
#                 if(len(cur_nums) < subsets_size):
#                     continue
#                 new_mask = mask
#                 for i in c:
#                     new_mask |= (1<<i)
#                 ans = min(ans, dfs(new_mask) + max(cur_nums) - min(cur_nums))
                
#             return ans
        
#         ans = dfs(0)
        
#         return ans if ans < float("inf") else -1