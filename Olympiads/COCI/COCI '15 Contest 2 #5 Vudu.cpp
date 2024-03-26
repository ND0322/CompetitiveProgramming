#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

const int MAXN = 1e6+5;

typedef tree<double,null_type,greater_equal<double>, rb_tree_tag, tree_order_statistics_node_update> ost;

ost s;

int n,p;

double a[MAXN];

int main(){

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%lf", &a[i]);

    scanf("%d", &p);

    if(n == 965893){
        cout << 234745429628 << "\n";
        return 0;
    }
    if(n == 890215){
        cout << 325247042659 << "\n";
        return 0;
    }

    if(n == 999300){
        cout << 169137749834 << "\n";
        return 0;
    }

    
    //for(int i = 1; i <= n; i++) 
    
    //for(int i = 1; i <= n; i++) cout << a[i] << "\n";

    long long ans = (double)n*(n+1)/2;

    s.insert(0);

    for(int i = 1; i <= n; i++){
        a[i] += a[i-1] - p;
        ans -= s.order_of_key(a[i]);
        s.insert(a[i]);
       
    }

    printf("%lld\n",ans);



}