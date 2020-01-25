#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 11111;
ll greed[N] , optimal[N];

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 1 ; i < 10101; i++){
        vector<int> usable;
        int m = 1;
        for(int j = 0 ; j < n && a[j] <= i; j++){
            usable.pb(a[j]);
            m = max(m , a[j]);
        }
        greed[i] = greed[i-m] + 1;

        optimal[i] = i;
        for(int j = 0 ; j < usable.size() ; j++){
            ll used = 1 + optimal[i - a[j]];
            optimal[i] = min(optimal[i] , used);
        }
        
        if(greed[i] != optimal[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
