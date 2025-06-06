/*
a + b + c = 1000
a^2 + b^2 = c^2, find abc?
a = m^2 - n^2, b = 2mn, c = m^2 + n^2
a + b + c = 2m(m+n) = 1000
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    int x = 1;
    int y = 0;
    for(x = 1; x < n/2; x++){
        if((n/2)%x) continue;
        y = ((n/2)/x) - x;
        if(y > 0 && y < x) break;
    }
    // cout << "x = " << x << ", y = " << y << endl;
    // cout << "a = " << x*x - y*y << ", b = " << 2*x*y << ", c = " << x*x + y*y << endl;
    int a = x*x-y*y;
    int b = 2*x*y;
    int c = x*x+y*y;
    cout << a*b*c << endl;
}

int main(){
    solve(12);
    solve(1000);

    return 0;
}