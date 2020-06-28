#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const int mxn = (int)1e7+5;

int sieve[mxn] = {0};
int divisors[mxn];
int ans[mxn];

int main(){
	IOS;
	for(int i=0; i<mxn; i++) {
		sieve[i] = -1;
	}
	for(int i=2; i*i <= mxn; i++){
		if(sieve[i] == -1) {
			for(int j = i+i; j < mxn; j+=i) {
				if(sieve[j] == -1) sieve[j] = i;
			}
		}
	}

	divisors[0] = 0;
	divisors[1] = 1;

	for(int i=2; i<mxn; i++) {
		if(sieve[i] == -1) divisors[i] = 2;
		else divisors[i] = 1 + divisors[(i/sieve[i])];
	}

	for(int i=0; i<=100; i++) cout << divisors[i] << " ";

	int n;
	cin >> n;

	ll ans = 0;

	for(int i=1; i <= n; i++) {
		ans += ((ll) divisors[i] * (ll) i);
	}

	cout << ans;

 	return 0;
}