#include <bits/stdc++.h>
#include <iostream>

const int MAXN = 2e5+5;

using namespace std;


/*
each i is paired with some range possible rs

i can be paired with

i + k - 1, i + k - 3, i + k - 5


i + k - 2j - 1

where j is at most i and at least somethinn to do with the end
sliding window


need to move from projected left to last left and from last r to new r
*/

int n, k, a[MAXN], cnt[MAXN];

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 1 + k - 3;
    int r = 1 + k - 3;


    int tot = 1;
    cnt[a[l]]++;

    int ans = tot - cnt[a[1]];
    


    for(int i = 2; i <= n; i+=2){
        

        
    }

   


}