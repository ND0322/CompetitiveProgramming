#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//it always be good if no factor > i
//each number can only be good for so long 

const int MAXN = 1e6+5;

int n, a[MAXN];

int f(int n) {

    int ans = 1;

    
    while (n % 2 == 0) {
        ans = 2;
        n /= 2;
    }


    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0)  {
            ans = i;
            n /= i;
        }
    }


    if (n > 2) {
        ans = n;
    }

    return ans;
}

int main(){
    cin >> n;

    //i <= min(l,r)

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        a[i] = f(a[i]);
        
        a[i] = i-a[i]+1;
    }



    long long ans = 0;

    for(int i = 1; i <= n; i++){
        int r = i;
        for(; r <= n; r++){
            if(a[r] < i) break;
        }

        ans += r-i;

        cout << r << " " << i << "\n";
    }

    cout << ans << "\n";


}