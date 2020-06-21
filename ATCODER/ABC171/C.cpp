#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

string getAns(ll num) {
	if(num <= 26) {
		string ans = "";
		char cur = ('a' + (num - 1));
		ans += cur;
		return ans;
	}
	ll st = 1;
	while(st * 26 < num) st *= 26;
	cout << st << " " << num/st << endl;
	string smallAns = getAns(num % st);
	char ans = (((num/st) - 1) + 'a');
	string a = "";
	a += ans;
	return a + smallAns;
}

void solve(){
	ll num;
	cin >> num;
	cout << getAns(num);
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}