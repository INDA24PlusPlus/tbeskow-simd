#include <bits/stdc++.h>
#include <random>
#include <immintrin.h>

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
vector<__m256i> rvals_simd;



ll compute_hash_simd(string &s){
    __m256i hash_simd = _mm256_setzero_si256();
    uint64_t* vals = new uint64_t[s.size()];
    for(size_t i = 0; i < s.size(); i++) {
        vals[i] = (uint64_t)s[i];
    }
    
    for(size_t i = 0; i < s.size(); i += 4) {
        __m256i chars_a = _mm256_loadu_si256((__m256i*)&vals[i]);

        __m256i mul_simd = _mm256_mul_epi32(chars_a, rvals_simd[i/4]);
        hash_simd = _mm256_xor_si256(hash_simd, mul_simd);
    }
    uint64_t* res = (uint64_t*)&hash_simd;
    return res[0]^res[1]^res[2]^res[3];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll amount;
    cin >> amount;
    deb(amount);
    
    vector<string> strings(amount);
    ll max_length = 0;
    fo(i, amount){
        cin >> strings[i];
        max_length = max(max_length, (ll)strings[i].size());
    }
    mt19937_64 rng(1337);
    fo(i, max_length){
        rvals.pb(rng()%((1ll<<31ll)/100ll));
    }
    auto start = std::chrono::steady_clock::now();
    for(ll i = 0; i<max_length; i+=4) rvals_simd.pb(_mm256_loadu_si256((__m256i*)&rvals[i]));

    fo(i, amount){
        while(strings[i].size()%4!=0) strings[i]+=(char)0;
        ll hash = compute_hash_simd(strings[i]);
    }
    cout << "Time taken: " << since(start).count() << "ms" << endl;

    return 0;
}