#include <iostream>
using namespace std;

const int N = 1010;

int f[N];
int v[4] = {10, 20, 50, 100};

int main()
{
    int m;
    cin >> m;
    f[0] = 1; //初始化
    
    for (int i = 0; i < 4; i ++ )
        for (int j = v[i]; j <= m; j ++ )
            f[j] += f[j - v[i]];
    cout << f[m] << endl;
    return 0;
}