﻿#include <iostream>

using namespace std;

const int N = 30010;

int f[N];

int n, m;

int main()
{
    cin >> m >> n;
    
    for (int i = 0; i < n; i ++ )
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j -- )
            f[j] = max(f[j], f[j - v] + w * v);
    }
    
    cout << f[m] << endl;
    return 0;
}