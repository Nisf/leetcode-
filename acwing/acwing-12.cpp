#include <iostream>
using namespace std;

const int N = 1010;

int f[N][N];
int v[N], w[N];

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    for (int i = n; i; i -- )
        for (int j = 0; j <= m; j ++ )
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    
    // f[1][m] 是最大值
    int j = m;
    for (int i = 1; i <= n; i ++ )
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
        {
            cout << i << " ";
            j -= v[i];
        }
    return 0;        
}
