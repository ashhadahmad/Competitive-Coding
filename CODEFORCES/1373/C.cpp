#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	string s;
	cin >> s;
	int count = 0;
	int worst = 0;
	ll ans = 0;

	for(int i=0; i<(int) s.size(); i++) {
		if(s[i] == '+') count++;
		else count--;
		if(count < worst) {
			ans += i+1;
			worst = count;
		}
	}

	cout << ans + (int) s.size() << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}