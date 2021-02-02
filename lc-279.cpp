// 完全背包
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

// BFS
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> hash;
        q.push(n); hash.insert(n);

        int cnt = 0;
        while (q.size()) {
            cnt ++ ;
            int level = q.size();
            while (level -- ) {
                int t = q.front();
                q.pop();
                for (int i = 1; i * i <= t; i ++ ) {
                    int res = t - i * i;
                    if (res == 0) return cnt;
                    q.push(res);
                    hash.insert(res);
                }
            }
        }
        return cnt;
    }
};