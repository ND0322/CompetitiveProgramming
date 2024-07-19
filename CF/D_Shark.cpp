#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], parents[MAXN], sz[MAXN], cnt[MAXN], cc, tot;

pair<int,int> s[MAXN];
bool wall[MAXN];

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

    if(sz[x] < sz[y]) swap(x,y); 
    cnt[sz[x]]--;
    cnt[sz[y]]--;  
    parents[y] = x;
    sz[x] += sz[y];
    cnt[sz[x]]++;
}
//dsu merging stuff
//start from small k to large k
//when we merge we add the sizes of the children + 1 for the location for that component
//number of days increases by 1
//so we know the target size of each array
//maintain a cnt array and simple lookup to validate an answer 
//if both neighbors are walls, increment cc
//if only one is wall nothing changes
//if both are not walls decrement cc cnt

int main(){
    cin >> n;

    set<int> al;
    

    for(int i = 1; i <= n; i++){
        parents[i] = i;
        cin >> a[i];
        al.insert(a[i]);
        al.insert(a[i]+1);
        s[i] = {a[i], i};
    }

    sort(s+1,s+n+1);

    int p = 1;

    memset(wall,1,sizeof(wall));


    pair<int,int> ans = {-1,-1};

    for(int i : al){
        //cout << i << "\n";
        set<int> queue;
        while(p <= n){
            if(s[p].first >= i) break;
            wall[s[p].second] = 0;
            sz[s[p].second] = 1;
            cnt[1]++;
            queue.insert(s[p].second);
            tot++;
            p++;
        }

        for(int j : queue){
            if(wall[j-1] && wall[j+1]) cc++;
            else if(!wall[j-1] && !wall[j+1]) cc--;
            if(!wall[j-1] && j != 1) uni(j,j-1);
            if(!wall[j+1] && j != n) uni(j,j+1); 
        }

        //cout << tot << " " << cc << "\n";

        //if(tot % cc == 0) cout << "r: " << cnt[tot/cc] << "\n";
        if(!cc) continue;
        if(tot%cc == 0 && cnt[tot/cc] == cc) ans = max(ans, {cc, -i});
        
        
    }

    cout << -ans.second << "\n";

   


}