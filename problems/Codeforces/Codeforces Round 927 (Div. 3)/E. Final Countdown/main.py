#
# name: E. Final Countdown
# link: https://codeforces.com/problemset/problem/1932/E
# start: Sat Mar 16 10:58:34 2024
#

import sys

memo99 = [0]

print("arr", file=sys.stderr)
memo99 = [9] * 400010
print("genning", file=sys.stderr)

for i in range(2, 100):
    memo99[i] = memo99[i - 1] + (i + memo99[i - 1]) * 9
print("genned", file=sys.stderr)

memo = {}


def f(n, len):
    if len == 1:
        return int(n)
    elif n in memo:
        return memo[n]

    memo[n] = f(n[1:], len - 1) + (len + f("9" * (len - 1), len - 1)) * int(n[0])
    return memo[n]


for i in range(1, 100):
    fi = f("9" * i, i)
    print(f"{i}: {memo99[i]=} {fi=}")


for i in range(int(input())):
    print(f"testcase: {i}", file=sys.stderr)
    len = int(input())
    n = input()
    print(f(n, len))
