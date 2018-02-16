sum = 0
count = 0
flag = True
a = 0
for i in range(0,12):
    line = input()
    sum += 300
    sum -= int(line)
    a = sum // 100
    
    if(a > 0):
        sum -= a* 100
        count += a * 100
    elif(sum < 0):
        print("-" + str((i + 1)))
        flag = False
        break
    
if(flag == True):
    print(int(count * 1.2) + sum)
