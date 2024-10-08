#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...) 8
#endif
#define ll long long int
#define lld long double
#define pb push_back
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define eb emplace_back
#define INF 1e18
#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define fk(l, r) for (ll k = l; k < r; k++)
#define fir(r, l) for (ll i = r; i >= l; i--)
#define fjr(r, l) for (ll j = r; j >= l; j--)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ff first
#define ss second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
ll lcm(ll a, ll b) { return ((a * b) / __gcd(a, b)); }
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

const ll mod = 1e18;
const ll mod2 = 998244353;
const ll inf = 1e9;
const ll N = 2e5 + 5;

vector<ll> arr(N, 1);
// void set_sieve(){arr[0]=0;arr[1]=0;for(ll i=2;i*i <N;i++){if(arr[i]==1){for(ll j=i*2;j<N;j+=i){arr[j]=0;}}}}
// void set_fact(){arr[0]=1;for(ll i=1;i<N;i++){arr[i]=(i*arr[i-1])%mod;}}
// vector<ll>prime;void prime_vec(){fi(0,N+1){if(arr[i]==1){prime.pb(i);}}}

/*------------------------------------------------------------------------------------------------------------------------------------------*/

void K_Length_cycle()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> g(n + 1);
    fi(0, m)
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll> vis(n + 1, 0), par(n + 1, 0);
    bool flag = 0;
    auto dfs = [&](ll v, ll p, auto &&dfs) -> void
    {
        vis[v] = 1;
        par[v] = p;

        for (auto u : g[v])
        {
            if (!vis[u] && !flag)
            {
                par[u] = v;

                dfs(u, v, dfs);
            }
            else if (vis[u] == 1)
            {
                ll cycle = 0;
                for (ll i = v;; i = par[i])
                {
                    cycle++;
                    if (i == u)
                        break;
                }
                if (cycle > k)
                {
                    cout << cycle << endl;
                    vector<ll> ans;
                    for (ll i = v;; i = par[i])
                    {
                        ans.pb(i);
                        if (i == u)
                            break;
                    }
                    for (auto i : ans)
                        cout << i << " ";
                    cout << endl;
                    flag = 1;
                }
            }
        }
        vis[v] = 2;
    };

    dfs(1, 1, dfs);
    debug(par);
}

void MAX_DIA()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<vector<array<ll, 2>>> g(n + 1);
    fi(0, n - 1)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        ans += 2 * w;
    }
    ll dia = 0;
    auto dfs = [&](ll v, ll par, auto &&dfs) -> ll
    {
        ll mxh = 0, mxh2 = 0;

        for (auto it : g[v])
        {
            ll u = it[0], w = it[1];
            if (u == par)
                continue;

            ll h = w + dfs(u, v, dfs);
            if (h > mxh)
            {
                mxh2 = mxh;
                mxh = h;
            }
            else if (h > mxh2)
                mxh2 = h;
        }
        dia = max(dia, mxh + mxh2);
        return mxh;
    };
    ll h = dfs(1, -1, dfs);
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> g[n + 1];

    fi(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll> level(n + 1, 0);
    vector<ll> subtree(n + 1, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(18, 0));

    function<void(ll, ll)> dfs = [&](ll v, ll par) -> void
    {
        dp[v][0] = par;
        for (ll i = 1; i <= 17; i++)
        {
            dp[v][i] = dp[dp[v][i - 1]][i - 1];
        }

        level[v] = level[par] + 1;

        for (auto u : g[v])
        {
            if (u != par)
            {
                dfs(u, v);
            }
        }
    };
    dfs(1, 0);
    auto kthpar = [&](ll node, ll k)
    {
        ll cnt = 0;
        while (k)
        {
            if (k & 1)
            {
                node = dp[node][cnt];
            }
            cnt++;
            k /= 2;
        }
        return node;
    };

    auto LCA = [&](ll a, ll b)
    {
        if (level[a] > level[b]) // a must be upper than b
        {
            swap(a, b);
        }
        ll k = level[b] - level[a]; //  move b k step up
        b = kthpar(b, k);
        if (a == b)
            return a;
        for (ll i = 16; i >= 0; i--)
        {
            if (dp[a][i] != dp[b][i])
            {
                // ith par are diff than move both to that level
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    };
}

int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    ll t = 1;
    // cin >> t;

    for (ll tc = 1; tc <= t; tc++)
    {

        debug(tc);

        solve();
    }
    return 0;
}
