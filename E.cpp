#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; T++)
    {
        int n, k;
        cin >> n >> k;
        int a[k], b[k];
        for(int i = 0; i < k; i++)
            cin >> a[i];
        for(int i = 0; i < k; i++)
            cin >> b[i];
        int ans[n];
        multiset<int> st;
        map<int, int> mp;
        map<int, int> mp2;
        for(int i = 0; i < n; i++)
        {
            ans[i] = 2e9;
        }
        for(int i = 0; i < k; i++)
        {
            st.insert(a[i] + b[i]);
            mp[a[i]] = a[i] + b[i];
        }
        for(int i = 1; i <= n; i++)
        {
            int val = 2e9;
            if(!st.empty())
            {
                val = min(val, *st.begin());
            }
            if(mp[i] != 0)
            {
                if(st.find(mp[a[i]]) != st.end())
                    st.erase(st.find(mp[i]));
            }
            ans[i - 1] = min(ans[i - 1], val - i);
        }
        // razdelenye
        for(int i = 0; i < k; i++)
        {
            st.insert(-(a[i]) + b[i] + n);
            mp2[a[i]] = -(a[i]) + b[i] + n;
        }
        for(int i = n; i >= 1; i--)
        {
            int val = 2e9;
            if(!st.empty())
            {
                val = min(val, *st.begin());
            }
            if(mp2[i] != 0)
            {
                st.erase(st.find(mp2[i]));
            }
            ans[i - 1] = min(ans[i - 1], val - i + n);
        }
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " " ;
        }
        cout << endl;
    }                  
    return 0;
}