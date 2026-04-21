#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, k, a[MAXN];

set<int> s;


/*
sorted order


fixed by first number chosen 
consider the first number

we can place it anywhere on the chain of 4

depending on that the other 3 are uniquely determined
now we have all numbers that are (a+12k)
take all numbers mod 12 to find there original 4 value 
*/



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;


    for(int i = 1; i <= n; i++){
        cin >> a[i];

        a[i] %= 12;
    }


    int ans = 0;
    for(int i = 0; i < 12; i++){
        s = {i, (i+4) % 12, (i+7) % 12, (i+10) % 12};

        int tmp = k;
        int r = 0;
        for(int j = 1; j <= n; j++){

            while(r < n && (s.find(a[r+1]) != s.end() || tmp)){
                if(s.find(a[r+1]) == s.end()) tmp--;
                r++;
            }

            ans = max(ans, r-j+1);


            tmp += (s.find(a[j]) == s.end());
        }


        
    }

    cout << ans << "\n";
}