#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int n,m;
vector<vector<int>> a;
vector<vector<int>> b;

bool can(int x){
    b = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        deque<int> q;

       
        for (int j = 0; j < m; j++) {
            while (!q.empty() && q.front() < j - x + 1) q.pop_front();
            while (!q.empty() && a[i][q.back()] >= a[i][j]) q.pop_back();
            q.push_back(j);
            if (j >= x-1) b[i][j - x + 1] = a[i][q.front()];
            
        }
    }
    for (int j = 0; j < m; j++) {
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() < i - x + 1) q.pop_front();
            while (!q.empty() && b[q.back()][j] >= b[i][j]) q.pop_back();
            q.push_back(i);
            if (i >= x-1 && b[q.front()][j] >= x) return 1;
        }
    }
    return 0;
    
}

void solve(){
    cin >> n >> m;

    a = vector<vector<int>> (n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    int lo = 1;
    int hi = min(n,m);

    int ans = -1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();
}