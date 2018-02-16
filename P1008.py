# 1000 / 3 = 333 666 999
#第一个数必定在333以下

for i in range(111,334):
    n = a,b,c = [i,i*2,i*3]
    t = ['1','2','3','4','5','6','7','8','9']
    try:
        for i in n:    # 遍历存放3个数的列表
            a = list(str(i))
            for ii in a:     #遍历每个数的位数
                if(ii in t):
                    t.remove(ii)
    except ValueError:
        continue
    if not t:
        print(int(n[0]),int(n[1]),int(n[2]))

