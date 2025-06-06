#include <bits/stdc++.h>
using namespace std;

long long solve(int n){
    long long sum = 0;
    for(int i = 1; i<n; i++){
        if((i%3 == 0) || (i%5 == 0)) sum += i;
    }
    return sum;
}

int main(){
    cout << solve(10) << endl;
    cout << solve(1000) << endl;

    return 0;
}