#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool isPrime(int n){
	for(int i=3; i*i <= n; i+2) {
		if(n % i) return false;
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

	if(!(n & (n-1))) {
		cout << "FastestFinger\n";
		return;
	}

	int count2 = 0;
	while(!(n&1)) {
		n >>= 1;
		count2++;
	}

	if(isPrime(n)){
		if(count2 == 1){
			cout << "FastestFinger\n";
		}
		else {
			cout << "Ashishgup\n";
		}
	}
	else{
		cout << "Ashishgup\n";
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}