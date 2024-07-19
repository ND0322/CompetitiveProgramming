#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n;

stack<int> a,b;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a.push(x);
    }

    vector<pair<char, char>> ans; 
    for(int i = 1; i <= n; i++){

        if(a.empty() && b.top() != i){
            cout << "-1\n";
            return 0;
        }
        if(!b.empty() && b.top() == i){
            b.pop();
            ans.push_back({'B', 'C'});
        }
        else{
            while(a.size() && a.top() != i ){
                ans.push_back({'A', 'B'});
                b.push(a.top());
                a.pop();
            }

            if(!a.size()){
                cout << "-1\n";
                return 0;
            }

            a.pop();
            ans.push_back({'A', 'C'});
        }
    }

    cout << ans.size() << "\n";

    for(auto [a,b] : ans) cout << a << " " << b << "\n"; 
}
