#输入并分别赋值给n,number 例如 3 10 那n = 3 number = 10
n,number = input().split()
n = int(n)
# x代表某个数字出现的次数
x = 0
#遍历每个数 并通过count函数计算这个数里有多少个对应的number
for i in range(1,n + 1):
    x += str(i).count(number)
print(x)
