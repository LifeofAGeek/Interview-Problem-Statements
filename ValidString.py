str=')*('
c=0
h=0
for i in range(0,len(str)):
    if str[i]=='{':
        c+=1
    if str[i]=="}":
        c-=1
    if str[i]=='*':
        h+=1
c=c-h
if c!=0:
    print("Not Valid")
else:
    print("Valid")
