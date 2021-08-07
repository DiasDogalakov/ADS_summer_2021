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
    long long p = 31;
    vector<long long> p_pow;
    p_pow.push_back(1);
    long long n = s.size();
    for(int i = 1; i <= n; ++i){
        p_pow.push_back((p_pow[i-1] * p) % MOD);
    }

    long long hash = 0;
    for(int i = 0; i < n; ++i){
        hash = (hash + (s[i] - 'a' + 1) * p_pow[i] % MOD) % MOD;
    }

    return hash;
}

set<long long> get_hashes(string & s) {
    int n = s.length();
    set<long long> st;
    for (int i = 0; i < n; ++i) {
        string temp = "";
        for (int j = i; j < n; ++j) {
            temp += s[j];
            long long hash = get_hash(temp);
            st.insert(hash);
        }
    }
    return st;
}

int main()
{
    string s, t; cin >> s >> t;
    set<long long> hashes1 = get_hashes(s), hashes2 = get_hashes(t);
    int cnt = 0;
    for (auto it : hashes1) {
        if (hashes2.find(it) != hashes2.end()) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}