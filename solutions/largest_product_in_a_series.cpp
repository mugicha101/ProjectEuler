#include <bits/stdc++.h>

using namespace std;
#define INPUT true

typedef long long ll;
typedef long double ld;

#define ssort(x) sort(x.begin(), x.end())
#define flip(x) reverse(x.begin(), x.end())
#define iseq(x) iota(x.begin(), x.end(), 0)

#define forn(i,n) for (int i = 0; i < n; ++i)
#define rforn(i,n) for (int i = n-1; i >= 0; --i)
#define fora(a) for(auto x : a)
#define forr(a) for(auto& x : a)

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
#define len(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define getx(a) a.first
#define gety(a) a.second
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

bool prime(ll a) { if (a==1) return 0; ll cap = sqrt(a); for (int i=2;i<=cap;++i) if (a%i==0) return 0; return 1; }

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>{}(p.first) ^ hash<T2>{}(p.second); }
};

typedef vector<vector<int>> AdjList;

int main(int argc, char **argv) {
    // env setup
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);
    #if INPUT
    freopen("./input.txt","r",stdin);
    #endif
    
    string num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    ll val = 1;
    ll res = 0;
    const int window = 13;
    int zeros = 0;
    for (int i = 0; i < window-1; ++i) {
        if (num[i] == '0') ++zeros;
        else val *= num[i] - '0';
    }
    for (int i = window-1; i <= num.size(); ++i) {
        if (num[i] == '0') ++zeros;
        else val *= num[i] - '0';
        if (zeros == 0) res = max(res, val);
        if (num[i-window+1] == '0') --zeros;
        else val /= num[i-window+1] - '0';
    }
    cout << res << endl;
}