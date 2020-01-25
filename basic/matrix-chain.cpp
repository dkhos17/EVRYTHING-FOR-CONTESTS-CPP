#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int P[N+1]; //dimensions of matrix
int M[N+1][N+1]; // cost
int S[N+1][N+1]; // solution


void matrix_chain(){
    for(int l = 2; l <= N; l++){ // chain length
        for(int i = 1 ; i <= N - l + 1; i++){
            int j = i + l - 1;
            M[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++){
                int q = M[i][k] + M[k + 1][j] + P[i-1] * P[k] * P[j];
                if(q < M[i][j]){
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void print_optimal(int i , int j){
    if(i == j){
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    print_optimal(i , S[i][j]);
    print_optimal(S[i][j] + 1 , j);
    cout<<")";
}


//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i = 0; i <= n; i++){
        cin>>P[i];
    }
    matrix_chain();
    print_optimal(1 , n);
    cout<<endl;
    cout<<M[1][n]<<endl;

    return 0;
}