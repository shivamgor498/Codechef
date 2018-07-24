/* shivamgor498
	https://www.codechef.com/JULY18A/problems/PINS*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		ll n;
		cin >> n;
		ll cnt = n/2;
		cout << "1 1";
		for(int i=0;i<cnt;i++)
			cout << "0";
		cout << "\n";
	}
}
