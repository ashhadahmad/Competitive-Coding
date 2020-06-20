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

ll countDivisors(ll n) 
{ 
	ll cnt = 0; 
	for (ll i = 1; i <= sqrt(n); i++) { 
		if (n % i == 0) { 
			if (n / i == i) 
				cnt++; 

			else
				cnt = cnt + 2; 
		} 
	} 

	return cnt == 0 ? 1 : cnt; 
} 

void solve(){
	vector<bool> sieve(80, true);
	vector<int> primes;
	for(int i=2; i<10; i++){
		if(sieve[i]) {
			for(int j=i+i; j < 80; j+=i) sieve[j] = false;
		}
	}
	for(int i=2; i<80; i++){
		if(sieve[i]) primes.push_back(i);
	}
	vector<int> power_prime(primes.size(), 0);
	for(int i=0; i<primes.size(); i++){
		ll cur = primes[i];
		ll pow_cur = cur;
		while(pow_cur < (1e9+1)) pow_cur = pow_cur * cur;
		cout << "? " << pow_cur << endl;
		cout.flush();
		int bestgcd;
		cin >> bestgcd;
		while(bestgcd > 1) {
			bestgcd /= cur;
			power_prime[i]++;
		}
	}

	ll temp_ans = 1;
	for(int i=0; i<primes.size(); i++){
		temp_ans *= pow(primes[i], power_prime[i]);
	}

	ll finalAns = countDivisors(temp_ans);
	cout << "! " << finalAns << endl;
	cout.flush();
}

int main(){
	// FAST(); 
	// lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}