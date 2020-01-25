#include <bits/stdc++.h>
using namespace std;

struct Tree {
    typedef int T;
    static constexpr T unit = 0;//INT_MIN;
    T f(T a, T b) {
        // return max(a,b);
        return __builtin_popcount(a) + __builtin_popcount(b);
    }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos*2], s[pos*2+1]);
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;
        for(b += n, e += n; b < e; b /= 2, e/= 2) {
            if(b % 2) ra = f(ra, s[b++]);
            if(e % 2) rb = f(s[--e], rb);
        }
        for(auto x : s) cout << x << " ";
        cout << endl;
        return f(ra, rb);
    }
};


int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);  
    int n,q;
    cin >> n >> q;
    Tree Tr(16);
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            int pos;
            cin >> pos;
            int curr = Tr.query(pos,pos);
            cout << curr << endl;
            Tr.update(pos, 2*curr+1);
        }else if(x == 2){
            int pos;
            cin >> pos;
            int curr = Tr.query(pos,pos);
            cout << curr << endl;
            Tr.update(pos, curr/2);
        }else{
            int l,r;
            cin >> l >> r;
            cout << Tr.query(l,r) << endl;
        }
    }
    return 0;
}