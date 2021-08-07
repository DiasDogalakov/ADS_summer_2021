#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
#include <deque>

using namespace std;

deque<int> deq;
stack<int> stk;

void stt()
{
	int sz = deq.size();
	for(int i = 1; i <= sz/2; i++)
	{
		stk.push(deq.back());
		deq.pop_back();
	}
}
void dtt()
{
	while(stk.size()!=0)
	{
		deq.push_back(stk.top());
		stk.pop();
	}
}
int main()
{
	long long n,v,u;
	char c;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c;
		if(c == '+')
		{
			cin>>v;
			deq.push_back(v);
		}
		else if(c=='*')
		{
			cin>>v;
			stt();
			deq.push_back(v);
			dtt();	
		}
		else
		{
			cout<<deq.front()<<endl;
			deq.pop_front();
		}
	}
	return 0;	
}