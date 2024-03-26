#include <bits/stdc++.h>
#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 4005;

int n, m,r,s, a[MAXN][MAXN], b[MAXN][MAXN], ans[MAXN][MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }


    cin >> r >> s;
    for (int i = 0; i < n; i++) {
        deque<int> q;
        for (int j = 0; j < m; j++) {
            while (!q.empty() && q.front() < j - s + 1) q.pop_front();
            while (!q.empty() && a[i][q.back()] <= a[i][j]) q.pop_back();
            q.push_back(j);
            if (j >= s-1) b[i][j - s + 1] = a[i][q.front()];
            
        }
    }
    for (int j = 0; j < m; j++) {
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() < i - r + 1) q.pop_front();
            while (!q.empty() && b[q.back()][j] <= b[i][j]) q.pop_back();
            q.push_back(i);
            if (i >= r-1) ans[i - r + 1][j] = b[q.front()][j];
            
        }
    }
    for (int i = 0; i < n - r + 1; i++) {
        for (int j = 0; j < m - s + 1; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}
