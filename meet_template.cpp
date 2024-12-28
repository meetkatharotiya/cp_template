#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target("popcnt")
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...) 8
#endif

typedef long long int ll;
typedef long double lld;
#define pb push_back

#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define fk(l, r) for (ll k = l; k < r; k++)
#define fir(r, l) for (ll i = r; i >= l; i--)
#define fjr(r, l) for (ll j = r; j >= l; j--)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll inf = 1e18;
const ll N = 2e6 + 5;
const lld PI = 3.14159265358979323846;

/*------------------------------------------------------------------------------------------------------------------------------------------*/

void init()
{
}

void solve()
{
}

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	init();
	ll t = 1;
	cin >> t;

	for (ll tc = 1; tc <= t; tc++)
	{

		debug(tc);
		solve();
	}
	return 0;
}
