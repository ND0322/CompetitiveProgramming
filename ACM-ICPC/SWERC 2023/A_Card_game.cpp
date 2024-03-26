#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN], c[5] = {0,1,2,3,4}, ans = 1e9;

map<char,int> m;

int solve(){
    vector<int> dp;
    vector<int> d;

    for(int i = 1; i <= n; i++) d.push_back(a[i] + c[b[i]] * n);

	for(int i : d) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) dp.push_back(i);
		else dp[pos] = i;
	}

	return n-dp.size();
}

int main(){
    cin >> n;
    
    m['S'] = 0;
    m['W'] = 1;
    m['E'] = 2;
    m['R'] = 3;
    m['C'] = 4;

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        int x; cin >> x;

        a[i] = x;
        b[i] = m[c];
    }

    do{
        ans = min(ans,solve());
    }
    while(next_permutation(c, c+4));

    cout << ans << "\n";


}

