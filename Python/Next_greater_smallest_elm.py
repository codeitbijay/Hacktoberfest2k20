def NGE(li):
    next = 0
    stack = []
    nge = [-1] * n
    stack.append({li[0]: 0})
    for i in range(n - 1):
        next += 1
        if list(stack[-1])[0] < li[next]:
            nge[list(stack[-1].values())[0]] = li[next]
            NSE(li, list(stack[-1].values())[0], next)
            stack.pop()
            while len(stack) != 0 and list(stack[-1])[0] < li[next]:
                nge[list(stack[-1].values())[0]] = li[next]
                NSE(li, list(stack[-1].values())[0], next)
                stack.pop()
            stack.append({li[next]: next})
        else:
            stack.append({li[next]: next})

    print(nge)


def NSE(li, z, x):
    res = li[x]
    for it in li[x + 1:]:
        if res > it:
            nse[z] = it
            break


n = int(input())
li = []
for i in range(n):
    li.append(int(input()))



nse = [-1] * n
NGE(li)

for i in range(n):
    print(nse[i], end=" ")
