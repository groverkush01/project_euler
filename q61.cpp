#include <bits/stdc++.h>
using namespace std;

vector<int> triangular, square, pentagonal, hexagonal, heptagonal, octagonal;

map<int, int> triangular_front, square_front, pentagonal_front, hexagonal_front, heptagonal_front, octagonal_front;

int dfs(int mask, int num, int og_num){
	if(mask == 63) {
		if((num%100) == (og_num/100)) return num;
		return -1;
	}
	else {
		if((mask & 2) == 0) {
			if((square_front.find(num%100) != square_front.end())){
				int ans = dfs((mask | 2), square_front[num%100], og_num);
				if(ans != -1) {
					// cout << "square num = " << square_front[num%100] << endl;
					return num + ans;
				}
			}
		}
		if((mask & 4) == 0) {
			if((pentagonal_front.find(num%100) != pentagonal_front.end())){
				int ans = dfs((mask | 4), pentagonal_front[num%100], og_num);
				if(ans != -1) {
					// cout << "pentagonal num = " << pentagonal_front[num%100] << endl;
					return num + ans;
				}
			}
		}
		if((mask & 8) == 0) {
			if((hexagonal_front.find(num%100) != hexagonal_front.end())){
				int ans = dfs((mask | 8), hexagonal_front[num%100], og_num);
				if(ans != -1) {
					// cout << "hexagonal num = " << hexagonal_front[num%100] << endl;
					return num + ans;
				}
			}
		}
		if((mask & 16) == 0) {
			if((heptagonal_front.find(num%100) != heptagonal_front.end())){
				int ans = dfs((mask | 16), heptagonal_front[num%100], og_num);
				if(ans != -1) {
					// cout << "heptagonal num = " << heptagonal_front[num%100] << endl;
					return num + ans;
				}
			}
		}
		if((mask & 32) == 0) {
			if((octagonal_front.find(num%100) != octagonal_front.end())){
				int ans = dfs((mask | 32), octagonal_front[num%100], og_num);
				if(ans != -1) {
					// cout << "octagonal num = " << octagonal_front[num%100] << endl;
					return num + ans;
				}
			}
		}
	}
	return -1;
}

void solve(){
	for(auto x : triangular) {
		int ans = dfs(1, x, x);
		if(ans != -1){
			// cout << "triangular num = " << x << endl;
			cout << ans << endl;
			return;
		}
	}
}

int main(){
	int i = 1;
	while(((i*(i+1))/2) < 10000) {
		int num = ((i*(i+1))/2);
		if(num >= 1000) {
			triangular.push_back(num);
			triangular_front[num/100] = num;
		}
		i++;
	}
	i = 1;
	while((i*i) < 10000) {
		int num = (i*i);
		if(num >= 1000) {
			square.push_back(num);
			square_front[num/100] = num;
		}
		i++;
	}

	i = 1;
	while(((i*(3*i-1))/2) < 10000) {
		int num = ((i*(3*i-1))/2);
		if(num >= 1000) {
			pentagonal.push_back(num);
			pentagonal_front[num/100] = num;
		}
		i++;
	}

	i = 1;
	while((i*(2*i-1)) < 10000) {
		int num = (i*(2*i-1));
		if(num >= 1000) {
			hexagonal.push_back(num);
			hexagonal_front[num/100] = num;
		}
		i++;
	}
	
	i = 1;
	while(((i*(5*i-3))/2) < 10000) {
		int num = ((i*(5*i-3))/2);
		if(num >= 1000) {
			heptagonal.push_back(num);
			heptagonal_front[num/100] = num;
		}
		i++;
	}
	
	i = 1;
	while((i*(3*i-2)) < 10000) {
		int num = (i*(3*i-2));
		if(num >= 1000) {
			octagonal.push_back(num);
			octagonal_front[num/100] = num;
		}
		i++;
	}

	solve();

	return 0;
}