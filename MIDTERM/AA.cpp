#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
 
using namespace std;

stack<char> s;

bool function(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else {
            if (s.empty())  return false;
            char ch = s.top();
            if (ch == '{' && str[i] != '}')
                return false;
            if (ch == '[' && str[i] != ']')
                return false;
            if (ch == '(' && str[i] != ')')
                return false;
            s.pop();
        } 
    }
    if (s.empty())
        return true;
    return false;
}

int main()
{
    string str;
    cin >> str;
    char a = '{';
    char aa = '}';
    char b = '[';
    char bb = ']';
    char c = '(';
    char cc = ')';
    int cnt = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == a) cnt++;
        if(str[i] == aa) cnt++;
        if(str[i] == b) cnt++;
        if(str[i] == bb) cnt++;
        if(str[i] == c) cnt++;
        if(str[i] == cc) cnt++;
    }
    if(cnt == str.size())
    {
        if (function(str))
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}
