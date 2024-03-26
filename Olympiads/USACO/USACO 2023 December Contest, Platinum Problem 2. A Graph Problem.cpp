#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//add based on mst
//using dsu to track ans for each component

const int MAXN = 4e5+5;
const int MOD = 1e9+7;

//each edge we update the answer along the component to the root of the component
//we store size and answer for each node
//add (1,i) to every node along each component
//to combine add 10^current size which is how many weve added so far times a + b

typedef pair<int,int> pii;

int n, m, powt[MAXN], parents[MAXN];

pii dp[MAXN];



pii comb(pii a, pii b){
    return {a.first + b.first, ((powt[b.first] * a.second) % MOD + b.second) % MOD};
}


int find(int x){
    if(x == parents[x]) return x;
    int tmp = find(parents[x]);

    if(x == tmp) return tmp;

    //update the node in component
    dp[x] = comb(dp[x],dp[parents[x]]);
    parents[x] = tmp;
    return tmp;   
}

pii calc(int x){
    return (x == find(x) ? dp[x] : comb(dp[x],calc(parents[x])));
}

int main(){
    cin >> n >> m;

    powt[0] = 1;
    for(int i = 1; i <= n; i++) powt[i] = (powt[i-1] * 10) % MOD;
    for(int i = 1; i <= n; i++) parents[i] = i;

    int cnt= n;
    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;


        int fx = find(x);
        int fy = find(y);

        if(fx == fy) continue;

        //cout << fx << " " << y << "\n";

        //cout << parents[fx] << "\n";

        


        

        dp[fx] = comb(dp[fx], comb({1,i+1}, calc(x)));
        dp[fy] = comb(dp[fy], comb({1,i+1}, calc(y)));
        

        

        //add dummy children

        parents[fx] = parents[fy] = ++cnt;
        
    }

    for(int i = 1; i <= n ; i++){
        cout << calc(i).second << "\n";
    }   
}