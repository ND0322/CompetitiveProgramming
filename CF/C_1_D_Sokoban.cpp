#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;



//try moving left and right
//all negatives will be seperated from positives so you can split and find the answer separately 
//a sweep from left to right should work with some query
//if we have prefix of x boxes then we will collect boxes between i and i+x as well and keep on doing this until we dont intersect new boxes
//then we can bsearch for next i again 
//for updating answer we just query the number of b[i] between i and i+x
//suffix some sh 


