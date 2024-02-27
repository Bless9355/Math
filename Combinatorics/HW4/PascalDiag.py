def P(n, k):
    ans = 1
    for i in range(k):
        ans = ans * (n-i)
    return ans

def C(n, k):
    return P(n, k)/P(k, k)

def nthDiag(N):
    i = 0
    ans = 0
    while (N - i >= i):
        ans = ans + C(N - i, i)
        i = i + 1
        
    return ans