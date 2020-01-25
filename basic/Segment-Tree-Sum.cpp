struct tree{
    tree *l,*r;
    int sum;
    tree(){
        l=NULL; r=NULL; sum=0;
    }
};
void update(tree* &t, int val, int lf,int rg, int i){
    if(t == NULL) t = new tree();
    t->sum += val;
    if(rg - lf == 1) return;
    if(i < (lf+rg)/2) update(t->l, val, lf, (lf+rg) / 2, i);
    else update(t->r, val, (lf+rg) / 2,rg, i);

}

int get(tree* &t,int lf,int rg , int a , int s){
    if(t == NULL) return 0;
    if(lf >= a && rg-1 <= s) return t->sum;
    if(lf > s || rg <= a) return 0;
    return get(t->l, lf, (lf+rg)/2 , a, s) + get(t->r, (lf+rg)/2, rg , a, s);
}