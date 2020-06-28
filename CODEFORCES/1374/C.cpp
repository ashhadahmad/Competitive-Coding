#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	int err = 0, open = 0;
	for(int i=0; i<n; i++){
		char c; 
		cin >> c; 
		if(c == '(') open++;
		if(c == ')') {
			if(open == 0) err++;
			else open--;
		}
	}
	err += open;
	cout << (err >> 1) << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}