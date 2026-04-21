#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;


int n, q, a[MAXN], k;

struct Node{
    int cnt0 = 0;
    int cnt1 = 0;

    bool lz1 = 0;
    int lzset = 0;
} st[MAXN<<2];

void pushup(int node, int l, int r){
    int mid = (l+r)>>1;

    
}

/*
something about number greater and smaller in range 

replace smaller elements with 0 and larger with 1

if m is contained in range we update it position to l + 2 * min(#0, #1) + 1
When we sort an array 
*/