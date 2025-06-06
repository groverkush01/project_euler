#include <bits/stdc++.h>
using namespace std;

long long solve(int n){
    int a = 1;
    int b = 2;
    long long ans = 0;
    while(a <= n){
        if(a%2 == 0) ans += a;
        int c = a + b;
        a = b;
        b = c;
    }
    return ans;
}

int main(){
    cout << solve(4*1000*1000) << endl;

    return 0;
}