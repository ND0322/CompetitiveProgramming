#include <bits/stdc++.h>
#include <iostream>

const int MAXN = 1e5+5;



//sweepline
//two types of events
//one at l+t which introduces bad and one at r that is the expiry
//we will only use the blocker at an l+t where k is reached
//can be done with a difference array keeping track of left and right bounds 


/*
sweepline
do an initial sweep to find points where k is violated
add these as events with expiry at i + x
*/



int main(){

}