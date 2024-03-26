#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const ll N = 20;
ll w[N][N];
ll p[N], fa[N];
ll n, m, k, ans = 1e18;

ll find(ll x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

bool check()
{
	for (ll i = 0; i <= n; i++) p[i] = i;

	for (ll i = 2; i <= n; i++)
	{
		if (find(i) == find(fa[i])) return false;
		p[i] = p[fa[i]];
	}
	return true;
}

void dfs(ll step, ll sum)
{
	if (step == n + 1)
	{
		if (check())
			ans = min(ans, sum);
		return;
	}
	for (ll i = 1; i <= n; i++)
	{
		if (i != step && w[step][i] != -1)
		{
			fa[step] = i;
			dfs(step + 1, (sum + w[step][i]) % k);
		}
	}
	return;
}

int main()
{
	cin >> n >> m >> k;
	memset(w, -1, sizeof w);
	for (ll i = 1; i <= m; i++)
	{
		ll u, v, weight;
		cin >> u >> v >> weight;
		w[u][v] = weight;
		w[v][u] = weight;
	}
	dfs(2, 0);
	cout << ans << endl;
}