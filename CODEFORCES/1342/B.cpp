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

void solve() {
	string s;
	cin >> s;
	bool is_one = false;
	bool is_zero = false;
	for(char c:s){
		if(c == '0') is_zero = true;
		else is_one = true;
	}

	// cout << is_one << " " << is_zero<<endl;

	if(is_one && is_zero){
		string ans = "";
		ans += s[0];
		for(int i=1; i<2 * s.size(); i++){
			if(ans[ans.size() - 1] == '1') ans += '0';
			else ans += '1';
		}
		cout << ans << endl;
		return;
	}
	cout << s << endl;
	return;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();		
	}
	return 0;
}