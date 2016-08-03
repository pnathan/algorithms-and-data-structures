#!/usr/bin/ruby


arr = Array[10, -10, 0, -20, 20, 5]

# formally, Omega(n^2), O(n^2). however, a careful reading of Baase
# sugests that the Average case is n^2/4. Of course, that's O(n^2),
# but constants might matter sometime.

def insertion_sort(array)
  # Takes n passes here.
  (1...array.size).each{ |i|
    j = i
    # and this also takes n, but the distance of the count decreases
    # each time.
    while j > 0 and array[j - 1] > array[j]
      temp = array[j]
      array[j] = array[j-1]
      array[j-1] = temp

      j -= 1
    end
  }
  array
end

foo =  insertion_sort arr
puts foo
