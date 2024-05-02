import sys
import random

# Open a file named 'output.txt' in write mode ('w')
with open('input.txt', 'w') as file:
    # Redirect standard output to the file
    sys.stdout = file
    t=1#random.randint(1,100)
    print(t)
    for j in range(t):
        n=200
        # Now, all print statements will write to the file
        print(n)
        for i in range(1,n+1):
            print(i,i,end=" ")
        # print(a)
        
        
# Reset standard output back to the console
sys.stdout = sys.__stdout__
