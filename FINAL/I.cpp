#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

int pf(string s){
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
    return p.back();
}

int main()
{
    string s, t; cin >> s >> t;
    int to_erase = pf(t + "@" + s);
    cout << s << t.substr(to_erase, t.length()) << endl;
    return 0;
}