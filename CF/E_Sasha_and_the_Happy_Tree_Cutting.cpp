#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//greedy + range path update

//in one iteration look for the edge with the most stuff
//path update and range max with index

const int MAXN = 1e5+5;

int n, k;

set<int> effect[MAXN];
vector<int> adj[MAXN];

int sz[MAXN], p[MAXN], dep[MAXN];
int st[MAXN<<1], id[MAXN], tp[MAXN];

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, st[lo++]);
		if (hi & 1) rb = max(rb, st[--hi]);
	}
	return max(ra, rb);
}

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	p[cur] = par;
	for (int chi : adj[cur]) {
		if (chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	int h_chi = -1, h_sz = -1;
	for (int chi : adj[cur]) {
		if (chi == par) continue;
		if (sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if (h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for (int chi : adj[cur]) {
		if (chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}

int path(int x, int y) {
	int ret = 0;
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
		ret = max(ret, query(id[tp[x]], id[x]));
		x = p[tp[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = max(ret, query(id[x], id[y]));
	return ret;
}




