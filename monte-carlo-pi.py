import random


# N.B., couldn't make the math work for 0,0 -> 1,1 square.

# square goes from -1,-1 to 1,1
hit = 0
max = 10000
for i in xrange(0, max):
    xcandidate = 2 * random.random() - 1
    ycandidate = 2 * random.random() - 1
    # print xcandidate, ycandidate

    if ((xcandidate * xcandidate) + (ycandidate * ycandidate)) < 1:
        hit += 1.0

print hit
print 4 * hit / max
