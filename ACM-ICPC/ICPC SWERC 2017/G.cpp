#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 2005;
const int inf = 0x3f3f3f3f;


int N, M;
ll a[MAXN][MAXN];

pair<ll,ll> b[MAXN],c[MAXN], r;

//i stole this btw
ll hungarian() {
    ll n = N;
    ll m = N+M-1;
    vector<ll> u(n+1), v(m+1), p(m+1), way(m+1);
    for(ll i = 1; i <= n; ++i) {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(m+1, inf);
        vector<char> used(m+1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = inf, j1;
            for(ll j = 1; j <= m; ++j)
                if(!used[j]) {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for(ll j = 0; j <= m; ++j)
                if(used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while(p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }

    return -v[0];
}

int main() {
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> b[i].first >> b[i].second;
    for(int i = 1; i <= M; i++) cin >> c[i].first >> c[i].second;

    cin >> r.first >> r.second;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N+M-1; j++){
            if(j <= M) a[i][j] = abs(b[i].first - c[j].first) + abs(b[i].second - c[j].second) + abs(b[i].first - r.first) + abs(b[i].second - r.second);
            else a[i][j] = (abs(b[i].first - r.first) + abs(b[i].second - r.second))<<1;
        }
    }

    cout << hungarian() << "\n";



}