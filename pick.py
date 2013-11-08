def pick(n, picked, select):
    if select == 0 : 
        print(picked)
        return None
    
    last = 0
    if len(picked) > 0 : 
        last = picked[len(picked)-1] + 1

    for i in range(last, n):
        picked.append(i)
        pick(n, picked, select-1)
        picked.pop()
        
