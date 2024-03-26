#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

const int INF = 1e9 + 7;

typedef pair<int, int> pii;

int n, m;

pii fmoves[MAXN], bmoves[MAXN];

int dist(pii x,pii y){
  int distx = abs(y.first - x.first);
  int disty = abs(y.second - x.second);

  

  return distx * distx + disty * disty;
}

int main() {

  freopen("radio.in","r",stdin);
  freopen("radio.out","w",stdout);
  
  cin >> n >> m;

  

  vector<vector<int>> dp(n+5,vector<int>(m+5,INF));

  int fx, fy, bx, by;
  cin >> fx >> fy >> bx >> by;

  vector<pii> floc, bloc;

  floc.push_back({fx, fy});
  bloc.push_back({bx, by});

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;

    if (c == 'N') {
      fmoves[i] = {0, 1};
    }
    if (c == 'S') {
      fmoves[i] = {0, -1};
    }
    if (c == 'W') {
      fmoves[i] = {-1, 0};
    }
    if (c == 'E') {
      fmoves[i] = {1, 0};
    }

    floc.push_back({floc[i - 1].first + fmoves[i].first,
                    floc[i - 1].second + fmoves[i].second});



    
  }
  for (int i = 1; i <= m; i++) {
    char c;
    cin >> c;

    if (c == 'N') {
      bmoves[i] = {0, 1};
    }
    if (c == 'S') {
      bmoves[i] = {0, -1};
    }
    if (c == 'W') {
      bmoves[i] = {-1, 0};
    }
    if (c == 'E') {
      bmoves[i] = {1, 0};
    }

    bloc.push_back({bloc[i - 1].first + bmoves[i].first,
                    bloc[i - 1].second + bmoves[i].second});
  }


  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i+1][j] = min(dp[i+1][j],dp[i][j] + dist(floc[i+1],bloc[j]));

      dp[i][j+1] = min(dp[i][j+1],dp[i][j] + dist(floc[i],bloc[j+1]));
      dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + dist(floc[i+1],bloc[j+1]));
    }
  }

  cout << dp[n][m] << endl;

}