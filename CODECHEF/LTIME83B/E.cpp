#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

ll f(int n, int k){
	if(n < k) return 0;
	if(k == 1) return n;

	int ans = 0;
	ans += f(n-1, k);
	vector<int> factors;
	for(int i=1; i*i <= n; i++){
		if(n%i){
			factors.push_back(i);
			if(n/i != i){
				factors.push_back(i);
			}
		}
	}
	// for(auto x: factors) cout << x << endl;
	ans += (factors.size() * f(n, k-1))/ n;
	return ans;
}

int main(){
	FAST(); 
	lol();
	// int t; cin >> t; while(t--){

	// }
	int n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
	return 0;
}