#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 5e5+5;

int n, ch[MAXN], out[MAXN];

vector<int> parents[MAXN];

stack<int> queue;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> ch[i];
        parents[ch[i]].push_back(i);
    }


}