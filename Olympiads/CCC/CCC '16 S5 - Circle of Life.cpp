#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//good question
//2 pages of proof stuffs


const int MAXN = 1e5+5;

int n;

long long t;

vector<int> a(MAXN), b(MAXN);

int msb(long long x){
    return 64 - __builtin_clzll(x);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);

    cin >> n >> t;

    string s; cin >> s;

    for(int i = 1; i <= n; i++) a[i] = (s[i-1] == '1');

    

    
    
    for(int i = 0; i <= msb(t); i++){

        
       
        
        if(!(t & (1LL<<i))) continue;
        
        for(int j = 1; j <= n; j++){
            int l,r;
            long long tmp = 1LL<<i;
            if(j-tmp > 0) l = j-tmp;
            else l = n - (tmp-j) % n;
            r = (j+ tmp)%n;

            if(!l) l = n;
            if(!r) r= n;

            //cout << j << " " << l << " " << r << "\n";

            //cout << a[l] << "\n";

            b[j] = a[l] ^ a[r];
        }

        a.swap(b);
    }

    
    for(int i = 1; i <= n; i++) cout << a[i];
    cout << "\n";
    

    
    

}