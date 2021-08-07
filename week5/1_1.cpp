// Однонаправленный граф который по входной матрице показывает какие графы соеденины между собой
// Релизация Рёбрами
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

int main(){

    int n, x;
    cin >> n;
    vector<int> e[n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> x;
            if(x == 1){
                e[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        cout << i + 1<< ": ";
        for(int j = 0; j < e[i].size(); ++j){
            cout << e[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
/*

input:
4
0 1 0 1
0 0 1 0 
0 0 1 1
1 0 0 0

output:
1: 2 4
2: 3
3: 3 4
4: 1

*/
