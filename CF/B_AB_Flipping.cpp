#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//all b will end up on the left all a on the right

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        

        string s; cin >> s;

        long long ans = 0;
        bool first = true;
        int last = 0;


        for(int i = 0; i < n; i++){
            if(s[i] == 'B'){
                ans += i-last;

                if(i == last) last = i+1;
                else last = i;

            }
        }

        cout << ans << "\n";



    }
}