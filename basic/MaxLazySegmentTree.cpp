#define vi vector<int>
const int inf = 1e9;
// vector<int> v(N, 0)
// MaxNode* tr = new MaxNode(v, 0, N); create
//tr->add() use

struct MaxNode {
    MaxNode *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    MaxNode(int lo,int hi):lo(lo),hi(hi){} // Large interva l of −in f
    MaxNode(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new MaxNode(v, lo, mid); r = new MaxNode(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
 
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new MaxNode(lo, mid); r = new MaxNode(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        }
};