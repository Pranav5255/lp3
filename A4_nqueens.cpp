#include<bits/stdc++.h>
using namespace std;
int n;vector<int>q; // q[row]=col
bool ok(int r,int c){for(int i=0;i<r;i++)if(q[i]==c||abs(q[i]-c)==r-i)return 0;return 1;}
bool solve(int r){if(r==n)return 1;for(int c=0;c<n;c++)if(ok(r,c)){q[r]=c;if(solve(r+1))return 1;}return 0;}
int main(){int c0;cin>>n>>c0;q.assign(n,0);q[0]=c0; // first queen fixed at (0,c0)
  if(!solve(1))return cout<<"No solution\n",0;
  for(int r=0;r<n;r++){for(int c=0;c<n;c++)cout<<(q[r]==c?"Q ":". ");cout<<"\n";}}
