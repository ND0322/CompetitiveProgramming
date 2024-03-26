#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1e6+5;

long long n,c, freq[2*MAXN], psa[2*MAXN];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);


    cin >> n >> c;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        psa[x+1]++;
        freq[x+1]++;
        freq[x+c+1]++;
        psa[x+c+1]++;
    }

    for(int i = 1; i <= 2*c+1; i++) psa[i] += psa[i-1];

    

    //psa = [0, 3, 3, 4, 4, 4, 6, 7, 7 ,7, 8, 11]

    //6 - 0 - 2
    //7 - 3 - 0


    //loop through where a could be and consider all pairs between b (opposite of a) and a
    //3 cases
    //1: choose 1 from a 2 from x (a to b)
    //2: choose 2 from a
    //3: choose all from a

    //nC3
    long long tot = (n * (n-1) * (n-2)) / 6;
    long long ans = 0;

    

    
    
   
    

    for(int b = 1; b <= c; b++){
        int a = (b + (c/2));

        


        //cout << b << " " << a << "\n";
        //cout << psa[a] - psa[b-1] - freq[a] << "\n";
        ans += (freq[a] * (freq[a] - 1) * (freq[a] - 2))/6;

        
        ans += (psa[a] - psa[b-1] - freq[a]) * ((freq[a]) * (freq[a] - 1))/2;

    
        ans += ((psa[a] - psa[b-1] - freq[a]) * (psa[a] - psa[b-1] - 1 - freq[a]))/2 * freq[a];  



        
    }

   

    if(!(c&1)){
        for(int b = 1; b <= c/2; b++){
            int a = (b+(c/2));
            ans -= ((freq[a]) * (freq[a]- 1)) / 2 * freq[b];
            ans -= ((freq[b]) * (freq[b]- 1)) / 2 * freq[a];
        }
    }

        

    //cout << ans << "\n";

    

    cout << tot - ans << "\n";



}

  


