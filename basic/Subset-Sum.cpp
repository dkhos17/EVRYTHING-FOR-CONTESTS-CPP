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
const int  N = 1e5 + 7;
int t , n ,  sum ,a[N] ;

bool solve(){
    bool dp[n+1][sum+1]; 
    for (int i = 0; i <= n; i++)  dp[i][0] = true; 
    for (int i = 1; i <= sum; i++) dp[0][i] = false; 

    for (int i = 1; i <= n; i++){ 
        for (int j = 1; j <= sum; j++){ 
            if(j < a[i-1]) dp[i][j] = dp[i-1][j]; 
            if (j >= a[i-1]) dp[i][j] = dp[i-1][j] || dp[i - 1][j-a[i-1]]; 
        } 
    }
    return dp[n][sum];
}

//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);  cin.tie(0);
    cin>>n>>sum;
    for (int i = 0; i < n; i++){ 
        cin>>a[i];
    }
    if(solve()){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;

    return 0;
}