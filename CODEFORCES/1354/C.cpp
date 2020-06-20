#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pi 3.14159265358979323846
void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	double n; cin >> n;
	double angle = (2 * n - 2) * (double) 180 / (2 * n);
	// cout << angle << endl;
	double thirdangle = (double) 180 - angle;
	thirdangle /= 2;
	double result = tan(thirdangle*pi/180);
	// double tant = tan(thirdangle);
	// cout << pi << endl;
	double ans = (double) 1 / result;

	// double ans = 
	cout << fixed << setprecision(10) << ans << endl;	
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}