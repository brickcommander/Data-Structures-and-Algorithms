class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (dividend == -2147483648 and divisor == -1): return 2147483647
        sign = bool((dividend > 0) == (divisor > 0))
        dividend = abs(dividend)
        divisor = abs(divisor)
        ans = int(0)
        
        while dividend >= divisor:
            a = int(1)
            d = divisor
            while (divisor << 1) <= dividend:
                divisor <<= 1
                a <<= 1
            dividend -= divisor
            divisor = d
            ans += a
        
        return ans if sign else -ans