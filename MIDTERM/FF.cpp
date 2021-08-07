#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        pq.push(-a[i]); // -1 -2 -3 -9 -10 -12
    }
    int ans = 0;
    while(true)
    {
        if(pq.size() == 1)
        {
            if(-pq.top() < m)
            {
                ans = -1;
            }
            break;
        }
        int mn = -pq.top();
        if(mn >= m) break;
        pq.pop();
        int mn2 = -pq.top();
        pq.pop();
        int neww = mn + mn2* 2;
        pq.push(-)

        ans++;
    }
    
    cout << ans << endl;
    return 0;
}