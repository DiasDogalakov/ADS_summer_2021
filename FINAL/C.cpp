#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define ll long long

using namespace std;
 
int main()
{
    ll N;
    cin >> N;
    ll cnt = 0;
    ll cnt2 = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 2; j <= sqrt(i + 1); j++)
            if((i + 1) % j == 0)
                cnt2++;
        if(cnt2 < 2 && cnt2 != 0)
            cnt++;
        cnt2 = 0;
    }
    cout << cnt << endl;
    return 0;
}