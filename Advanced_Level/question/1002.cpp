#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAXN 1111
float p[MAXN]{0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k;
    cin>>k;
    int n;
    float a;
    while (k--)
    {

        cin>>n>>a;
        p[n] += a;
    }
    cin>>k;
    while (k--)
    {
        cin>>n>>a;
        p[n] += a;
    }
    int cnt = 0;
    for (int i = 0; i < MAXN; i++)
    {
        if (p[i] != 0)
            cnt++;
    }
    cout << cnt;
    for (int i = MAXN-1; i >=0; i--)
    {
        if (p[i] != 0)
        {
            printf(" %d %.1f", i, p[i]);
            cnt--;
        }
        if (cnt == 0)
            break;
    }
}