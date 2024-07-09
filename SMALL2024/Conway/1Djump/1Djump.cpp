#include<stdio.h>
#include<std>
using namespace std;

//we also have a board mtp m. 
//characterize each jump by 
//a0, a1, a2, ... an before the boundary 
//ai denotes the jump to the ith piece from the bdry
//b1, b2, ... bl for jumps after the bdry

//we know that the following recurrence must be satisfied:
//m + ai - a(i + 1) - a(i + 2) >= 0 for i >= 2
//a0 - b1 - b2 >= 0 
//m + a1 - a0 - b1 >= 0
//b1 - b2 - b3 >= 0
//and so on

//finally, we know that b1 = 1. 
//given m, l, is there a possible solution?





//we conduct backtracking by m^n 

void backtrack(int N, int prog, vector<int>){
    
}

int main(){
    return 0;
}