/*
    Created by:- milind0110
*/
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #pragma comment(linker, "/STACK:268435456");
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define int long long
// #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e18;
const int N = 2e5 + 5;
template<typename Node,typename Update>
class segtree{
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> upd;
    vector<Node> v;
    int32_t n,l,r;
    Update val;
    Node segnull;
    Update updnull;
    inline void buildTree(int32_t start,int32_t end,int32_t node){
        if(start == end){
            tree[node] = v[start];
            return ;
        }
        int mid = (start+end) >> 1;
        buildTree(start,mid,node << 1);
        buildTree(mid + 1,end,(node << 1) + 1);
        tree[node].merge(tree[node << 1],tree[(node << 1) + 1]);
    }
    inline void apply(int32_t start,int32_t end,int32_t node,Update update) {
        update.apply(tree[node],start,end);
        if(start != end) {
            upd[node << 1].combine(update,start,end);
            lazy[node << 1] = 1;
            upd[(node << 1) + 1].combine(update,start,end);
            lazy[(node << 1) + 1] = 1;
        }
    }
    inline void updateTree(int32_t start,int32_t end,int32_t node){
        if(start > end)
            return ;
        if(lazy[node]){
            apply(start,end,node,upd[node]);
            upd[node] = updnull;
            lazy[node] = 0;
        }
        if(l > end || r < start)
            return ;
        if(l <= start && end <= r){
            apply(start,end,node,val);
            return ;
        }
        int mid = (start+end) >> 1;
        updateTree(start,mid,node << 1);
        updateTree(mid + 1,end,(node << 1) + 1);
        tree[node].merge(tree[node << 1],tree[(node << 1) + 1]);
    }
    inline Node queryTree(int32_t start,int32_t end,int32_t node){
        if(lazy[node]){
            apply(start,end,node,upd[node]);
            upd[node] = updnull;
            lazy[node] = 0;
        }
        if(l > end || r < start)
            return segnull;
        if(l <= start && end <= r){
            return tree[node];
        }
        int mid = (start+end) >> 1;
        Node sol;
        Node left = queryTree(start,mid,node << 1);
        Node right = queryTree(mid + 1,end,(node << 1) + 1);
        sol.merge(left,right);
        return sol;
    }
public:
    template<typename T>
    segtree(int32_t n,T a,bool lazyflag = false) {
        //assign default values for Node and Update
        for(int i = 0; i < n; i++) v.push_back(a[i]);
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        if(lazyflag){
            upd.resize(4 * n);
        }
        buildTree(0,n - 1,1);
    }
    inline Node query(int32_t l,int32_t r) {
        this->l = l;
        this->r = r;
        return queryTree(0,n - 1,1);
    }
    inline void update(int32_t l,int32_t r,Update val) {
        this->val = val;
        this->l = l;
        this->r = r;
        updateTree(0,n - 1,1);
    }
    inline void update(int32_t ind,Update val) {
        this->val = val;
        this->l = ind;
        this->r = ind;
        updateTree(0,n - 1,1);
    }
};
class Node{
public:
	int ans = -inf;
    int mxl = -inf,mnr = -inf;
    int mxr = -inf,mnl = -inf;
	Node() {}
	Node(int ans,int mxl,int mnr,int mxr,int mnl) {
        this->ans = ans;
        this->mxl = mxl;
        this->mnr = mnr;
        this->mxr = mxr;
        this->mnl = mnl;
	}
	void merge(Node &l,Node &r){
        ans = max({l.ans,r.ans,l.mxl + r.mnr,r.mxr + l.mnl});
        mxl = max(l.mxl,r.mxl);
        mnr = max(l.mnr,r.mnr);
        mxr = max(l.mxr,r.mxr);
        mnl = max(l.mnl,r.mnl);
        //merge left and right
	}
};
class Update{
public:
	int x;
	Update() {}
	Update(int x){
		this->x = x;
	}
	void combine(Update &parent,int32_t l,int32_t r){
		//apply a parent update to a child update
	}
	void apply(Node &node,int32_t l,int32_t r){
        node.ans = 0;
        node.mxl = x + l;
        node.mnr = - x - l;
        node.mxr = x - l;
        node.mnl = - x + l;
        	//apply an update to a range [l,r]
	}
};
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    segtree<Node,Update> st(n,vector<Node>(n));
    for(int i = 0; i < n; i++){
        st.update(i,a[i]);
    }
    cout << st.query(0,n - 1).ans << "\n";
    while(q--){
        int ind,val;
        cin >> ind >> val;
        ind--;
        st.update(ind,val);
        cout << st.query(0,n - 1).ans << "\n";
    }
}
signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int32_t t = 1;
    cin >> t;
    for(int32_t i = 1; i <= t; i++){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << " ms.\n"; 
    return 0; 
}
