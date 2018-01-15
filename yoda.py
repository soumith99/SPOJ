def swap(a,b):
    temp=lst[a]
    lst[a]=lst[b]
    lst[b]=temp
def mearge(i,k,j):
    left =i
    right=k+1
    sol=[0 for m in range(j-i+1)]
    count=0
    a=0
    while(left<=k and right <=j):
        if dic[lst[left]]<dic[lst[right]]:
            sol[a]=lst[left]
            a+=1
            left+=1
        else:
            sol[a]=lst[right]
            a+=1
            right+=1
            count+=(k-left+1)
    while(left<=k):
            sol[a]=lst[left]
            a+=1
            left+=1
    while(right <=j):
            sol[a]=lst[right]
            a+=1
            right+=1
    return count

def inp(i,j):
    if j<=i+1:
        if dic[lst[j]]<dic[lst[i]]:
            swap(i,j)
            return 1
        return 0
    else:
        k=(i+j)/2
        return inp(i,k)+inp(k+1,j)+mearge(i,k,j)

t=input()
lst=[]
dic={}

for i in range(t):
    l=input()
    x=raw_input().split(" ")
    y=raw_input().split(" ")
    for j in range(l):
        lst.append(x[j])
    for j in range(l):
        dic[y[j]]=j
    print inp(0,l-1),
    del(lst[:])
    dic.clear()
