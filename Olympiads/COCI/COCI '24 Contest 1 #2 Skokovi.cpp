#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//store the set of all good indices iteratively and bsearch the height of i
int main(){
    int n, k; cin >> n >> k;

    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    set<int> s = {a[1]};

    cout << "1 ";

    for(int i = 2; i <= n; i++){


        

        if(a[i] < *s.begin()){
            if(*s.begin() - a[i] <= k){
                cout << "1 ";
                s.insert(a[i]);
            }
            else cout << "0 ";
            continue;
        }

        if(a[i] > *s.rbegin()){
            if(a[i] - *s.rbegin() <= k){
                cout << "1 ";
                s.insert(a[i]);

            }
            else cout << "0 ";
            continue;
        }

        auto it = s.lower_bound(a[i]);

        it--;


        if(a[i] - *it <= k){
            cout << "1 ";
            s.insert(a[i]);
            continue;
        }

        it++;
        it++;

        if(*it - a[i] <= k){
            cout << "1 ";
            s.insert(a[i]);
            continue;
        }

        cout << "0 ";
        


    }


}



