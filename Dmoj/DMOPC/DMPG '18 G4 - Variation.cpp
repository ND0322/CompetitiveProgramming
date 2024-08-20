#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

#define int long long

using namespace std;

const int MAXN = 2005;

int n, dp[MAXN][MAXN<<1], A, B;

pair<int,int> a[MAXN];
map<int,int> mp;





/*
create frequency array
sort and processs small to big or other way idk
the things of that value will become a range starting from a[i] - k to a[i] + j
where k + j = frequency
dp
bruteforce right endpoint of the range
hopefully that thing is convex
*/


int main(){
    cin >> n >> A >> B;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    n = mp.size();

    int j = 1;
    for(auto i : mp) a[j++] = i;


    
    for(int i = n; i >= 1; i--){
        for(int r = 4005; r >= 0; r--){
            

        }
    }

    cout << dp[1][0] << "\n";
    

    
}