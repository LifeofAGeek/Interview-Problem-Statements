def greater(arr):
    l=[]
    for i in range(0,len(arr)-1):
        if arr[i] > max(arr[i+1:]):
            l.append(arr[i])
    l.append(arr[-1])
    return l
greater([16,17,4,3,5,2])
