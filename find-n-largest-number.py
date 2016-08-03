import collections

# find the nth largest
numlist = [0,5, 6, 8, 3,-10, 1, 13, 11, -7, -14, 9]

n = 3
deq = collections.deque(maxlen=n)
for x in numlist:
    print x, 'DEQ', deq
    if len(deq) == 0:
        deq.append(x)
    if x > deq[0]:
        print 'push'
        deq.append(x)

    deq.sort()



print sorted(numlist)
print 'RESULT', deq[0]
