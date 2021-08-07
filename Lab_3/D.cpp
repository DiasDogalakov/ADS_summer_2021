#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int arr[n][m];
    int maxi[750], mini[750];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int cur;
            cin >> cur;
            if(i == 0)
                maxi[j] = cur;
            else if(maxi[j] < cur)
                maxi[j] = cur;
            if(j == 0)
                mini[j] = cur;
            else if(mini[i] > cur)
                mini[i] = cur;
        }
    }
     for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mini[i] == maxi[j])
                cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
