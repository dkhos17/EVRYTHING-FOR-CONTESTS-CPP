#include<bits/stdc++.h>
using namespace std;

int fiba(long long a, long long b, int c, long long& n){
    if(a + b > n) return c;
    return fiba(b,a+b,c+1, n);
}

int main(){
    ofstream f("test.txt");
    srand(0);
    if(!f.is_open()) cout << "file not found" << endl;
    for(long long i = 0; i < 100; i++){
        long long n = rand();
        f << n << endl << fiba(1,2,0,n) << endl;
    }
    return 0;
}