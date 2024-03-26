#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//at any point a will try to choose 2 numbers with equal parity
//b will try to choose 2 numbers with different parity
//other stuff doesnt matter



const int MAXN = 1e5+5;

int n, psa[MAXN], cnt[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> psa[i];

        for(int i = 1; i <= n; i++){
            cnt[i] = psa[i] & 1;
            cnt[i] += cnt[i-1];
            psa[i] += psa[i-1];
        }

       
        cout << psa[1] << " ";
        for(int i = 2; i <= n; i++){
            if(cnt[i] % 3 == 0) cout << psa[i] - cnt[i]/3<< " ";
            if(cnt[i] % 3 == 1) cout << psa[i] - cnt[i]/3-1 << " ";
            if(cnt[i]%3 == 2) cout << psa[i] - cnt[i]/3 << " ";
        }
        cout << "\n";

        //subtract the number of times a is forced to take 0 1
        //will only happen at the end


        //cnt % 3 == 0: split evenly
        // == 1: give one extra to b
        // == 2: dont give one extra

        //a will prioritize combining ones

        //1 1 1 1
        //2 1 1
        //2 1 |
        //2 |        

        //2 thirds will be used for making 2s
        //1 1 1 1 1
        //2 1 1 1
        //2 1 1 |
        //2 2
        
        //1 1 1 1 1 1
        //2 1 1 1 1
        //2 1 1 1 |
        //2 2 1
        //2 2 |
        //4

        //1 1 1 1 1 1 1
        //2 1 1 1 1 1
        //2 1 1 1 1 |
        //2 2 1 1
        //2 2 1 |
        //2 2 |
        //4


        //1 1 1 1 1 1
        //2 1 1 1 1
        //2 1 1 1 |
        //2 2 1
        //2 2 |
        //4

        //2 2 1 1 1
        //2 2 2 1
        //2 2 2 |

        //2 2 2 2 1 1 1
        //2 2 2 2 2 1
        //2 2 2 2 2 |
        //10


        
    }
}