#define vi vector<int>
const int inf = 1e9;
// vector<int> v(N, 0)
// MaxNode* tr = new MaxNode(v, 0, N); create
//tr->add() use

struct SumNode {
    SumNode *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0, val = 0;
    SumNode(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of −inf
    SumNode(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo)/2;
            l = new SumNode(v, lo, mid); r = new SumNode(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    ll query(ll L, ll R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += (hi - lo) * x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            ll mid = lo + (hi - lo)/2;
            l = new SumNode(lo, mid); r = new SumNode(mid, hi);
        }
        if (mset != inf)
        l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
        l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};