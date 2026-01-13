#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

/*
we only compare about prefix max

look at i where prefix max increases 

dp

i, max prefix

transition by finding next j

if max prefix >= ai we can transition to any suffix or move to next without buying 
otherwise we must at least transition to (ai, j)

When transitioning to some j > pmax we have to query a diagonal

(j, i+j), (j+1, i+j+1)


we can build suffix mins along the diagonal by finding where the diagonal must end 



*/

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cout << "Case #" << _ << ": " << ans << "\n";
    }
}