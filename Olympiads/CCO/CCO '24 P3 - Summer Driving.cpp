#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, rt, a,b, dp[MAXN], parent[MAXN];

vector<int> adj[MAXN], nxt[MAXN], as[MAXN];

/*
that shi does not work

notice that the depth a can travel to strictly increases probably
b < a therefore we will never revisit a node

the game will stay within bs subtree after its move 

consider the problem backwards
we start from each candidate and verify if it can reach the rt
we take the largest node that can reach the rt
     
          6
         / \
        1   4
        |  / \  
        3 8   2
        |    / \
        9   5   7





*/  


int main(){
   cin >> n >> rt >> a >> b;

   if(b > a){
      cout << "1\n";
      return 0;
   }


}