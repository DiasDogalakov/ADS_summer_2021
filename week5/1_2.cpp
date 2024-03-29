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
            if( x == 1){
                e[i].push_back(j);
            }
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        cout << i + 1<< ": ";
        for(int j = 0; j < e[i].size(); ++j){
            cout << e[i][j] + 1 << " ";
        }
        cout << endl;
    }*/

    int a, b;
    cin >> a >> b;

    bool found = false;

    for(int i = 0; i < e[a-1].size(); ++i){
        if(e[a-1][i] == b-1){   
            found = true;
            break;    
        }
    }

    if(found){
        cout << "YES";
    }
    else{
        cout << "NO";       
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
2 3
(2,3 - города между которыми нужно проверить есть ли путь)

output:
YES

*/