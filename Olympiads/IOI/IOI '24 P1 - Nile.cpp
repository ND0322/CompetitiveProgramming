/*
observe that the pattern must be AA or ABA

because imagine we skipped more than 1
We would get ABBA in which case we can pair the two Bs

dp

if(w[i+1] - w[i] <= D) a[i+1] + a[i+2] + dp[i+3]
if(w[i+1] - w[i] <= )
*/