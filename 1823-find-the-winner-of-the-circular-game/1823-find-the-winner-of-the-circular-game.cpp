class Solution {
public:
    int go(int n, int k) {
        if(n==1) return 0;
        return (go(n-1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return go(n, k) + 1;
    }
};