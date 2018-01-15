t=input()
for i in range(t):
    k=raw_input()
    n=input()
    sum=0
    for j in range(n):
        sum+=input()
    if(sum%n==0): print "YES"
    else: print "NO"
