#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

/*
(__)
()() = 1 + 1
(())= 1 + 3

(____)
()()()
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        //) want to take farthest, ( take closer

        set<int> se;

        for(int i = 0; i < n; i+=2){
            se.insert(i);
        }

        long long ans = 0;

        for(int i = 1; i < n; i+=2){
            if(s[i] == ')'){
                int x = *se.begin();

                se.erase(se.begin());

                ans += i - x;
            }
            else{
                int x = *se.lower_bound(i);

                se.erase(x);

                ans += x-i;
            }
        }

        cout << ans << "\n";





    }
}