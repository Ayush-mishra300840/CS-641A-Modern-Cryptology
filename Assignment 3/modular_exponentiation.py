
def modulo_inv(a, m):
    m0 = m
    y = 0
    x = 1
    if (m == 1):
        return 0
    while (a > 1):
        q = a // m
        t = m
        m = a % m
        a = t
        t = y
        y = x - q * y
        x = t
    if (x < 0):
        x = x + m0
    return x

def modularexp(a, b, m):
    ans = 0
    for i in range(len(a)): 
        ans = (ans*10 + int(a[i])) 
        ans = ans % m 
    
    mul = ans 
    for i in range(1,b): 
        ans = (ans*mul) % m 
    return ans 

A1 = "11226815350263531814963336315"
A2= "9190548667900274300830391220"
A3= "4138652629655613570819000497"
L,M,N, m = +139,632,493, 19807040628566084398385987581
X=(modularexp(A1, N, m))
Y=(modularexp(A2, M, m))
Z=(modularexp(A3, L, m))
Z=modulo_inv(Z,m)
NUM=(Y*Z)%m
G=(modulo_inv(X,m))
g=(G*NUM)%m
g="192847283928500239481729"
a2=2345
ga=(modularexp(g, a2, m))
ga_inv=modulo_inv(ga,m)
ans2=(ga_inv*(9190548667900274300830391220)%m)%m
print(ans2)
