def rotate(arr,k):
    i=0
    while(i<k):
        arr.insert(len(arr),arr[0])
        arr.pop(0)
        i+=1
    return arr
    
a=[1,2,3,4,5]
rotate(a,3)
