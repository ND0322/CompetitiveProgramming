#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
const ld eps = 1e-9; 
 
 
int n;
vector<ld> v;

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
 
	reverse(v.begin(), v.end());
	while (v.size() && v.back() == 1)
		v.pop_back();
	reverse(v.begin(), v.end());
 
	for (auto i : v)
		if (i == 1) {
			cout << "-1\n";
			return;
		}
 
 
	for (auto &i : v)
		i = log(log(i));
 
	ll ans = 0;
	for (int i = 1; i < v.size(); i++) {
		ld need = v[i - 1] - v[i];
		if (need > eps) {
			int cnt = 1 + (need - eps) / log(2);
			ans += cnt;
			v[i] += cnt * log(2);
		}
	}
 
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

}