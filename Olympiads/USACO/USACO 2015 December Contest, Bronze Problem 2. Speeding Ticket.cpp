#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 101;

int n,m, limit[MAXN], speed[MAXN];

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    
    cin >> n >> m;

	int start = 0;
	for (int i = 0; i < n; i++) {
		int l,s; cin >> l >> s;
		for (int j = start; j < start + l; j++) limit[j] = s;
		start += l;
	}

	start = 0;
	
	for (int i = 0; i < m; i++) {
		int l,s; cin >> l >> s;
		for (int j = start; j < start + l; j++) speed[j] = s;
		start += l;
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) ans = max(ans, speed[i] - limit[i]);
	cout << ans << "\n";
}