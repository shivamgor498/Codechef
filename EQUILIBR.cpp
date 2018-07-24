/* shivamgor498
	https://www.codechef.com/problems/EQUILIBR
	*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
ll inv(ll n)
{
	return fpow(n,hell-2);
}
int main()
{
	ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
		ll n,k;
		cin >> n >> k;
		/* formula for this problem is   1 - (n/(2^(n-1)))
		*/
		ll deno = fpow(2,n-1);
		//cout << deno << "\n";
		ll fdeno = inv(deno);
		//cout << fdeno << "\n";
		fdeno = ((n%hell)*(fdeno%hell))%hell;
		fdeno = 1 - fdeno;
		fdeno%=hell;
		fdeno = (fdeno+hell)%hell;
		cout << fdeno << "\n";
	}
}
