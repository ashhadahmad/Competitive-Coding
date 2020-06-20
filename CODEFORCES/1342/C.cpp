#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve() {
	ll a, b, q;
	cin >> a >> b >> q;
	if(a < b) swap(a,b);
	ll mul = (a * b) / gcd(a, b);
	while(q--){
		ll l,r;
		cin >> l >> r;
		ll mulr = floor(r / mul);
		ll mull = ceil(l/mul);
		ll toatalInstances = mulr-mull;
		ll ans = r - l + 1;
		ll sub = toatalInstances * a;
		for(ll i=0; i<a; i++){
			ll dig = r - i;
			if(dig % mul == 0) {
				sub -= (a-i-1);
				break;
			}
		}


		for(ll i=0; i<a; i++){
			ll dig = l - i;
			if(dig % mul == 0) {
				sub += a-i;
				break;
			}
		}


		ans -= sub;
		cout << (ans > 0 ? ans : 0) << " ";
	}
	cout << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();		
	}
	return 0;
}