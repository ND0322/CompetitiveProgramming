#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 5e6+5;

int n, b[MAXN];

long long a[MAXN];

/*
intuition is to look at the leftmost element

From here we can determine the first index that is greater
and keep on going until final is reached


*/

void solve(int l, int r, int d){

    if(l > r) return;
    vector<int> inds;
    //a[l] = (r - l + 1)
    int cur = l;

    while(cur <= r){
        inds.push_back(cur);

        cur = a[cur] / (cur - l + 1) + cur;
    }
    
    reverse(inds.begin(), inds.end());

    for(int i = 1; i <= inds.size(); i++){
        int j = inds[i-1];

        cout << j << " ";

        b[j] = i;
    }

    cout << "\n";
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    solve(1,n, 1);

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    

   
}