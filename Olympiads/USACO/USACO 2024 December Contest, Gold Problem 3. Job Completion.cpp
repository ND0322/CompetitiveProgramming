#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, a[MAXN], b[MAXN]; 

pair<int,int> c[MAXN];
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        c[i] = {a[i] + b[i], i};
    }

    sort(c+1, c+n+1);


    for(int i = 1; i <= n; i+)
}


/*
By exchange asrgument, 

if we have a solution with some i, j such that s[i] + t[i] > s[j] + t[j]

lets exchange 


We will have that s[i] must be < sum of t[j] for items already in our set 


We should have smaller t[i] earlier AND smaller s[i] earlier 
*/

