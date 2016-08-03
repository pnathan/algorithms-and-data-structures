object driver {
  // in place design
  def quicksort(
    first: Int,
    last: Int,
    array: Array[Int]): Unit = {
    if (first < last) {
      var p = split(first, last, array)
      quicksort(first, p - 1, array)
      quicksort(p + 1, last, array)
    }
  }

  def swap(array: Array[Int], i: Int, j: Int): Unit = {
    var temp = array(i)
    array(i) = array(j)
    array(j) = temp
  }
  def split(
    first : Int,
    last: Int,
    array : Array[Int]): Integer = {

    // lomuto pivot
    var pivot = array(last)

    var i = first;
    for (j <- first to (last - 1)) {
      if (array(j) <= pivot) {
        swap(array, i, j)
        i+=1
      }
    }
    swap(array, i, last)
    i
  }

  def main(args: Array[String]) = {
    var arr = Seq.fill(20)(scala.util.Random.nextInt(50)).toArray
    println(arr.toList)
    quicksort(0, arr.size - 1, arr);
    println(arr.toList);
  }
}
