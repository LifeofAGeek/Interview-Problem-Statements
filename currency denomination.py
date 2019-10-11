notes=[2000,500,200,100,50,20,10,5,2,1]
def denomination(amount):
  '''
  Objective: To find the minimum number of notes of different denominations that sums upto the given amount.

  '''
  for i in notes:
    if amount//i>0:
      print(i,":",amount//i)
      amount-=i*(amount//i)
      continue

denomination(10820)