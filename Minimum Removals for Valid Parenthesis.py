str='{} {} {}'
c=0
for i in range(0,len(str)):
  if str[i]=='{':
    c+=1
  if str[i]=="}":
    c-=1
if c!=0:
  print(abs(c))
else:
  print("Valid string")
