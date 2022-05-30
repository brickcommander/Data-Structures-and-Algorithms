class Solution:
        
    def numOfWays(self, nums: List[int]) -> int:
        
        mod = int(1e9+7)
        
        def arrange(seq_1, seq_2):
            total_things = seq_1 + seq_2
            things_to_choose = seq_1
            return math.comb(total_things, things_to_choose) % mod
        
        def helper(seq):
            
            if len(seq) <= 1:
                return 1
            
            left = [x for x in seq if x < seq[0]]
            right = [x for x in seq if x > seq[0]]
            
            ways_to_arrange_left = helper(left)
            ways_to_arrange_right = helper(right)
            
            return ways_to_arrange_left * ways_to_arrange_right * arrange(len(left), len(right)) % mod
            
        return (helper(nums) - 1 + mod) % mod