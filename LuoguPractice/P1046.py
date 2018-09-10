apple = input().split()
height = int(input()) + 30
count = 0
for i in apple:
    if height >= int(i):
        count += 1
print(count)