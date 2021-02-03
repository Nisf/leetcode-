#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 30, M = 90;

int f[N][M];

int m, n, k;

int main()
{
    memset(f, 0x3f, sizeof f);
    
    f[0][0] = 0;
    
    cin >> m >> n >> k;
    while (k -- )
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        
        for (int i = m; i >= 0; i -- )
            for (int j = n; j >= 0; j -- )
                f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);
    }
    
    cout << f[m][n] << endl;
    
    return 0;
}