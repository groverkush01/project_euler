#include <bits/stdc++.h>
using namespace std;

int cnt_divisors(long long n){
    int cnt = 0;
    for(long long i = 1; i<=sqrt(n); i++){
        if(n%i == 0) cnt += 2;
        if(i*i == n) cnt--;
    }
    return cnt;
}

long long solve(int n){
    for(int x = 1;; x++){
        if(x%2){
            if(cnt_divisors(x)*cnt_divisors((x+1)/2) >= n) return (x*(x+1))/2;
        } else {
            if(cnt_divisors(x/2)*cnt_divisors(x+1) >= n) return (x*(x+1))/2;
        }
    }
}

int main(){
    cout << solve(5) << endl;
    cout << solve(500) << endl;

    return 0;
}