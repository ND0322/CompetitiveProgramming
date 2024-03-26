#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <bitset>

using namespace std;


//keep a bitset as the answer for each number
//max is is only 25000
//process largest to smallest


const int MAXN = 505;

int n, a[MAXN];

bitset<25000> dp;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a,a+n);
    reverse(a,a+n);

    set<int> s;

    dp[0] = 1;

    for(int i = 1; i < n; i++){
        bitset<25000> tmp = dp;

        for(int j : s) dp |= tmp << (j-a[i]);
        s.insert(a[i]);
    }


    for(int i = 0; i <= 25000; i++){
        if(dp[i]) cout << i << " ";
    }

   
}

