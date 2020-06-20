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

void solve(){
	string a;
	cin >> a;
	int n = a.size();
	vector<int> one(n,-1);
	vector<int> two(n,-1);
	vector<int> three(n,-1);
	for(int i=0; i<n; i++){
		if(a[i] == '1') one[i] = i;
		if(a[i] == '2') two[i] = i;
		if(a[i] == '3') three[i] = i;
		if(i > 0) {
			one[i] = max(one[i], one[i-1]);
			two[i] = max(two[i], two[i-1]);
			three[i] = max(three[i], three[i-1]);
		}
	}
	int ans = INT_MAX;
	for(int i=0; i<n; i++){
		if(one[i] == -1 || two[i] == -1 || three[i] == -1) continue;
		else{
			ans = min(ans, 1 + max(one[i], max(two[i], three[i])) - min(one[i], min(two[i], three[i])));
		}
	}
	if(ans == INT_MAX) cout << "0" << endl;
	else cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}