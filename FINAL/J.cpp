#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

int d1, d2;

void appercase(string s1, string s2)
{
    for(int i = 0; i < s1.size(); i++)
        if(int(s1[i]) >= 65 && int(s1[i]) <= 90)
            d1 = i;
    for(int i = 0; i < s2.size(); i++)
        if(int(s2[i]) >= 65 && int(s2[i]) <= 90)
            d2 = i;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<char> v1;
    vector<char> v2;
    appercase(s1, s2);
    for(int i = d1; i < s1.size(); i++)
        v1.push_back(s1[i]);
    for(int i = d2; i < s2.size(); i++)
        v2.push_back(s2[i]);
    if(v1 == v2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}