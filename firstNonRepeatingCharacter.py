def firstNonRepeatingCharacter(word):
  d={}
  for i in word:
    if i in d:
      d[i]+=1
    else:
      d[i]=1
  for i in d:
    if d.get(i)==1: #constant time
      print(i)
      break
  else:
    print("All letter are repeating")

firstNonRepeatingCharacter("anubhav sethi")
