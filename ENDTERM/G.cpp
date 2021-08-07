#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

#define INF 10000000

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
            {
                arr[i][j] = INF;
            }
        }
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    if(arr[s][t] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << arr[s][t] << endl;
    }
    return 0;
}