def sum(n) :
    result = 0
    for i in range(n):
        result = result + 1
    return result

def recursiveSum(n):
    if n == 1 : return 1
    return n + recursiveSum(n-1)
