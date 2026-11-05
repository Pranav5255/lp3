#include<bits/stdc++.h>
using namespace std;
int calls=0;
int fr(int n){calls++;return n<2?n:fr(n-1)+fr(n-2);}     // Recursive: T=O(2^n), S=O(n) stack
int fi(int n){int a=0,b=1;while(n--){b+=a;a=b-a;}return a;} // Iterative: T=O(n),  S=O(1)
int main(){int n;cin>>n;cout<<"Recursive: "<<fr(n)<<" ("<<calls<<" calls)\nIterative: "<<fi(n)<<"\n";}
