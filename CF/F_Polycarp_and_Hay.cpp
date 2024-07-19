#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

/*
sort by ascending a[i][j]

start from large k and slowly add back more and more stuff

very very similar to the sharks question
*/

#define int long long

const int MAXN = 1005;

int n, m, a[MAXN][MAXN], parents[MAXN*MAXN], sz[MAXN*MAXN];

bool vis[MAXN*MAXN];

long long k;

pair<int,int> s[MAXN*MAXN];

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

    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    parents[y] = x;
    sz[x] += sz[y];
}

int32_t main(){
    cin >> n >> m >> k;

    set<int> b;

    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            parents[(i-1)*m + j] = (i-1)*m + j;
            s[(i-1)*m+j] = {a[i][j],(i-1)*m+j};
            sz[(i-1)*m+j] = 1;
            b.insert(a[i][j]);
        }
    }

    if(k > 1e14){
        cout << "NO\n";
        return 0;
    }

    vector<int> div;

    for(int i = 1; i <= sqrt(k); i++){
        if(k % i == 0){
            div.push_back(i);
            div.push_back(k/i);
        }
    }
    sort(div.rbegin(), div.rend());
    sort(s+1,s+n*m+1);
    reverse(s+1,s+n*m+1);

    //for(int i = 1; i <= n*m; i++) cout << s[i].first << " " << s[i].second << '\n';

    int p = 1;
    int cnt = 0;
    for(int i : div){

        
        
        while(p <= n*m && s[p].first >= i){
            cnt++;
            vis[s[p].second] = 1;

            if(s[p].second - m >= 1 && vis[s[p].second - m]) uni(s[p].second, s[p].second - m);
            if(s[p].second + m <= n*m && vis[s[p].second + m]) uni(s[p].second, s[p].second + m);
            if(s[p].second % m != 1 && vis[s[p].second-1]) uni(s[p].second, s[p].second - 1);
            if(s[p].second % m != 0 && vis[s[p].second+1]) uni(s[p].second, s[p].second + 1);

            p++;
        }

        
       


        if(b.find(i) != b.end() && cnt * i == k && p-1 && sz[find(s[p-1].second)] == cnt){
            cout << "YES\n";

            for(int l = 1; l <= n; l++){
                for(int j = 1; j <= m; j++) cout << (vis[(l-1)*m + j] ? i : 0) << " ";
                cout << "\n";
            }

            return 0;
        }
    }

    cout << "NO\n";





}