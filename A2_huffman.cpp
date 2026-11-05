#include<bits/stdc++.h>
using namespace std;
struct N{char c;int f;N*l,*r;};
void pr(N*n,string s){if(!n)return;if(!n->l)cout<<n->c<<": "<<(s.empty()?"0":s)<<"\n";pr(n->l,s+"0");pr(n->r,s+"1");}
int main(){string s;cin>>s;map<char,int>m;for(char c:s)m[c]++;
  auto cmp=[](N*a,N*b){return a->f>b->f;};priority_queue<N*,vector<N*>,decltype(cmp)>q(cmp);
  for(auto[c,f]:m)q.push(new N{c,f});
  while(q.size()>1){N*a=q.top();q.pop();N*b=q.top();q.pop();q.push(new N{0,a->f+b->f,a,b});} // greedy: merge 2 smallest
  pr(q.top(),"");} // O(n log n)
