#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long


void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("travel_restrictions_input.txt", "r", stdin);
	freopen("travel_restrictions_output.txt", "w", stdout);
	#endif	
}


void solve(){
	int n;
	cin >> n;
	vector<bool> ip(n), op(n);
	for(int i=0; i<n; i++) {
		char x;
		cin >> x;
		ip[i] = (x == 'Y');
	}
	for(int i=0; i<n; i++) {
		char x;
		cin >> x;
		op[i] = (x == 'Y');
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i == j) {
				cout << 'Y';
				continue;
			}
			bool isPossible = true;
			if(i < j){
				for(int k=i; k<j; k++) {
					if(!op[k] || !ip[k+1]) isPossible = false;
				}
			}
			else {
				for(int k=i; k>j; k--) {
					if(!op[k] || !ip[k-1]) isPossible = false;
				}
			}
			if(isPossible) cout << 'Y';
			else cout << 'N';
		}
		cout << '\n';
	}
}

int main(){
	localIO();
	IOS;
	int t = 1; 
	cin >> t;
	for(int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ":\n";
		solve();
	}
	return 0;
}