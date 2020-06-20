#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

bool tryOneHelper(ll a, ll b, ll c, ll p, ll q, ll r){
	if(b == q && c == r) return true;

	ll d1 = p-a, d2 = q-b, d3 = r-c;

	// SUM
	if(d1 == d2 && d2 == d3) return true;
	if(c == r){
		// printf("%d %d %d %d %d %d\n",a,b,c,p,q,r);
		if(d1 == d2) return true;
	}
	
	// MULTIPLICATION
	if(a != 0 && b != 0 && c != 0){
		if(p % a == 0 && q % b == 0 && r % c == 0){
			if(p * b == q * a && q * c == r * b) return true;
		}
	}
	if(c == r){
		if(a != 0 && b != 0){
			if(p % a == 0 && q % b == 0){
				if(p * b == q * a) return true;
			}
		}
	}
	if(c == r && b == q){
		if(a != 0 && p % a == 0) return true;
	}
	return false;
}
bool tryTwoHelper(ll a, ll b, ll c, ll p, ll q, ll r, ll steps = 0, ll i = 0){
	if(steps > 2) return false;
	if(i == 3 && steps == 2) return true;
	if(i == 0){
		if(a == p) return tryTwoHelper(a,b,c,p,q,r,0,i+1);
		ll diff = p - a;
		bool ans = false;
		ans |= tryTwoHelper(a+diff,b,c,p,q,r,1,1);
		ans |= tryTwoHelper(a+diff,b+diff,c,p,q,r,1,1);
		ans |= tryTwoHelper(a+diff,b,c+diff,p,q,r,1,1);
		ans |= tryTwoHelper(a+diff,b+diff,c+diff,p,q,r,1,1);
		if(ans) return true;
		if(a != 0 && p % a == 0){
			ll quot = p/a;
			ans |= tryTwoHelper(a * quot,b,c,p,q,r,1,1);
			ans |= tryTwoHelper(a * quot,b * quot,c,p,q,r,1,1);
			ans |= tryTwoHelper(a * quot,b,c * quot,p,q,r,1,1);
			ans |= tryTwoHelper(a * quot,b * quot,c * quot,p,q,r,1,1);
		}
	}
	if(i == 1){
		if(b == q) return tryTwoHelper(a,b,c,p,q,r,steps,i+1);
		ll diff = q - b;
		bool ans = false;
		ans |= tryTwoHelper(a,b+diff,c,p,q,r,steps+1,i+1);
		ans |= tryTwoHelper(a,b+diff,c+diff,p,q,r,steps+1,i+1);
		if(ans) return true;
		if(b != 0 && q % b == 0){
			ll quot = q/b;
			ans |= tryTwoHelper(a,b * quot,c,p,q,r,steps+1,i+1);
			ans |= tryTwoHelper(a,b * quot,c * quot,p,q,r,steps+1,i+1);
		}
	}
	if(i == 2){
		if(c == r) return tryTwoHelper(a,b,c,p,q,r,steps,i+1);
		else return tryTwoHelper(a,b,c,p,q,r,steps+1,i+1);
	}
	return false;
}

bool tryTwoHelperAnother(ll a, ll b, ll c, ll p, ll q, ll r){
	if(a != 0 && b != 0 && c != 0){
		ll mod1 = ((p%a)+a)%a;
		ll mod2 = ((q%b)+b)%b;
		ll mod3 = ((r%c)+c)%c;
		if(mod1 == mod2 && mod2 == mod3){
			if(p * b == q * a && q * c == r * b) return true;
		}
	}

	for(ll i = -100000; i <= 100000; i++){
		if(tryOneHelper(a+i,b+i,c+i,p,q,r)) return true;
	}
	return tryTwoHelper(a,b,c,p,q,r);
}


bool tryZero(ll a, ll b, ll c, ll p, ll q, ll r){
	return (a == p) && (b == q) && (c == r);
}

bool tryOne(ll a, ll b, ll c, ll p, ll q, ll r){
	bool ans = false;
	ans |= tryOneHelper(a,b,c,p,q,r);
	ans |= tryOneHelper(a,c,b,p,r,q);
	ans |= tryOneHelper(b,a,c,q,p,r);
	ans |= tryOneHelper(b,c,a,q,r,p);
	ans |= tryOneHelper(c,a,b,r,p,q);
	ans |= tryOneHelper(c,b,a,r,q,p);
	return ans;
}

bool tryTwo(ll a, ll b, ll c, ll p, ll q, ll r){
	bool ans = false;
	ans |= tryTwoHelperAnother(a,b,c,p,q,r);
	ans |= tryTwoHelperAnother(a,c,b,p,r,q);
	ans |= tryTwoHelperAnother(b,a,c,q,p,r);
	ans |= tryTwoHelperAnother(b,c,a,q,r,p);
	ans |= tryTwoHelperAnother(c,a,b,r,p,q);
	ans |= tryTwoHelperAnother(c,b,a,r,q,p);
	return ans;
}

void solve(){
	ll a,b,c,p,q,r;
	cin >> a >> b >> c >> p >> q >> r;
	if(tryZero(a,b,c,p,q,r)){
		cout << "0\n";
		return;
	}
	if(tryOne(a,b,c,p,q,r)){
		cout << "1\n";
		return;
	}
	if(tryTwo(a,b,c,p,q,r)){
		cout << "2\n";
		return;
	}
	cout << "3\n";
}

int main(){
	FASTIO(); 
	localIO();
	ll t; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}