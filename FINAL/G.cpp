#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

vector<int> pf(string s){
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for(int i = 1; i < n; ++i){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if(s[i] == s[j]){
            j = j + 1;
        }
        p[i] = j;
    }
    return p;
}

int main()
{
    string s, t; cin >> s >> t;
    string tmp = "";
    while (tmp.length() < t.length()) {
        tmp += s;
    } 
    string to_compare = tmp + "@" + t;
    vector<int> p = pf(to_compare);
    int start = tmp.length();
    int mx = 0;
    for (int i = start; i < to_compare.length(); ++i) {
        mx = max(mx, p[i] / (int) s.length());
    }
    cout << mx << endl;
    return 0;
}