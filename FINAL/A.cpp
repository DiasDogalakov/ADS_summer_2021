#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<int> v;

int main()
{
    int N, K;
    cin >> N >> K;
    for(int T = 0; T < N; T++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int maxi1 = max(x1, y1);
        int maxi2 = max(x2, y2);
        int maxi3 = max(maxi1, maxi2);
        v.push_back(maxi3);
    }
    sort(v.begin(), v.end());
    cout << v[K - 1] << endl;
    return 0;
}
