#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;
const int MAXN = 2e5+5;

int n, a[MAXN];

string s;

int main(){
    cin >> n;

    set<pair<int,int>> intro, extro;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        intro.insert({a[i], i});
    }

    for(int i = 0; i < 2*n; i++){
        char c; cin >> c;

        if(c == '0'){
            pair<int,int> seat = *intro.begin();

            intro.erase(intro.begin());

            cout << seat.second << " ";

            extro.insert({seat.first, seat.second});
        }
        else{
            pair<int,int> seat = *prev(extro.end());

            cout << seat.second << " ";

            

            extro.erase(seat);

           
        }
    }

    cout << "\n";


}