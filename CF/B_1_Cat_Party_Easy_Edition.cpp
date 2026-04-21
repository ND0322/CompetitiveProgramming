#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], freq[MAXN];

map<int,int> cnt;


/*
either one element with freq k+1 or 1
*/

int main(){
    cin >> n;

    int ans = 1;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        if(cnt.find(freq[x]) != cnt.end()) cnt[freq[x]]--;

        if(!cnt[freq[x]]) cnt.erase(freq[x]);
        freq[x]++;
        cnt[freq[x]]++;


        if(cnt.size() == 1 && ((*cnt.begin()).second == 1 ||(*cnt.begin()).first == 1 )){
            ans = i;
            continue;
        }

        if(cnt.size() != 2) continue;
        
        if(cnt.find(1) == cnt.end() && cnt.find((*cnt.begin()).first + 1) == cnt.end()) continue;

        if(cnt.find((*cnt.begin()).first + 1) != cnt.end() && cnt[(*cnt.begin()).first+1] == 1){
            ans = i;
            continue;
        }

        
        
        if(cnt.find(1) != cnt.end() && cnt[1] == 1){
            ans = i;
            continue;
        }

        
        
        
    }

    cout << ans << "\n";
}