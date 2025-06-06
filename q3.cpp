#include <bits/stdc++.h>
using namespace std;

int solve(long long n){
    int ans = -1;
    long long iter = sqrtl(n);
    for(long long i = 2; i <= iter; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            ans = i;
        }
    }
    return ans;
}

int main(){
    cout << solve(13195) << endl;
    cout << solve(600851475143LL) << endl;

    return 0;
}