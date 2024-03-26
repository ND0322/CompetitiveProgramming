#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;
//cht dp
//m = -d
//b = dp[i] + a[i] + d[i] * i
//adding d[i] to b to offest the slope
//querying on i

const int MAXN = 1e6+5;
const long long INF = 1e18;

typedef long long ll;

int n;

long long dp[MAXN];



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
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};




int main(){
    cin >> n;

    LineContainer cht;
    
    cht.add(0,0);
    //my cht implementation wasnt working


    for(int i = 1; i <= n; i++){
        dp[i] = cht.query(i);

        //cout << dp[i] << "\n";

        long long a,d; cin >> a >> d;

        long long b = dp[i] + a + d*i;

        cht.add(-d, b);
    }

    cout << cht.query(n+1) << "\n";


}