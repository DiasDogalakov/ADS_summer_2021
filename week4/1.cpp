// Нахождение хэша для строки
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define ll long long

using namespace std;
 
vector<ll> p_pow;

ll get_hash(string s){
    ll p = 31;
    p_pow.push_back(1);
    ll n = s.size();
    for(int i = 1; i <= n; i++)
    {
        p_pow.push_back(p_pow[i-1] * p);
    }

    ll hash = 0;
    for(int i = 0; i < n; i++)
    {
        hash += (s[i] - 'a' + 1) * p_pow[i];
    }
    
    return hash;
}


int main(){

    string s;
    cin >> s;
    cout << get_hash(s) << endl;
    return 0;
}
