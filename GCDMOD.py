# GCDMOD in python
# shivamgor498
# https://www.codechef.com/AUG18A/problems/GCDMOD/



def power(x, y, m) :
    if (y == 0) :
        return 1
    p = power(x, y // 2, m) % m
    p = (p * p) % m
    if(y % 2 == 0) :
        return p
    else :
        return ((x * p) % m)
def modInverse(a, m) :
    return power(a, m - 2, m)
def computeGCD(x, y):
    while(y):
        x, y = y, x % y
    return x
MOD = 1000000007
for _ in range(int(input())):
    a, b, n = input().split()
    a, b, n = int(a), int(b), int(n)
    p = a-b
    if(p):
        temp = power(a,n,p)
        temp1 = power(b,n,p)
        temp = (temp+p)%p
        temp1 = (temp1+p)%p
        temp = (temp%p + temp1%p)%p
        ans1 = computeGCD(temp,p)%MOD
        print (ans1)
    else :
        temp = power(a,n,MOD)
        temp1 = power(b,n,MOD)
        temp = (temp%MOD + temp1%MOD)%MOD
        print(temp)
