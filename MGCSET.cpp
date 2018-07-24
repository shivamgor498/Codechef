/* shivamgor498
	https://www.codechef.com/JULY18A/problems/MGCSET
	*/

#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define x first
#define y second
using namespace std;
ll fpow(ll base, ll exp) {
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    else if ((exp & 1) != 0)
        return base * fpow(base * base, exp / 2);
    else
        return fpow(base * base, exp / 2);
}
int main()
{
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--)
	{
		ll n,m,cnt =0 ;
		cin >> n >> m;
		vector<ll>a(n),b;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			if(a[i]%m==0)
				b.pb(a[i]); //store elements divisible by m in an array and then no. of subsequences will be 2^(array size) but we have to exclude empty set so answer is 2^(array size)-1 for calculating 2^(array size) we use fast exponentiation without modulo
		}
		if(b.size()==0)
			cout << 0;
		else if(b.size()==1)
			cout << 1;
		else
		{
			cout << fpow(2,b.size())-1;
		}
		cout << "\n";
	}
}
