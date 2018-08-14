/*shivamgor498
https://www.codechef.com/COOK96A/problems/CHGCDG
*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>lprime(1000006,0),d[1000006];
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
	lprime[1] = 1;
	for(int i=2;i<1000006;i++)
		if(!lprime[i])
			for(int j=i;j<1000006;j+=i)
				if(!lprime[j])
					lprime[j] = i;//lowest prime integer of j
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		ll n;
		cin >> n;
		vector<ll>a(n);
		for(int i=0;i<1000006;i++)
			d[i].clear();
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
		{
			ll prime,tcnt = 0;
			while(a[i]>1)
			{
				prime = lprime[a[i]];
				tcnt = 0;
				while(a[i]>1 && a[i]%prime==0)
				{
					tcnt++;
					a[i]/=prime;
				}
				d[prime].pb(tcnt);//store count of prime factors of i
			}
		}
		ll gc = 1;
		for(int i=2;i<1000006;i++)
		{
			ll l = 0,r = 0;
			for(int k=0;k<d[i].size();k++)
				r = max(r,d[i][k]+1); // maximum right limit
			ll rem = n-d[i].size(); // no. of elements not having i in its prime factors
			while(r-l > 1)
			{
				ll mid = (l+r)/2,now = 0; // mid is count of prime i that will be present in each element of array so our final gcd will increase by gc = gc*mid*i;
				for(int k=0;k<d[i].size();k++)
					if(d[i][k]>=mid)
						now+=((d[i][k]-mid)/2); //count of extra prime i in a particular element that can be distributed to another element
					else
						now-=(mid-d[i][k]); //no. of primes needed in an particular element of an array so that it has mid no. of prime i in it
				now-=(rem*mid); //subtracting no. of primes needed by each element in array that does not have prime i in its factors
				if(now>=0) // if this value is possible then search for higher possible value than mid because we want maximum gcd
					l=mid;
				else // else find lower value than mid that is possible
					r=mid;
			}
			for(int j=0;j<l;j++)
				gc*=i; // multiply l times prime number i in gcd as atleast l no. of i will be present in each element in array
		}
		cout << gc << "\n";
	}
}
