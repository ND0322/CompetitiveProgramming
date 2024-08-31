#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int st[MAXN][MAXN];

/*
keep a seg tree for each column and row
basically rip that one coci question but add lazy set  
*/