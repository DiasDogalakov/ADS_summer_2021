#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<int> v;

void check(string s, string t, int i, int j)
{
    int cnt = 0;
    int cur1 = i;
    int cur2 = j;
    for(int i = cur1; i < s.size(); i++)
    {
        for(int j = cur2; j < t.size(); j++)
        {
            if(s[cur1] == t[cur2])
            {
                cnt++;
                cur1++;
                cur2++;
            }
        }
    }
    v.push_back(cnt);
}

int func(string s, string t)
{
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j])
                check(s, t, i, j);
        }
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    func(s, t);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}