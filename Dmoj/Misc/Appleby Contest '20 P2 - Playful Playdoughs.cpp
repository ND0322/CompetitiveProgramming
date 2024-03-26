#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,q;

long long freq[MAXN];

int main(){
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        freq[x]++;
    }

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int x; cin >> x;

            freq[x/2]+=freq[x];
            freq[(int)ceil(x/2.0)]+=freq[x];
            freq[x] = 0;
        }
        else{
            int x; cin >> x;

            cout << freq[x] << "\n";


        }
    }
}