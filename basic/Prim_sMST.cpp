#include <bits/stdc++.h>

using namespace std;

//Prim's Algorithm
int PrimsMST(vector<vector<int>>& edges){
    priority_queue < pair<int, pair<int,int> > > curr_pq;
    map<int, priority_queue < pair<int, pair<int,int> > > > ways;
    int mx,my,mw = INT_MAX;
    for(vector<int> e : edges){
        int x = e[0], y = e[1], w = e[2];
        ways[x].push(make_pair(-w,make_pair(x,y)));
        ways[y].push(make_pair(-w,make_pair(y,x)));
        if(mw > w){
            mx = x;
            my = y;
            mw = w;
        }
    }

    set<int> been;
    pair <int, pair <int,int> > min = make_pair(mw,make_pair(mx,my));
    int mst = min.first;
    been.insert(min.second.first);
    been.insert(min.second.second);
    while(!0){
        if(!ways[min.second.first].empty()){
            curr_pq.push(ways[min.second.first].top());
            ways[min.second.first].pop();
        }

        if(!ways[min.second.second].empty()){
            curr_pq.push(ways[min.second.second].top());
            ways[min.second.second].pop();
        }

        if(curr_pq.empty())break;
        min = curr_pq.top(); curr_pq.pop();

        if(been.count(min.second.first) && been.count(min.second.second))continue;
        mst += -min.first;
        been.insert(min.second.first);
        been.insert(min.second.second);
    }
    return mst;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(k);
    for(int i = 0; i < k; i++){
        int x,y,w;
        edges[i].resize(3);
        cin >> x >> y >> w;
        edges[i][0] = x;
        edges[i][1] = y;
        edges[i][2] = w;
    }
    cout << PrimsMST(edges) << endl;
    return 0;
}