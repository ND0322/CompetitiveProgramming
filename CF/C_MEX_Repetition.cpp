#include <bits/stdc++.h>
#include <iostream>

using namespace std;




int main(){

    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<bool> have(n+1);


        k %= (n+1);

        vector<int> balls(n+1);

        for(int i = 0; i < n; i++){
            cin >> balls[i];
            have[balls[i]] = 1;
        }

        for(int i = 0; i <= n; i++){
            if(!have[i]) balls[n] = i;
        }

    
        rotate(balls.begin(), balls.begin()+balls.size()-k, balls.end());
        


        for(int i = 0; i < n; i++) cout << balls[i] << " ";

        cout << "\n";


    }
}