#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
int n,k, a[MAXN], b[MAXN], ans = 1e9;

/*
my guess is that you can swap only within in certain range which may just be the direct left and right 

counter example
n = 3, k = 10

a = 50 51 52
b = 62 63 69

greedy answer = 1 + 1 + 1

better answer

3 -> 1 = 0
1 -> 3 = 1
2 -> 2 = 1
*/
