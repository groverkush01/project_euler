#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long ans = 0;
	// log10(10^(n-1)) = log10(i^n)
	// n-1 = n*log10(i)
	// n = (1/(1-log10(i)))
	for(int i = 1; i<10; i++){
		ans += floor(1/(1-log10(i)));
	}
	cout << ans << endl;
}

int main(){
	solve();

	return 0;
}