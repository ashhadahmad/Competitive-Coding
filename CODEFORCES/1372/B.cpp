#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	if(n & 1) { 
		int minprime = 1;
		for(ll i=2; i*i <= n; i++){
			if(n % i == 0) {
				minprime = i;
				break;
			}
		}

		if(minprime == 1) {
			cout << 1 << " " << n-1 << "\n";
		}
		else {
			int first = n/minprime;
			cout << first << " " << n-first << "\n";			
		}
	}
	else {
		cout << n/2 << " " << n/2 << "\n";
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}