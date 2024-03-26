#include <bits/stdc++.h>
#include <iostream>




using namespace std;


const int MAXN = 1e6+5;

int n,a[MAXN],freq[MAXN];

long long b[MAXN],sum[MAXN],psa[MAXN];







int main() {

  

  long long check = 0;
  int big = 0;

  
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);

    big= max(big,a[i]);

    freq[a[i]]++;
  }

  
  for(int i = 0; i < n; i++){
    scanf("%lld", &b[i]);

    check = max(check,b[i]);
  }

  for(int i = 2; i <= big; i++){
    sum[i] = sum[i-1] + freq[i-1];
    psa[i] = psa[i-1] + freq[i-1] * (i-1);
  }



 

  

  

  

  //for(int i = 0; i < n; i++) cout << sum[i] << "\n";

  //sort(b,b+n);

  


  //4463436074
  //2273002753
 
  if(big != check){
    cout << "-1\n";
    return 0;
  }

  long long ans = 0;

  
  for(int i = 0; i < n; i++){
    ans += psa[b[i]] + ((n-(sum[b[i]])) * b[i]);
  }

  //cout << query(2) << "\n";



  
  printf("%lld\n", ans);

 
  
}