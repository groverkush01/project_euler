#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long collatz_len(long long n){
    if(mp.find(n) != mp.end()) return mp[n];
    if(n%2) return mp[n] = (1 + collatz_len(3*n+1));
    else return mp[n] = (1 + collatz_len(n/2));
}

void solve(long long n){
    mp[1] = 1;
    long long ans = 1;
    long long max_len = 1;
    for(long long i = 1; i<n; i++){
        long long curr_len = collatz_len(i);
        if(curr_len > max_len) {
            max_len = curr_len;
            ans = i;
        }
    }

    cout << ans << endl;
}

int main(){
    solve(1000000);

    return 0;
}