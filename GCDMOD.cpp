/* shivamgor498
	https://www.codechef.com/AUG18A/problems/GCDMOD/
	Explanation :- gcd of two numbers (a,b) according to eucledian theorem is same as gcd of (b%a,a) so we have to calculate gcd of (a^n + b^n )%(a-b) and a-b.
	(a^n + b^n )%(a-b) = ((a^n)%(a-b) + (b^n)%(a-b))%(a-b)
	to calculate (a^n)%(a-b) and (b^n)%(a-b) we use fast power with big number multiplication */

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
using namespace std;
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=mM(res,x,p);res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=mM(x,x,p);if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n){return fpow(n,hell-2,hell);}
ll modmul(ll x,ll y){return mM(x,y,hell);}
ll modadd(ll x,ll y){ll temp=x%hell+y%hell;temp%=hell;if(temp<0)temp = (temp+hell)%hell;return temp;}
int main(){
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll a,b,n;
		cin >> a >> b >> n;
		n%=hell1; // fermats theorem
		ll p = a-b;
		if(p){
			ll temp = fpow(a,n,p); 
			ll temp1 = fpow(b,n,p);
			temp = (temp+p)%p;
			temp1 = (temp1+p)%p;
			temp = (temp%p + temp1%p)%p;
			ll ans = __gcd(temp,p);
			cout << ans%hell << "\n";
		}
		else{
			ll temp = fpow(a,n,hell);
			ll temp1 = fpow(b,n,hell);
			cout << modadd(temp,temp1) << "\n";
		}
	}
}
