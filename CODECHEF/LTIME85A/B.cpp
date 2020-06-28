#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	double a = 0, b = 0;
	for(int i=0; i<n; i++) {
		double t, x, y;
		cin >> t >> x >> y;
		a += (t * y) / (x + y);
		b += (t * x) / (x + y);
	}
	cout << fixed << setprecision(6) << a << " ";
	cout << fixed << setprecision(6) << b << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}