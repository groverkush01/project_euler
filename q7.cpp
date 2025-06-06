#include <bits/stdc++.h>
using namespace std;

const int N = 1000*1000;
vector<bool> sieve(N+1, true);

void create_sieve(){
    sieve[0] =false;
    sieve[1] =false;

    for(int i = 2; i<=sqrt(N); i++){
        if(sieve[i]){
            for(long long j = i*1LL*i; j <= N; j+=i) sieve[j] = false;
        }
    }
}

long long solve(int n){
    int curr = 0;
    for(int i =0; i<=N; i++){
        if(sieve[i]) curr++;
        if(curr == n) return i;
    }
    return -1;
}

int main(){
    create_sieve();
    cout << solve(6) << endl;
    cout << solve(10001) << endl;

    return 0;
}