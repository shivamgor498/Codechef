/* shivamgor498
	https://www.codechef.com/LTIME62B/problems/SPLST	*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
typedef unsigned long long int ull;
using namespace std;
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
ll inv(ll n)
{
	return fpow(n,hell-2);
}
ll modmul(ll x,ll y){
	return (x*1ll*y)%hell;
}
ll modadd(ll x,ll y){
	ll temp = x%hell + y%hell;
	temp%=hell;
	if(temp<0)
		temp = (temp+hell)%hell;
	return temp;
}
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		vector<ll>a(3),b(2);
		for(int i=0;i<3;i++)
			cin >> a[i];
		for(int i=0;i<2;i++)
			cin >> b[i];
		bool ok = false;
		sort(a.begin(),a.end());		
		sort(b.begin(),b.end());
		do
		{
			do
			{
				ll t1 = b[0]-a[0];
				ll t2 = b[1]-a[1];
				if(t1>=0 && t2>=0 && t1+t2==a[2])
				{
					ok = true;
					break;
				}
			}while(next_permutation(b.begin(),b.end()));
			if(ok)
				break;
		}while(next_permutation(a.begin(),a.end())); // generate all possible permutation of a and b check if it is possible 
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
