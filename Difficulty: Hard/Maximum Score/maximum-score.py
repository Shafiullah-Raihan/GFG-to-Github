class Solution:
    def maximum_score(self, n, arr, k, x):
        import bisect
        
        medSum = [0] * n
        
        for i in range(n):
            cur = []
            for j in range(i, n):
                bisect.insort(cur, arr[j])
                length = j - i + 1
                
                med = cur[(length - 1) // 2]
                medSum[length - 1] += med
        
        ans = 0
        
        for bit in range(60, -1, -1):
            if (x >> bit) & 1:
                continue
            
            candidate = ans | (1 << bit)
            
            cnt = 0
            for val in medSum:
                if (val & candidate) == candidate:
                    cnt += 1
            
            if cnt >= k:
                ans = candidate
        
        return x | ans