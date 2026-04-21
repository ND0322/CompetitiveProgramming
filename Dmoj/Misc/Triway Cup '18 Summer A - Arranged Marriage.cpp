#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long n,b,a; cin >> n >> b >> a;

    /*
    f(x) = (a + x * b) (n-x)
         = -bx^2 - ax + nb x + an
         = -bx^2 + (nb - a) x + an

        -b/2a
    */

    if(!b){
        cout << a * n << "\n";
        return 0;
    }

    long long x = (a-n*b) / (-2 * b);

    long long ans = -b * x * x + (n * b - a) * x + a * n;

    x++;

    ans = max(ans,-b * x * x + (n * b - a) * x + a * n);

    cout << ans << "\n";





}