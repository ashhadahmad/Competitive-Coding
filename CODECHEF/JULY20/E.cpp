#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long


// BRUTE FORCE IN PYTHON

// mod = 998244353

// def W(a,x):
//     weirdness = 0
//     for i in range(len(a)):
//         weirdness += a[i] * (x ** i)
//     return weirdness

// t = int(input())
// for _t in range(t):
//     n,x = (int(_x) for _x in input().split())
//     a = [int(_x) for _x in input().split()]
//     ans = 1
//     for i in range(n):
//         for j in range(i,n):
//             ans *= (W(a[i:j+1],x) ** 2)
//             # print(i,j)
//     ans = ans % mod
//     # print(a[0:1])
//     print(ans)

void solve(){
	
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}