#Normal Approach
import memory_profiler
import time
def check_even(numbers):
    even = []
    for num in numbers:
        if num % 2 == 0: 
            even.append(num*num)
            
    return even
if __name__ == '__main__':
    m1 = memory_profiler.memory_usage()
    t1 = time.clock()
    cubes = check_even(range(100000000))
    t2 = time.clock()
    m2 = memory_profiler.memory_usage()
    time_diff = t2 - t1
    mem_diff = m2[0] - m1[0]
    print(f"It took {time_diff} Secs and {mem_diff} Mb to execute this method")

#Using Generators

import memory_profiler
import time
def check_even(numbers):
    for num in numbers:
        if num % 2 == 0:
            yield num * num 
    
if __name__ == '__main__':
    m1 = memory_profiler.memory_usage()
    t1 = time.clock()
    cubes = check_even(range(100000000))
    t2 = time.clock()
    m2 = memory_profiler.memory_usage()
    time_diff = t2 - t1
    mem_diff = m2[0] - m1[0]
    print(f"It took {time_diff} Secs and {mem_diff} Mb to execute this method")
