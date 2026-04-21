#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

/*
let x be the number of time we use rpeate the second

ny + b1 = mx + b2

ny - mx = b2 - b1
ny = mx + b2 - b1
y = (mx + b2 - b1) / n


*/

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}


int main(){
    int n,m; cin >> n >> m;

    string s; cin >> s;
    string t; cin >> t;

    s = '.' + s;
    t = '.' + t;

    //multiply gcd(n, m)

    int mult = gcd(n,m);

    n = n / gcd(n,m);
    m = m / gcd(n,m);



    /*
    abbbabbbabbb

    bbaabbbbaabb
    */

}