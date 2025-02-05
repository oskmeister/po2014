#!/usr/bin/python3
import sys

def match(f, d):
    res = 0
    i = 0
    while i < len(f) - 1:
        if f[i+1] - f[i] < d:
            i += 1
            res += 1
        i += 1
    return res

N,K = [int(i) for i in input().split()]
F = sorted([int(s) for s in input().split()])

lo = 0
hi = 1000000000000000
while lo < hi:
    mid = lo + (hi - lo)//2
    if match(F, mid) >= K:
        hi = mid
    else:
        lo = mid + 1
print(lo)
