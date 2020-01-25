#include <bits/stdc++.h>
using namespace std;

const int m = 101; //X.length + 1
const int n = 101; //Y.length + 1

int C[m][n];
string X , Y;


void LCS(){
    for(int i = 1; i <= X.size(); i++){
        for(int j = 1; j <= Y.size(); j++){
            if (X[i-1] == Y[j-1]) {
                C[i][j] = C[i-1][j-1]+1;
            }else if (C[i-1][j] >= C[i][j-1]) {
                C[i][j] = C[i-1][j];
            }else C[i][j] = C[i][j-1];
        }
    }
}

void print_LCS( int i , int j){
    if(i == 0 || j == 0) return;

    if(X[i-1] == Y[j-1]){
        print_LCS( i-1 , j - 1);
        cout<<X[i-1];
    }else if(C[i][j] == C[i-1][j]){
        print_LCS( i-1 , j );
    }else print_LCS( i , j - 1);
    
}



//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);
    cin>>X>>Y;
    LCS();
    cout<<C[X.size()][Y.size()]<<endl;
    print_LCS(X.size() , Y.size());
    cout<<endl;

    return 0;
}