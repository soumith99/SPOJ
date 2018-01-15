t=input()
for i in range(t):
	n=input()
	a=map(int,raw_input().split())
	b=map(int,raw_input().split())
	a.sort()
	b.sort()
	sum=0
	for j in range(n):
		sum+=int(a[j])*int(b[j])
	print sum
