#include <bits/stdc++.h>
#include <iostream>
#include <set>

//store solutions based on the number of prizes grater on the left and righ
//dac

using namespace std;

typedef pair<int,pair<int,int>> tu;

set<tu> cnt[500];

/*

vector<int> ask(int x){

    cout << x << "\n";
    int a,b; cin >> a >> b;

    return {a,b};
}

*/


int dac(int lo, int hi){
    if(lo > hi) return -1;

    int mid = (lo+hi)/2;

    vector<int> res = ask(mid);

    int tot = res[0] + res[1];

    if(!tot) return mid;

    cnt[tot].insert({mid,{res[0],res[1]}});

    auto it = cnt[tot].lower_bound({mid,{res[0],res[1]}});

    if(it == cnt[tot].begin() || res[0] - (*prev(it)).second.first){
        int x = dac(lo,mid-1);

        if(x != -1) return x;
    }

    if(next(it) == cnt[tot].end() || (*next(it)).second.first - res[0]){
        int x = dac(mid+1,hi);

        if(x != -1) return x;
    }

    return -1;
}


int find_best(int n){
   return dac(0,n-1);
}