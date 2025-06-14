#include <bits/stdc++.h>
using namespace std;

int calc_dig_sum(int x, int n){
    int sum = 0;
    while(x){
        sum += pow(x%10, n);
        x /= 10;
    }
    return sum;
}

void solve(int n){
    long long ans = 0;
    for(int i = 10; i < pow(10, n+1); i++){
        if(i == calc_dig_sum(i, n)) ans += i;
    }
    cout << ans << endl;
}

int main() {
    solve(4);
    solve(5);

    return 0;
}