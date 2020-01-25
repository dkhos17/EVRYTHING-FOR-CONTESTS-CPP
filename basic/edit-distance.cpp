#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int dp[N][N];

void edit_dist(string X, string Y){
    int m = X.size();
    int n = Y.size();
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) {
                dp[i][j] = j; 
            } else if (j == 0){
                dp[i][j] = i;
            }else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1]; 
            }else dp[i][j] = 1 + min(dp[i][j-1],  min (dp[i-1][j], dp[i-1][j-1]) );
        } 
    }
}


//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);
    string X, Y;
    cin>>X>>Y;
    edit_dist(X, Y);
    cout<<dp[X.size()][Y.size()]<<endl;

    return 0;

}