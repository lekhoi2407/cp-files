#include "bits/stdc++.h"
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native")
using namespace std;

#define int long long  // MLE sometimes
#define sz(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
inline int gcd(int a, int b) { int r; while (b) {r = a % b; a = b; b = r;} return a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)

// for printing std::pair
template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
// for printing collection
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
// for printing std::tuple
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}

// https://codeforces.com/blog/entry/91347
int recur_depth = 0;
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr << string(recur_depth, '\t') << "\033[36m[" <<  vars << "] = ";
    string delim = "";
    (..., (cerr << delim << values , delim = ", "));
    cerr << "\033[0;39m" << endl;
}

#ifdef LOCAL
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 69
#endif

// use mt19937_64 for 64-bit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l, int r) {
    assert(l <= r);
    return uniform_int_distribution<int> (l, r)(rng);
}

string s, t;   
map<char, char> mp;
map<char, int> ck;
void solve(){
    cin >> s >> t;
    for(int i=0; i<s.size(); ++i){
        if(s[i] != t[i]){
            if(ck[t[i]] and mp[t[i]] != s[i]){
                cout << -1;
                return;
            }
            else if(ck[s[i]] and mp[s[i]] != t[i]){
                cout << -1;
                return;
            }
            mp[s[i]] = t[i];
            mp[t[i]] = s[i];
            ck[t[i]] = 1;
            ck[s[i]] = 1;
        }
    }
    for(int i=0; i<s.size(); ++i){
        if(ck[s[i]])
            s[i] = mp[s[i]];
    }
    ck.clear();
    if(s != t)
        cout << -1;
    else{
        vector<pair<char, char>> ans;
        debug(mp);
        for(auto k : mp){
            if(!ck.count(k.second) and !ck.count(k.first)){
                ans.push_back({k.first, k.second});
                ck[k.first] = 1;
                ck[k.second] = 1;
            }
        }
        cout << ans.size() << '\n';
        for(auto k : ans)
            cout << k.first << ' ' << k.second << '\n';
    }
}

// Give yourself ~30 minutes of being stuck before reading editorial
// Write stuff down

int32_t main() {
//    freopen(".inp", "r", stdin);
//    freopen(".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int test = 1;
//    cin >> test;
    for(int i=1; i<=test; ++i){
//        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}


