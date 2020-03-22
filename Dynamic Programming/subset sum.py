def subsetSum(a,dp,n,total):
    if dp[n][total] is None:
        if total == 0:
            dp[n][total] = True
        elif n == 0 and total != 0:
            dp[n][total] = False
        elif total < a[n-1]:
            dp[n][total] = subsetSum(a,dp,n-1,total)
        elif total >= a[n-1]:
            dp[n][total] = subsetSum(a,dp,n-1,total) or subsetSum(a,dp,n-1,total-a[n-1])
    return dp[n][total]
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if sum(a)%2 == 1:
        print('NO')
        continue
    dp = [[None for i in range((sum(a)//2) + 1)] for j in range(n+1)]
    
    if subsetSum(a,dp,n,sum(a)//2):
        print('YES')
    else:
        print('NO')


x=input()