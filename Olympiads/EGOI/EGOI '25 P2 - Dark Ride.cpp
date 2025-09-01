#include <bits/stdc++.h>

using namespace std;
/*
we know the number of i such that

i -> i+1
is 0 to 1 
or 1 to 0

what happens when we query from 1 to n/2

querying mask and /mask gives the same result


if ans is the same for some query and a subset of the query we know that they are touching


2 log2(n) queries total 



*/

int main(){
    int n = 30000;

    cout << log2(n) << "\n";

}