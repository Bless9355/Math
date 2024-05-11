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

void init2Darr(int **&buf){
    buf = new int*[100];
    for(int i = 0; i < 100; i++) {
        buf[i] = new int[100];
    }

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++) {
            buf[i][j] = 0;
        }
    return;
}

void L(int ** &buf, int sz, int jump){
    init2Darr(buf);
    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= sz; j++){
            buf[i][j] = (j + (i - 1)*(jump))%sz;
            if(buf[i][j] == 0) 
                buf[i][j] = sz;
        }
        //cout << "\n";
    }
}


void magSq(int ** &buf, int ** &L, int ** &M, int sz){
    init2Darr(buf);
    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= sz; j++){
            buf[i][j] = (L[i][j] - 1) * sz + (M[i][j] - 1) + 
        }
    }
    return;
}


bool checksum(int ** sq, int sz){
    int SUM = 0;
    for(int i = 1; i <= sz; i++) 
        SUM += sq[i][1];

    //for rows
    for(int r = 1; r <= sz; r++){
        int rowSum = 0;
        for(int i = 1; i <= sz; i++)
            rowSum += sq[r][i];
        
        if(rowSum != SUM) 
            return false;
    }
    //for cols
    for(int c = 1; c <= sz; c++){
        int colSum = 0;
        for(int i = 1; i <= sz; i++)
            colSum += sq[i][c];
        
        if(colSum != SUM) 
            return false;
    }
    return true;
}

bool diagsum(int ** sq, int sz){
    int SUM = 0;
    for(int i = 1; i <= sz; i++) 
        SUM += sq[i][1];
    int d1 = 0, d2 = 0;
    for(int i = 1; i <= sz; i++){
        d1 += sq[i][i];
        d2 += sq[i][sz + 1- i];
    }
    if(d1 != SUM) return false;
    if(d2 != SUM) return false;
    return true;
}

int main(){
    //create latin squares
    int** Larr[10];
    for(int i = 1; i < 5; i ++){
        L(Larr[i], 5, i);
        cout << "\n";
        //printSq(Larr[i], 5);
    }

    //create Magic squares
    for(int fst = 1; fst < 5; fst++){
        for(int sec = fst + 1; sec < 5; sec++){
            int ** mag;
            magSq(mag, Larr[fst], Larr[sec], 5);
            cout << "product of " << fst << " " << sec <<"\n";
            printSq(mag, 5);
            //for each square, show the results
            if(checksum(mag, 5)){
                cout << "column sums are invariant\n";
            }
            else{
                cout << "test failed...\n";
            }
            if(diagsum(mag, 5)){
                cout << "diagonals are also invariant\n";
            }
        }
    }


    return 0;
}