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
    else:
        x="not possible"
    if x=="not possible":
        print("Sorry, there is no higher number!")
    else:    
        x=0
        for k in range(l):
            x=x*10+lis[k]
        print("Next higher number is:",x)
        
GreaterNumber(453876)
Next higher number is: 456873
