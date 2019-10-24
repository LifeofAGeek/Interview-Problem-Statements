
def GreaterNumber(num):
    x=str(num)
    l=len(str(num))
    lis=[]
    for i in range(0,l):
        lis.append(int(x[i]))
    for j in range(l-1,0,-1):
        if lis[j]>lis[j-1]:
            lis[j-1],lis[l-1]=lis[l-1],lis[j-1]
            break
    if j==1:
        print("not possible")
    else:
        n=sorted(lis[j:])
        for k in range(0,len(n)):
          if lis[j-1]<n[k]:
            lis[j],n[k]=n[k],lis[j-1]
          break
        lis=lis[0:j]+n[0:]    
        x=0
        for k in range(0,len(lis)):
            x=x*10+lis[k]
        print("Next higher number is:",x)
        
GreaterNumber(23623)
Next higher number is: 23632
