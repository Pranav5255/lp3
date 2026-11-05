#include<bits/stdc++.h>
using namespace std;
int main(){int n,W;cin>>n>>W;vector<int>w(n),v(n),dp(W+1);for(int i=0;i<n;i++)cin>>w[i]>>v[i];
  for(int i=0;i<n;i++)for(int j=W;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+v[i]); // O(nW)
  cout<<"Max value: "<<dp[W]<<"\n";}
