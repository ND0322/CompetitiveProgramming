#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, ans[MAXN], parents[MAXN];

//from the start keep asking until theres a repeat 
//then we can find out which one the repeat is ig
//dsu to find same color sh

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

void uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    parents[x] = y;
}

int query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    int x; cin >> x;
    return x;
}

int main(){
    cin >> n;

    int last = 1;

    for(int i = 1; i <= n; i++) parents[i] = i;

    for(int i = 2; i <= n; i++){
        if(query(1,i) == last){
            int lo = 1;
            int hi = i-1;
            int ans = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;
                if(query(mid, i) < i-mid){
                    lo = mid+1;
                    ans = mid;
                }
                else{
                    hi = mid-1;
                }
            }
            cout << i << "\n";
            cout << ans << "\n";
            uni(ans, i);
        }   
    }
}