#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;



typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;

const int MAXN = 1e6+5;
const long long INF = 1e18;

int n;

ll d[MAXN], a[MAXN], dp[MAXN], psa[MAXN], pref[MAXN];

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {

	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) {
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({-k, -m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -l.k * x + -l.m;
	}
};


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    
    for(int i = 1; i <= n; i++){
        cin >> a[i];

        psa[i] = a[i] + psa[i-1];
        pref[i] = a[i] * i + pref[i-1];
    }

    for(int i = 1; i <= n; i++) cin >> d[i];

   
    LineContainer cht;
    cht.add(0,0);
   

    for(int i = 1; i <= n; i++){
        cht.add(psa[i-1], dp[i-1] - psa[i-1] + pref[i-1]);
        dp[i] = cht.query(-i) + i * psa[i] + psa[i] - pref[i] + d[i];
        

    }

    cout << dp[n] << "\n";
    

    

    

    

}