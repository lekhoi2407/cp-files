/**
 *	author: kh0i
 *	created: 11.01.2022 13:38:43
**/
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

void solve(){
    int n, m, x, f = 0;
    map<int, int> mp;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> x;
        mp[x] = 1;
    }
    for(int i=0; i<m; ++i){
        cin >> x;
        if(f) continue;
        if(mp[x]){
            cout << "YES\n";
            cout << 1 << ' ' << x << '\n';
            f = 1;
        }
    }
    if(f) return;
    cout << "NO\n";
}

// Give yourself ~30 minutes of being stuck before reading editorial
// Write stuff down

int32_t main() {
//    freopen(".inp", "r", stdin);
//    freopen(".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int test = 1;
    cin >> test;
    for(int i=1; i<=test; ++i){
//        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}


