#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> use(n, true);
	int One = -1, Zero = -1;
	for(int i=0; i<n; i++) {
		if(s[i] == '1') if(One == -1) One = i;
		if(s[i] == '0') Zero = i;
	}

	if(One != -1 && Zero != -1) {
		for(int i=One; i < Zero; i++ ) {
			use[i] = false;
		}		
	}
	
	for(int i=0; i<n; i++) if(use[i]) cout << s[i];
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}