class Solution {
public:
    // 3^19 = 1,162,261,467;
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
};