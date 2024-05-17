for i in range(50000):
    t = i*i + (50000-i)*(50000-i)
    if t==2225759488 or t==2000000000:
        print(i, t)
