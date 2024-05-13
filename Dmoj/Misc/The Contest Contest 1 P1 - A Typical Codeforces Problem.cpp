#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n;

bool has[MAXN];
int main(){
    cin >> n;

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        has[i] = (c == 'Y');
        cnt += has[i];
    }

    int i = 1;
    while(i <= cnt){
        cnt += !has[i];
        i++;
    }


    cout << (cnt > n/2 ? "YES\n" : "NO\n");


    
}


/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/