#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int a[MAXN] , psa[MAXN], n;

/*
psa1[r] - psa1[l-1] + psa2[r] - psa2[l-1] >= psa3[r] - psa[l-1]

psa[r] >= psa[l-1]

where psa is 1 + 2 - 3
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        multiset<int> s;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i < n; i++){
            psa[i] = psa[i-1] + pow(-1, a[i] == 3);
            s.insert(psa[i]);
        }


        int bal = 0;
        bool flag = 0;
        for(int i = 1; i < n; i++){

            bal += pow(-1, a[i] != 1);

            if(bal < 0 ) continue;
            s.erase(s.find(psa[i]));

            if(s.size() && *s.rbegin() >= psa[i]){
                flag = 1;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}