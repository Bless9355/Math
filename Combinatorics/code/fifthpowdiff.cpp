#include<iostream>
using namespace std;

int main(){
    int D[100][100] = {0};
    for(int i = 0; i < 11; i++)
        D[0][i] = i*i*i*i*i;

    for(int row = 1; row < 11; row++){
        for(int i = 0; i < 11; i++){
            D[row][i] = D[row - 1][i+1] - D[row - 1][i];
        }
    }

    for(int r = 0; r < 11; r++){
        for(int c = 0; c <= 10 - r; c++)
            cout << D[r][c] << " ";

        cout << "\n";
    }
    return 0;
}