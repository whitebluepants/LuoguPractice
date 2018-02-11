d = float(input())
init = 2
sum = 0
step = 0
while(d > sum):
    sum += init
    init *= 0.98
    step += 1
print(step)