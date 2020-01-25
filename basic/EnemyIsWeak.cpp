#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
int powers[MAXN];   //powers of army
int tree[MAXN];     //fenwick tree
int indexs[MAXN];   //sorted indexs
int greatersLeft,lessLeft,lessRight, allLess;

//cmpr function to sort indexs - descents
bool cmpr(int i, int j){
    return powers[i] > powers[j];
}

//fenwick getValue
int get(int idx){
    int res = 0;
    while(idx){
        res += tree[idx];
        idx -= idx&-idx;
    }
    return res;
}

//fenwick update
void update(int idx, int maxval){
    while (idx <= maxval){
        tree[idx]++;
        idx += idx&-idx;
    }
}

int main(){
    int n;
    scanf("%d",&n);                     //არმიის რაოდენობა
    for(int i = 1; i <= n; i++){
        scanf("%d",&powers[i]);         //მებრძოლთა ძალები
        indexs[i] = i;                  //შევინახოთ ინდექსები 
    } 

    int* start = indexs + 1;            //მასივის დასაწყისი(მიმთითებელი)start = begin()+1, რადგან ინდექსების ათვლა დავიწყეთ 1-დან
    int* end = indexs + n+1;            //შესაბამისად end იქნება -> end()+1
    sort(start, end, cmpr);             //დავასორტიროთ ინდექსები მებრძოლთა ძალების კლებოადობის მიხედვით,ამას გააკეთებს cmpr ფუნქცია
    
    long long result = 0;                       //პასუხი შეიძლება იყოს ლონგ ლონგი
    for(int i = 1; i <= n; i++){
        greatersLeft = get(indexs[i]-1);        //ფენვიკის ხე დააბრუნებს რაოდენობას თუ რამდენი ელემენტია ამ ინდექსის მარცხნივ მასზე მეტი.
        lessLeft = indexs[i]-greatersLeft-1;    //თუ ვიცით i-ურისთვის რამდენია მარცხნივ მასზე მეტი,მაშინ ასევე ვიცით თუ რამდენია მარცხნივ მასზე ნაკლები,
        allLess = n-i;                          //ასევე სორტირებული მასივისთვის i-ურისათვის ვიცით რამდენია სულ მასზე ნაკლები (n-i),
        lessRight = allLess-lessLeft;           //შესაბამისად ვიცით თუ რამდენი იქნება მასზე ნაკლები მარჯვნივ.
        result += 1LL*greatersLeft*lessRight;   //i-იური ელემეტისთვის, სამეულების რაოდენობა,სადაც ის მე-2 წევრს წარმოადგენს.
        update(indexs[i], n);                   //განვაახლოთ ფენვიკის ხე.
    }

    printf("%lld\n", result); //დავბეჭდოთ პასუხი,რომელიცაა long long/%I64d
}