#include <bits/stdc++.h>
#include <random>
using namespace std;


#define ll long long
#define INF ((ll)(1e9+7))
#define fo(i, n) for(ll i=0;i<((ll)n);i++)
#define deb(x) cout << #x << " = " << (x) << endl;
#define deb2(x, y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LSOne(S) ((S) & (-S))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template <class result_t=std::chrono::milliseconds,class clock_t=std::chrono::steady_clock,class duration_t = std::chrono::milliseconds>
auto since(std::chrono::time_point<clock_t, duration_t> const& start){return std::chrono::duration_cast<result_t>(clock_t::now() - start);}
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpl> vvpl;

vector<ll> rvals;

ll compute_hash(string &s){
    ll hash = 0;
    fo(i, s.size()){
        hash ^= s[i] * rvals[i];
    }
    return hash;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll amount;
    cin >> amount;
    // deb(amount);
    
    vector<string> strings(amount);
    ll max_length = 0;
    fo(i, amount){
        cin >> strings[i];
        max_length = max(max_length, (ll)strings[i].size());
    }
    mt19937 rng(1337);
    fo(i, max_length){
        rvals.pb(rng()%((1<<31)/100));
    }

    auto start = std::chrono::steady_clock::now(); 
    fo(i, amount){
        ll hash = compute_hash(strings[i]);
    }
    cout << "Time taken: " << since(start).count() << "ms" << endl;

    return 0;
}