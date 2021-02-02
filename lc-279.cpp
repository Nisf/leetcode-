class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        for (int i = 1; i <= n; i ++ ) {
            int t = sqrt(i);
            if (t * t == i) {
                coins.push_back(i);
            }
        }
        vector<int> f(n + 1, 1e8);
        f[0] = 0; //别忘了初始化
        for (int i = 0; i < coins.size(); i ++ )
            for (int j = coins[i]; j <= n; j ++ )
                f[j] = min(f[j], f[j - coins[i]] + 1);
        return f[n];
    }
};