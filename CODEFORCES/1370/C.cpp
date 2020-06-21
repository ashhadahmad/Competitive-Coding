#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool isPrime(int n){
	for(ll i=2; i*i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

void solve(){
	int n;
	cin >> n;

	if(n == 1) {
		cout << "FastestFinger\n";
		return;		
	}
	if(n & 1 || n == 2) {
		cout << "Ashishgup\n";
		return;
	}

	if((n & (n-1)) == 0) {
		cout << "FastestFinger\n";
		return;
	}

	int count2 = 0;
	while(n > 1 && n % 2 == 0){
		count2++;
		n/=2;
	}

	if(isPrime(n) && count2 == 1) {
		cout << "FastestFinger\n";
		return;		
	}

	cout << "Ashishgup\n";
	return;
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}