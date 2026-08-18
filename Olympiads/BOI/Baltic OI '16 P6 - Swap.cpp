#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], b[MAXN];


//we can permute groups 3 in any way except for adjacent swaps
//the gaps between each group increases by 1 every time
//If min element is at position 1 or 2, then 3 is set where it is -> no choice can be made
//if min element is at position 3 we can swap 1 and 2 
//each position has at most 2 queries 

/*
xxx
 x xx
  x  xx
   x   xx

sqrt n 

*/


int main(){

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; (i<<1) <= n; i++){   
        int lc = (1<<i);
        int rc = 1<<i|1;
        
    }



}