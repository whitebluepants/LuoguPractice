n = input()
nn = int(n)
sign = ""
if(nn < 0):
    sign = n[0]
    n = n[1:]
n = n[::-1]
if(n != '0'):
    t = n[0]
    while(t == '0'):
        n = n[1:]
        t = n[0]
n = sign + n

print(n)