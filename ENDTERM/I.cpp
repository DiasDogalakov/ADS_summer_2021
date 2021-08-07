#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int calc(string s) {
    int n = s.size();
    int p[n + 1];
    p[0] = 0;
    int mx = 0;
    for(int i = 1; i < n; ++i)
    {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j])
        {
            j = p[j - 1];
        }
        if(s[i] == s[j])
        {
            j = j + 1;
        }
        p[i] = j;
        mx = max(mx, p[i]);
    }
    return mx;
}

int main()
{
    string s, t; cin >> s >> t;
    cout << calc(s + t) << endl;
    return 0;
}