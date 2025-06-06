#include <bits/stdc++.h>
using namespace std;

long long combination(long long n, long long r){
    if(r == 0) return 1;
    if(r == 1) return n;
    return ((n*combination(n-1, r-1))/r);
}

void solve(int n){
    cout << combination(2*n, n) <<endl;
}

int main(){
    solve(2);
    solve(20);

    return 0;
}