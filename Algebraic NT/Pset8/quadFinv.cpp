#include<iostream>
using namespace std;

bool small(int x){
    if(x < 2&& x  > -2){
        return true;
    }
    return false;
}

int R = 500;

int main(){

for(int d = -100; d < -5; d+= 5)
    for(int a = -R; a < R; a++){
        for(int b = -R; b < R; b++){
            for(int A = -R; A < R; A++){
                int B;
                if(a != 0)
                    B = (1 - b*A)/a;
                else   
                    B = 0;
                    if(small(a)&&small(b)&&small(A)&&small(B))
                        continue;
                    if(a*B + b*A == 1 && a*A + d*b*B == 0
                    ){
                        cout << d << " works\n";
                        printf("(a, b, A, B) = (%d,%d,%d,%d)\n\n",
                        a, b, A, B
                        );
                        break;
                    }
                }
            }
        }
return 0;
}