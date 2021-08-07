#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
    string s = "abcd";
    for(int i = 0; i < s.size(); i++)
    {
        cout << int(s[i]) << endl;
    }
    return 0;
}