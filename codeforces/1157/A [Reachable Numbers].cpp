/**
 *    author: kh0i
 *    created: 30.09.2021 15:12:41
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mp make_pair
#define F first
#define S second

#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << " = " << x << '\n'

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr<<" "<<H;
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve(){
	int n; cin>>n;
	set<int> ans;
	while(true){
		ans.insert(n);
		n++;
		while(true){
			if(n%10!=0) break;
			while(n%10==0) n/=10;
		}
		if(ans.count(n)) break;
	}
	// for(auto k: ans) cout<<k<<' ';
	cout<<sz(ans);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    /*freopen("*.inp", "r", stdin);
    freopen("*.out", "w", stdout);*/
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}