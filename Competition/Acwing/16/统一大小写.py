t = int(input())


for _ in range(t):
    s = input()
    upp,low = 0,0
    for i in range(len(s)):
        if s[i].islower():
            low += 1
        else:
            upp += 1
    if low >= upp:
        s = s.lower()
    else:
        s = s.upper()
    print(s)