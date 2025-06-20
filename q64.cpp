#include <bits/stdc++.h>
using namespace std;

// arr[4] --> arr[0] = numerator(irrational), arr[1] = numerator(rational), arr[2] = denominator(num), arr[3] = denominator(den);

void solve(int n){
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(((int)sqrt(i))*((int)sqrt(i)) == i) continue;
		vector<int> num = {i, -((int)sqrt(i)), 1, 1};
		map<vector<int>, int> mp;
		int iter = 0;
		while(true) {
			if(mp.find(num) != mp.end()) {
				if((iter - mp[num])%2) ans++;
				break;
			}
			mp[num] = iter;
			// reciprocal = (den_num/den_den)/(num(irr)+num(rat))
			// reciprocal = (num(irr) - num(rat))/(den_den*(num(irr)  num(rat)*num(rat))/den_num);
			vector<int> reciprocal = {num[0], -num[1], num[3]*(num[0]-(num[1]*num[1])), num[2]};
			int hcf = __gcd(reciprocal[2], reciprocal[3]);
			reciprocal[2] /= hcf;
			reciprocal[3] /= hcf;

			int res = ((sqrt(reciprocal[0]*1.0) + reciprocal[1]*1.0)/((reciprocal[2]*1.0)/reciprocal[3]));
			reciprocal[1] -= ((res*reciprocal[2])/reciprocal[3]);

			iter++;
			num = reciprocal;
		}
	}
	cout << ans << endl;
}

int main(){
	solve(13);
	solve(10000);

	return 0;
}