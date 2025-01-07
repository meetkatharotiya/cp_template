#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// dfs

vector<ll> arr(N, 2);
void op_seive()
{ // if arr[i]==2 --> prime,
    // arr[i] --> no. of factor of i,
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

    // for (auto x : v)
    //     cout << x << " ";
}
ll SQRT(ll x)
{
    ll ans = 0;
    for (ll k = 1ll << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) < x)
            ans += k;
    }
    return ans;
}
vector<ll> z_function(string s) // pref start from that index (ex. abcabc = 000300)
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

vector<ll> KMP(string &s) // pref till that index (ex. abcabc = 000123)
{
    // m=pat.length();
    // after geting vector if v[i]==m the it start from i-2*m
    ll n = s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
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
vector<ll> Centroid(vector<vector<ll>> g, ll root)
{
    // take as lamda function
    ll n = g.size();
    vector<ll> centroid;
    vector<ll> sz(n + 1);
    function<void(ll, ll)> dfs = [&](ll v, ll prev)
    {
        sz[v] = 1;
        bool is_centroid = true;
        for (auto u : g[v])
            if (u != prev)
            {
                dfs(u, v);
                sz[v] += sz[u];
                if (sz[u] > n / 2)
                    is_centroid = false;
            }
        if (n - sz[v] > n / 2)
            is_centroid = false;
        if (is_centroid)
            centroid.push_back(v);
    };
    dfs(root, -1);
    return centroid;
}

ll FACT()
{
    fact[0] = 1;
    fact[1] = 1;
    fi(2, N)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[N - 1] = power(fact[N - 1], mod - 2);
    fir(N - 2, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * 1ll * (i + 1)) % mod;
    }
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
    ll res, mxl, mnr, mnl, mxr;
};

struct sgtree // 1 based array
{
    ll sz, n;
    vector<dat> tree;

    dat neutral_element = {0, INT_MIN, INT_MIN, INT_MIN, INT_MIN};

    dat merge(dat a, dat b) //---------> changes..
    {
        dat ans;
        ans.res = max(a.res, b.res);
        ans.res = max({ans.res, a.mxl + b.mnr, b.mxr + a.mnl});
        ans.mxl = max(a.mxl, b.mxl);
        ans.mxr = max(a.mxr, b.mxr);
        ans.mnl = max(a.mnl, b.mnl);
        ans.mnr = max(a.mnr, b.mnr);

        return ans;
    }
    dat single(ll x, ll idx) //-------------> changes..
    {
        return {0, x + idx, -x - idx, -x + idx, x - idx};
    }

    void init(ll n)
    {
        this->n = n;
        // sz = 1;
        // while (sz < n)
        //     sz *= 2;
        tree.resize(4 * n);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx == lx)
        {
            if (lx < a.size())
                tree[x] = single(a[lx], lx);
            return;
        }

        ll mid = (lx + rx) / 2;
        build(a, 2 * x, lx, mid);
        build(a, 2 * x + 1, mid + 1, rx);
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void build(vector<ll> &a)
    {
        build(a, 1ll, 1ll, n);
    }

    void set(ll ind, ll val, ll x, ll lx, ll rx)
    {
        if (rx == lx)
        {

            tree[x] = single(val, lx);
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

        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void set(ll ind, ll val)
    {
        set(ind, val, 1ll, 1ll, n);
    }

    dat calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (l <= lx && rx <= r)
            return tree[x];

        if (lx > r || rx < l)
            return neutral_element;

        ll mid = (lx + rx) / 2;
        dat left = calc(l, r, 2 * x, lx, mid);
        dat right = calc(l, r, 2 * x + 1, mid + 1, rx);
        return merge(left, right);
    }

    dat calc(ll l, ll r)
    {
        return calc(l, r, 1, 1, n);
    }
    ll find_mx(ll l, ll r, ll val, ll x, ll lx, ll rx) // idx_ of elem >val
    {
        if (lx > r || rx < l || tree[x].mx < val)
            return -1;

        if (lx == rx)
            return rx;
        ll mid = (lx + rx) / 2;
        ll left = find_mx(l, r, val, 2 * x, lx, mid);
        if (left != -1)
            return left;
        return find_mx(l, r, val, 2 * x + 1, mid + 1, rx);
    }
    ll find_mx(ll l, ll r, ll x)
    {
        return find_mx(l, r, x, 1, 1, n);
    }
    ll find_mn(ll l, ll r, ll val, ll x, ll lx, ll rx) // idx of elem  < val
    {
        if (lx > r || rx < l || tree[x].mn >= val)
            return -1;

        if (lx == rx)
            return rx;
        ll mid = (lx + rx) / 2;
        ll left = find_mn(l, r, val, 2 * x, lx, mid);
        if (left != -1)
            return left;
        return find_mn(l, r, val, 2 * x + 1, mid + 1, rx);
    }
    ll find_mn(ll l, ll r, ll x)
    {
        return find_mn(l, r, x, 1, 1, n);
    }
};

// Single hash
class HashString
{
    long long p = 31, m = 1e9 + 9;
    vector<long long> h, ppow;

public:
    HashString(string &s)
    {
        int n = s.length();
        h.resize(n + 1, 0);
        ppow.resize(n + 1, 0);
        ppow[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            ppow[i] = (ppow[i - 1] * p) % m;
            h[i] = ((h[i - 1] * p) % m + (s[i - 1] - 'a' + 1)) % m;
        }
    }

    // assume zero based indexing
    long long getSubHash(int l, int r)
    {
        long long ans = (h[r + 1] - (h[l] * ppow[r - l + 1]) % m + m) % m;
        return ans;
    }

    long long getInstantHash(string &s)
    {
        long long ans = 0;

        for (auto &c : s)
        {
            ans = (ans * p) % m;
            ans = (ans + (c - 'a' + 1)) % m;
        }

        return ans;
    }
};

// double hash
class HashString
{
    long long p = 37, m = 1000000021;
    long long p1 = 31, m1 = 1000000241;
    vector<long long> h, ppow;
    vector<long long> h1, ppow1;

public:
    HashString(string &s)
    {
        int n = s.length();
        h.resize(n + 1, 0);
        h1.resize(n + 1, 0);
        ppow.resize(n + 1, 0);
        ppow1.resize(n + 1, 0);
        ppow[0] = 1;
        ppow1[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            ppow[i] = (ppow[i - 1] * p) % m;
            ppow1[i] = (ppow1[i - 1] * p1) % m1;
            h[i] = ((h[i - 1] * p) % m + (s[i - 1] - 'a' + 1)) % m;
            h1[i] = ((h1[i - 1] * p1) % m1 + (s[i - 1] - 'a' + 1)) % m1;
        }
    }

    // assume zero based indexing
    pair<long long, long long> getSubHash(int l, int r)
    {
        long long ans = (h[r + 1] - (h[l] * ppow[r - l + 1]) % m + m) % m;
        long long ans1 = (h1[r + 1] - (h1[l] * ppow1[r - l + 1]) % m1 + m1) % m1;
        return {ans, ans1};
    }

    pair<long long, long long> getInstantHash(string &s)
    {
        long long ans = 0;
        long long ans1 = 0;

        for (auto &c : s)
        {
            ans = (ans * p) % m;
            ans1 = (ans1 * p1) % m1;
            ans = (ans + (c - 'a' + 1)) % m;
            ans1 = (ans1 + (c - 'a' + 1)) % m1;
        }

        return {ans, ans1};
    }
};
int main()
{

    return 0;
}
