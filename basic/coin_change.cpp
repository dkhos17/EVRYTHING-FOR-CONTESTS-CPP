#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int t, n , m , dp[N][N];

void coin_change(vector <int>& v){
    for (int i = 0; i < m; i++) {
        dp[0][i] = 1; 
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 0; j < m ; j++){
            dp[i][j] = 0;            
            if(i >= v[j]) dp[i][j] += dp[i - v[j]][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
        }
    }
}

int main() {
	cin>>t;
	while(t--){
	   cin>>m;
	   vector <int> v(m);
	   for(int i = 0; i < m; i++){
	       cin>>v[i]; 
	   }
	   cin>>n;
	   coin_change(v);
	   cout<<dp[n][m-1]<<endl;
	}
	
	return 0;
}