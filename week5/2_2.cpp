// Однонаправленный граф который по входной матрице и двум введённым вершинам показывает есть ли между ними путь
// Релизация Матрицей Смежности
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

    int arr[n][n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }
    /*
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    int a, b;
    cin >> a >> b;

     if(arr[a][b] == 1){
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