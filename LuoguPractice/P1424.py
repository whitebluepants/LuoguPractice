w,day = input().split()
w = int(w)
day = int(day)
d = 0
for i in range(0,day):
    if w in [1,2,3,4,5]:
        d += 250
    w += 1
    if(w == 8):
        w = 1
print(d)   