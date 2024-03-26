#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;
const int MOD = 1e9;

int n,m, k, parents[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}


void uni(int x, int y){
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < (n+m)<<1; i++) parents[i] = i;

    int ans = -1;

    for(int i = 0; i < k; i++){
        int x,y,c; cin >> x >> y >> c;

       

        if(c ^ ((x%2) & (y%2))){
            uni(x,y+n);
            uni(x+n+m, y + (n<<1) + m);
        }
        else{
            uni(x+n+m,y+n);
            uni(x, y + (n<<1) + m);
        }
        
    }

    for(int i = 0; i < n+m; i++){
        if(find(i) == find(i+n+m)){
            cout << "0\n";
            return 0;
        }
        else if(find(i) == i) ans++;
        
    }

   

    int temp = 1;

    for(int i = 0; i < ans; i++){
        temp<<=1;
        temp %= MOD;
    }

    cout << temp << "\n";


}