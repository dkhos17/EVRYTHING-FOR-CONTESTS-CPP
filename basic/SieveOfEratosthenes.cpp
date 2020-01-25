// Prime Numbers
bool prime[100001]; // true
void SieveOfEratosthenes(int n) { 
    for (int p=2; p*p<=n; p++) { 
        if (prime[p]){
            for (int i = p*p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }
} 


const int N = 100001;
int lp[N+1];
vector<int> pr;//saves prime numbers

void prime_numbers(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}