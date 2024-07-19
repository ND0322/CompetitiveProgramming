#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
for every character 
if they dont match:
we can add 1 to a
add 1 to b
or dont add any
if they match
we can add 1 to both
or dont add any
check that both can equal t

greedy
*/

int main(){
    int n, k; cin >> n >> k;

    string s,t; cin >> s >> t;

    string res;
    int cnt = 0;

    

    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) cnt++;
    }


    int a = max(n-k-cnt, 0);


    




}