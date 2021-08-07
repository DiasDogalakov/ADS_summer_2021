#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1e9 + 7;

long long get_hash(string & s){
    long long p = 11;
    vector<long long> p_pow;
    p_pow.push_back(1);
    long long n = s.size();
    for(int i = 1; i <= n; ++i){
        p_pow.push_back((p_pow[i-1] * p) % MOD);
    }

    long long hash = 0;
    for(int i = 0; i < n; ++i){
        hash = (hash + (s[i] - '0' + 1) * p_pow[i] % MOD) % MOD;
    }

    return hash;
}

int main()
{
    int n; cin >> n;
    n = 2 * n;
    vector<pair<string, int> > a(n);
    set<long long> st;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i].first; a[i].second = i;
        if (a[i].first.length() < 18)
            st.insert(atoi(a[i].first.c_str()));
    }
    sort(a.begin(), a.end());
    vector<pair<int, string> > res;
    for(int i = 0; i < n; ++i)
    {
        long long hash = get_hash(a[i].first);
        if(st.find(hash) != st.end())
        {
            st.erase(hash);
            res.push_back({a[i].second, "Hash of string \"" + a[i].first + "\" is " + to_string(hash) + "\n"});
        } 
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i].second;
    }
    return 0;
}