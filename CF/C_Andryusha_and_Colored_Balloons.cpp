#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;
#define pb  push_back
#define pf  push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
const ll mod = 1e9 + 7;
const int N = 2e5 + 100;
const ll INF = 1e18;
vector<vll> g(N);
ll mx = 0;
vector<ll> col(N, 0);
void dfs(ll v, ll p = 1){
	ll c = 1;
	mx = max(mx, col[v]);
	for(auto u : g[v]){
		if(u != p){
			if(c == col[v] || c == col[p]) c++;
			if(c == col[v] || c == col[p]) c++;
			col[u] = c++;
			dfs(u, v);
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	for(ll i = 1; i < n; i++){
		ll u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	col[1] = 1;
	dfs(1);
	cout << mx << '\n';
	for(ll i = 1; i <= n; i++){
		cout << col[i] << " ";
	}
	cout << '\n';
	return 0;
}