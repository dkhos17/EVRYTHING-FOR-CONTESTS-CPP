#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int partition(int p , int r){
    int x = A[r];
    int i = p-1;
    for (int j = p; j < r; j++) { 
        if (A[j] < x) {
            i++;
            swap(A[i] , A[j]);
        }
    } 
    swap(A[i+1] , A[r]);
    return i+1;
}

int randomized_partition(int p , int r){
    int i = rand() % (r - p + 1) + p;
    swap(A[i] , A[r]);
    return partition(p , r);
}

int randomized_select(int p , int r , int i){
    if (p == r) return A[p];
    int q = randomized_partition(p , r);
    int k = q - p + 1;
    if (i == k) return A[q];

    if(i < k){
        return randomized_select( p , q-1 , i);
    }
    return randomized_select(q+1, r , i - k);
}


void quicksort(int p , int r){
    if (p >= r) return;
    int q = randomized_partition(p , r);
    quicksort(p , q-1);
    quicksort(q+1, r);
}

int main(){
    int n , i;
    cin>>n>>i;
    A.resize(n);
    for(int j = 0; j < n ; j++){
        cin>>A[j];
    }
    quicksort(0 , n-1);
    for(int j = 0; j < n ; j++){
        cout<<A[j]<<" ";
    }
    cout<<endl;
    cout<<randomized_select(0 , n-1 , i)<<endl;
    return 0;
}
