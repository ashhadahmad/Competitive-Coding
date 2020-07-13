#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

ll dayscount(vector<ll> a,int x,ll pos) {
	ll days = 0;
    for(ll i = pos; i < a.size(); i++){
    	if(x < a[i]){
			while(x < a[i]){
				x = 2 * x;
				days++;
			}
			days++;
		}
		else days++;
		x = 2 * a[i];
	}
	return days;
}
ll func(vector<ll> a,int x, int n,ll pos) {
	ll days = dayscount(a,x,pos);
	ll p = days+pos;
	if(pos != 0){
		days = dayscount(a,x,pos-1);
		return min(days+pos-1, p);
	}
	return p;
}

void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(auto &x: a) cin >> x;
	sort(a.begin(), a.end());
	
	ll index = -1;
	if(x <= a[0]) index = 0;
	else if(x >= a[n-1]) index = n-1;
	else {
		for(int i=0; i<n; i++) {
			if(a[i] > x) {
				index = i;
				break;
			}
		}
	}
	cout << func(a,x,n,index) << "\n";

}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}