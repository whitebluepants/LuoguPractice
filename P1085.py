max = 0
day = 0
for i in range(0,7):
    a,b = input().split()
    sum = int(a) + int(b)
    if(sum > 8):
        if(sum > max):
            max = sum
            day = i + 1

print(day)
