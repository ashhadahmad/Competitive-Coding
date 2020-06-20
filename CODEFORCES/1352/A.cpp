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
	int n; 
	cin >> n;
	vector<int> ans;
	int base = 1;
	while(n){
		if(n%10){
			ans.push_back((n%10) * base);
		}
		base *= 10;
		n /= 10;
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << " ";
	cout<<endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}