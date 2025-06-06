#include <bits/stdc++.h>
using namespace std;

long long solve(int n){
    long long sq_sum = (n*1LL*(n+1)*(2*n+1))/6;
    long long sum_sq = ((n*(n+1))/2)*1LL*((n*(n+1))/2);

    return sum_sq - sq_sum;
}

int main(){
    cout << solve(10) << endl;
    cout << solve(100) << endl;

    return 0;
}