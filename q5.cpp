#include <bits/stdc++.h>
using namespace std;

long long solve(int n){
    long long ans = 1;
    for(long long i = 2; i<=n; i++){
        ans = ((ans*i)/__gcd(ans, i));
    }
    return ans;
}

int main(){
    cout << solve(10) << endl;
    cout << solve(20) << endl;

    return 0;
}