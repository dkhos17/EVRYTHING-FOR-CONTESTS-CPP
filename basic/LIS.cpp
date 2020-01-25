#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t , n , a[N] , dp[N] , p[N];

void LIS(){
    dp[0] = 1; 
    for (int i = 1; i < n; i++ ){ 
        dp[i] = 1; 
        p[i] = i;
        for (int j = 0; j < i; j++ ){
            if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;  
                p[i] = j;
            }
        } 
    }
}

void printLIS(){
    int maximum = 0;
    int ind = -1;
    for(int i = 0 ; i < n; i++){
        if(dp[i] > maximum){
            maximum = dp[i];
            ind = i;
        }
    }
    vector<int> res;
    res.push_back(a[ind]);
    while(p[ind] != ind){
        res.push_back(a[p[ind]]);
        ind = p[ind];
    }
    for(int i = res.size() - 1; i >= 0 ; i--){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        LIS();
        int maximum = 0;
        for(int i = 0 ; i < n; i++){
            maximum = max(maximum , dp[i]);
        }
        cout<<maximum<<endl;
        printLIS();
    }

    return 0;
}