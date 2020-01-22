def canStop(runway,speed,i=0):
    if (i>=len(runway) or i<0 or speed<0 or not runway[i]):
        return False
    
    if speed==0:
        return True
    
    for adjustedSpeed in [speed,speed-1,speed+1]:
        if canStop(runway,adjustedSpeed,i+adjustedSpeed):
            return "Will pass the runway"
    return("Cannot pass the runway")
    
canStop([True,False,True,True,True,True,False,False,True],3)
