
l=[]

def gcd(a,b):
	r=b%a
	if r==0:
		return a
	else:
		return gcd(r,a)
def lcm(n):
	ans=1
	for i in range(1,n+1):
		ans=((ans*i)/gcd(ans,i))
		l.append(ans)

lcm(10001)
t=input()
for i in range(t):
	n=input()
	print l[n-1]%1000000007
