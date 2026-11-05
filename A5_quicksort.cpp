#include<bits/stdc++.h>
using namespace std;
long long cmp=0;
int part(vector<int>&a,int l,int h){int p=a[h],i=l;for(int j=l;j<h;j++)if(cmp++,a[j]<p)swap(a[i++],a[j]);swap(a[i],a[h]);return i;}
void qs(vector<int>&a,int l,int h,int rnd){if(l>=h)return;if(rnd)swap(a[l+rand()%(h-l+1)],a[h]);
  int p=part(a,l,h);qs(a,l,p-1,rnd);qs(a,p+1,h,rnd);}
// Avg O(n log n) both; worst O(n^2): deterministic on sorted input, randomized only with negligible probability
int main(){srand(time(0));int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;
  for(int r=0;r<2;r++){auto b=a;cmp=0;qs(b,0,n-1,r);cout<<(r?"Randomized   ":"Deterministic")<<" comparisons: "<<cmp<<" | ";
    for(int x:b)cout<<x<<" ";cout<<"\n";}}
