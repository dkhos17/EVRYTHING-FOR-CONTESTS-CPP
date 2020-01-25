int parent[MAXN];
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
// 

int p[N];
int r[N];
int find(int a) {
    if (a == p[a])
        return a;
    return p[a] = find(p[a]);
}

bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (r[b] > r[a]) {
            swap(a, b);
        }
        p[b] = a;
        if (r[a] == r[b]) {
            r[a]++;
        }
        return true;
    }
    return false;
}