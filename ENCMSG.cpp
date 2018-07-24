/*shivamgor498
	https://www.codechef.com/COOK96A/problems/ENCMSG
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
		ll n;
		cin >> n;
		string s;
		cin >> s;
		if(n%2)
			n--; // if n is odd ignore last character for swapping
		for(int i=0;i<n;i+=2)
			swap(s[i],s[i+1]); // swap alternate elements
		for(int i=0;i<s.size();i++) 
			cout <<char(abs((s[i]-'a')-25)+'a'); // replace 'a' with 'z', 'b' with 'y' and so on..., using given formula
		cout  << "\n";
	}
}
