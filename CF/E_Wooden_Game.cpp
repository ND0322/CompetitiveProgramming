#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;


//for some tree we can delete the whole tree to get some sz bits
//process bits from high to low
//if we have a bit thats already on and we get another set bit for that pos we can push it down one
int n, a[MAXN];

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        memset(a,0,sizeof(a));

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            for(int j = 1; j <= a[i]-1; j++){
                int x; cin >> x;
            }
        
        }
        
        int ans = 0;

        for(int j = 20; j >= 0; j--){
            for(int i = 1; i <= n; i++){
                if(!(a[i] & (1<<j))) continue;
                if(!(ans & (1<<j))) ans += (1<<j);
                else{
                    ans|= (1<<j)-1;
                }
            }
        }


        cout << ans << "\n";
    }
    

   
}