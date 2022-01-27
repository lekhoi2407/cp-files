// Problem: A. Epic Game
// Contest: Codeforces - Codeforces Beta Round #90
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define MOD 1000000007

#define pb push_back
#define pf push_front
#define vi vector<int>
#define sz(x) (int((x).size()))
#define bg(x) begin(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 

#define each(a,x) for (auto& a: x)
#define FOR(i, n) for(int i=0; i<n; i++)

void solve(){
	int a, b, n;
	cin>>a>>b>>n;
	int count=0;
	while(true){
		if(count%2==0){
			if(n==0){
				cout<<1;
				return;
			}
			n-=__gcd(a, n);
			if(n<0){
				cout<<1;
				return;
			}
			count++;
		}
		if(count%2==1){
			if(n==0){
				cout<<0;
				return;
			}
			n-=__gcd(b, n);
			if(n<0){
				cout<<0;
				return;
			}
			count++;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
