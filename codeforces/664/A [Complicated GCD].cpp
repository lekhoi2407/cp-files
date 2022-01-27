// Problem: A. Complicated GCD
// Contest: Codeforces - Codeforces Round #347 (Div. 2)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
	string s, t;
	cin>>s>>t;
	if(s==t){
		cout<<s;
		return;
	}
	cout<<1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
