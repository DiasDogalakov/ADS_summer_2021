#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

const int N = 2e5;
vector<vector<int> > g(N);
vector<bool> used(N);

void dfs(int v) {
    used[v] = true;
    for(int to = 0; to < g[v].size(); ++to)
    {
        if(!used[g[v][to]])
        {
            dfs(g[v][to]);
        }
    }
}

int main()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!used[i])
        {
            cnt++;
            dfs(i);
        }
    }
    if(cnt == k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}