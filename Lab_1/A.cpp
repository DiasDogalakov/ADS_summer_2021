#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
	stack <int> s;
	bool check = true;
	vector<string> ans;
	string str;
	
	while(check)
	{
		cin >> str;
		if(str == "push")
		{
			int n;
			cin >> n;
			s.push(n);
			ans.push_back("ok");
		}
		else if(str == "size")
		{

			int a = s.size();
			stringstream ss;
			ss << a;
			string number = ss.str();

			
			ans.push_back(number);
		}
		else if(str == "clear")
		{
			while(s.size() != 0)
			{
				s.pop();
			}
			ans.push_back("ok");
		}
		else if(str == "back")
		{
			int a = s.top();
			stringstream ss;
			ss << a;
			string number = ss.str();
			ans.push_back(number);
		}
		else if(str == "pop")
		{
			int a = s.top();
			stringstream ss;
			ss << a;
			string number = ss.str();
			ans.push_back(number);
			s.pop();
		}
		else if(str == "exit")
		{
			check = false;
			ans.push_back("bye");
		}
	}
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
    return 0;
}
