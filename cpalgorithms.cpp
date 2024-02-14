#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// dfs
const ll N = 1e6 + 5;
bool vis[N];
vector<ll> g[N];
ll parent[N][18];
void dfs(int v, ll par)
{
    vis[v] = 1;
    parent[v][0] = par;
    for (int i = 1; i < 18; i++)
        parent[v][i] = parent[parent[v][i - 1]][i - 1]; // use for binary up lifting
    for (auto u : g[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }

    /*
    for kth parent of node
    cin>>node>>k;
    int cnt=0;
    while(k){
        if(k&1){
            node=parent[node][cnt];
        }
        cnt++;
        k=k>>1;
    }
    cout<<node<<endl;
    */
}
vector<ll> arr(N, 1);
void op_seive()
{ // if arr[i]==2-->prime,
    // arr[i]-->no. of factor of i,
    // if arr[i] is odd then it is perfect square
    arr[0] = 0;
    arr[1] = 1;
    for (ll i = 2; i * i <= N; i++)
    {

        for (ll j = i * i; j <= N; j += i)
        {
            if (j == i * i)
                arr[j]++;
            else
                arr[j] += 2;
        }
    }
}

// prime number
bool isprime(ll a)
{
    if (a != 2 && a % 2 == 0 || a < 2)
        return 0;
    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return 0;
    return 1;
}

// big powers
ll binaryexp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * 1ll * a;
        }
        a = a * a * 1ll;
        b >>= 1;
    }
    return ans;
}
// multiplication in binarry
ll binarymul(ll a, ll b)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans + a;
        }
        a = a + a;
        b >>= 1;
    }
    return ans;
}
// prime factors
ll primefactor(ll n)
{
    vector<ll> v;
    ll factor = 1;
    for (ll i = 2; i * i <= n; ++i)
    {
        ll c = 0;
        while (n % i == 0)
        {

            v.push_back(i);
            n /= i;
            c++;
        }
        factor *= (c + 1);
    }
    if (n > 1)
    {
        v.push_back(n);
        factor *= 2;
    }

    for (auto x : v)
        cout << x << " ";
}
ll SQRT(ll x)
{
    ll ans = 0;
    for (ll k = 1 << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) < x)
            ans += k;
    }
    return ans;
}
vector<ll> z_function(string s)
{
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
// MEX elemnt
ll MEX(vector<ll> &a)
{
    ll n = a.size();
    unordered_set<ll> hash(a.begin(), a.end());
    for (ll i = 0; i <= n + 1; i++)
    {
        if (hash.find(i) == hash.end())
        {
            return i;
        }
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
// ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
// ll power(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
// ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// ll mminvprime(ll a, ll b) {return power(a, b - 2, b);}
// bool revsort(ll a, ll b) {return a > b;}
// ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
// void google(int t) {cout << "Case #" << t << ": ";}
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
// ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
// ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
// unique path of grid is (m+n-2)C(n-1) or (m+n-2)C(m-1) in O(1)
/*---------------------------------------------------------------------------------------------------------------------------*/
long long ncr(long long n, ll r, ll p)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * inv(fac[r], p) % p * inv(fac[n - r], p) % p) % p;
}

struct DSU
{
    ll n;
    vector<ll> sz, par;

    DSU(ll n) : n(n)
    {
        sz.assign(n + 1, 1);
        par.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
    }

    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    bool Union(ll a, ll b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        sz[b] = 0;
        return true;
    }
};

struct dat
{
    ll g;
};

struct sgtree // 1 based array
{
    ll sz;
    vector<dat> v;

    dat neutral_element = {0};

    dat merge(dat a, dat b) //---------> changes..
    {
        dat ans = {__gcd(a.g, b.g)};
        return ans;
    }

    dat single(ll x) //-------------> changes..
    {
        return {x, 1};
    }

    void init(ll n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        v.resize(2 * sz);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx == lx)
        {
            if (lx <= a.size())
                v[x] = single(a[lx]);
            return;
        }

        ll mid = (lx + rx) / 2;
        build(a, 2 * x, lx, mid);
        build(a, 2 * x + 1, mid + 1, rx);
        v[x] = merge(v[2 * x], v[2 * x + 1]);
    }

    void build(vector<ll> &a)
    {
        build(a, 1ll, 1ll, sz);
    }

    void set(ll ind, ll val, ll x, ll lx, ll rx)
    {
        if (rx == lx)
        {
            v[x] = single(val);
            return;
        }

        int mid = (lx + rx) / 2;

        if (ind <= mid)
        {
            set(ind, val, 2 * x, lx, mid);
        }
        else
        {
            set(ind, val, 2 * x + 1, mid + 1, rx);
        }

        v[x] = merge(v[2 * x], v[2 * x + 1]);
    }

    void set(ll ind, ll val)
    {
        set(ind, val, 1ll, 1ll, sz);
    }

    dat calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (l <= lx && rx <= r)
            return v[x];

        if (lx > r || rx < l)
            return neutral_element;

        ll mid = (lx + rx) / 2;
        dat left = calc(l, r, 2 * x, lx, mid);
        dat right = calc(l, r, 2 * x + 1, mid + 1, rx);
        return merge(left, right);
    }

    dat calc(ll l, ll r)
    {
        return calc(l, r, 1, 1, sz);
    }
};

int main()
{

    cout << binarymul(2, 4) << endl;
    return 0;
}