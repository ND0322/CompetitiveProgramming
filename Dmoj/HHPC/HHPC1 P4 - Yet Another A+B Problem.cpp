#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

#define int long long

const int MAXN = 1e7+5;

int big[MAXN];

int32_t main() {
	for (int i = 2; i <= 1e7; i++) {
		if(!big[i]) {
			for (int j = i; j <= 1e7; j += i) { big[j] = i; }
		}
	}

	int tt; cin >> tt;

    while(tt--){
        int x; cin >> x;
		int ans = 1;
		while (x != 1) {
			int prime = big[x];
			int cnt = 0;
			while (x % prime == 0){
				cnt++;
				x /= prime;
			}
			ans *= 2*cnt+1;
		}
		
        cout << ans << "\n";
    }

	
}


/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/