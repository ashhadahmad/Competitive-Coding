#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s; 
	cin >> s;
	vector<ll> nextOne(n);
	int count = 0;

	for(int i=n-1; i >= 0; i--){
		if(i == n-1){
			if(s[i] == '1') nextOne[i] = 0;
			else nextOne[i] = INT_MAX;
		}
		else{
			if(s[i] == '1') nextOne[i] = 0;
			else if(nextOne[i+1] == INT_MAX) nextOne[i] = INT_MAX;
			else nextOne[i] = 1 + nextOne[i+1];
		}
	}
	ll leftOne = INT_MAX;
	for(int i=0; i<n; i++){
		if(s[i] == '0') {
			if(min(leftOne-1, nextOne[i] - 1) >= k) {
				++count;
				leftOne = 0;
			}
			++leftOne;
		}
		else{
			leftOne = 1;
		}
	}
	cout << count << "\n"; 
}

int main(){
	FASTIO(); 
	localIO();
	int t; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}