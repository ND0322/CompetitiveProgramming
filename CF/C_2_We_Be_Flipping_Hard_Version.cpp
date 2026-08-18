#include <bits/stdc++.h>
using namespace std; 

#define int long long

const int MAXN = 2e5+5;
const int INF = 1e18;
int n, a[MAXN];
int dp[MAXN][2];
int nxt[MAXN][2]; // to track if we flipped at i

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt; cin >> tt;
    while(tt--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        // Initialize DP table with negative infinity
        for(int i = 0; i <= n; i++) {
            dp[i][0] = -INF;
            dp[i][1] = -INF;
        }

        // Base case: before starting, sum is 0, parity is 0
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++){
                if (dp[i-1][j] == -INF) continue;

                // Current value of a[i] under parity j
                int cur = a[i] * (j == 1 ? -1 : 1);

                // Option 0: Don't flip at i
                if (dp[i-1][j] + cur > dp[i][j]) {
                    dp[i][j] = dp[i-1][j] + cur;
                    nxt[i][j] = 0;
                }

                // Option 1: Flip at i (Only allowed if cur > 0)
                if (cur > 0) {
                    // Toggles parity to !j, value becomes -cur
                    if (dp[i-1][j] - cur > dp[i][!j]) {
                        dp[i][!j] = dp[i-1][j] - cur;
                        nxt[i][!j] = 1; // Mark that we arrived at !j by flipping at i
                    }
                }
            }
        }

        // Find the best ending state
        int cur_state = 0;
        if (dp[n][1] > dp[n][0]) {
            cur_state = 1;
        }

        cout << dp[n][cur_state] << "\n";

        // Reconstruction (Backwards to find choices)
        vector<int> ans;
        for(int i = n; i >= 1; i--){
            if(nxt[i][cur_state] == 1){
                ans.push_back(i);
                cur_state = !cur_state; // backtrack to previous state
            }
        }

        // The problem allows operations in any valid chronological order.
        // Reversing our backward reconstruction naturally gives the correct
        // left-to-right chronological execution order!
        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}