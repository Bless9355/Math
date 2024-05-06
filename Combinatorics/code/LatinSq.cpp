#include<iostream>
#include<vector>
using namespace std;

void printSq(int ** square, int sz){
    //row, col
    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= sz; j++){
            cout << square[i][j] << " ";
        }
        cout << "\n";
    }
}

void init2Darr(int **buf){
    buf = new int*[100];
    for(int i = 0; i < 100; i++) 
        buf[i] = new int[100];
    return;
}

void L(int ** buf, int sz, int jump){
    init2Darr(buf);
    cout << buf[5][5];
    //row, col
    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= sz; j++){
    cout << "initialized\n";
            buf[i][j] = (j + (i - 1)*(jump))%sz;
            if(buf[i][j] == 0) 
                buf[i][j] = sz;
        }
        //cout << "\n";
    }
}


void magSq(int ** buf, int ** L, int ** M, int sz){
    init2Darr(buf);
    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= sz; j++){
            buf[i][j] = (L[i][j] - 1) * sz + (M[i][j] - 1);
        }
    }
    return;
}


int main(){
    int** L1;
    int **L2;
    int **L3;
    int **L4;

    L(L1, 5, 1);
    L(L2, 5, 2);
    L(L3, 5, 3);
    L(L4, 5, 4);


    cout << "squares constructed\n";

    int ** mag;
    magSq(mag, L1, L2, 5);
    printSq(mag, 5);
    

    return 0;
}