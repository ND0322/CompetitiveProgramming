#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,c[MAXN], host[MAXN],t[MAXN];

long long dp[MAXN][2];

//dp[i][0] is ans not using i
//dp[i][1] is using node

//all of these a for each child




//case 1: (IAmYourFriend)
//if we take the host we cant take the child very easy case
//for j = 0 we dont take the host
//we can choose to either take this child or not cause no child will be directly connected

//j = 0 is the same for the next two
//if we dont take the host we cant take the child cause each each child is connected


//case 2: (YourFriendIsMyFriend):
//if we choose the host
//we have 3 options
//add the current of choosing the host to choosing the child
//add the current of choosing the host to not choosing the child
//add the current of not choosing the host to choosing the child

//case 3: (WeAreYourFriends):
//combine the last 2
//first case doesnt work we can only choose one of either the host or child


int findSample(int n, int c[], int host[], int t[]){
    for(int i = 0; i < n; i++) dp[i][1] = c[i];

    for(int i = n-1; i > 0; i--){
        if(!t[i]){
            dp[host[i]][0] += max(dp[i][0], dp[i][1]);
            
            //take host cant take this dude
            dp[host[i]][1] += dp[i][0];
        }
        long long tmp = dp[host[i]][0];
        if(t[i] == 1){
            
            dp[host[i]][0] += dp[i][0];
            dp[host[i]][1] = max({dp[host[i]][1] + dp[i][1], dp[host[i]][1] + dp[i][0], tmp + dp[i][1]});
           
        }
        if(t[i] == 2){
            dp[host[i]][0] += dp[i][0];
            dp[host[i]][1] = max(dp[host[i]][1] + dp[i][0], tmp + dp[i][1]);
        }
    }

    return max(dp[0][0], dp[0][1]);
}