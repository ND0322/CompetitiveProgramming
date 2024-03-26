#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef tuple<int,int,int> tu;
typedef pair<int,int> pii;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        string s; cin >> s;

        int start = stoi(s,0,2);

        vector<tu> edges;

        for(int i = 0; i < m; i++){
            int c; cin >> c;

            string removes; cin >> removes;

            string adds; cin >> adds;

            edges.push_back(make_tuple(stoi(removes,0,2),stoi(adds,0,2),c));
        }

        priority_queue <pii,vector<pii>,greater<pii>> pq;


    }
}