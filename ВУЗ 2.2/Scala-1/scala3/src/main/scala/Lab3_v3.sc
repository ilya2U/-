import java.lang

//ЗАДАНИЕ 1
trait List_add {
  def list_add(ls: List[Any], elem: Any) = {
    ls :+ elem
  }
}
trait List_insert{
  def list_insert(ls:List[Any], ind: Int, elem:Any) = {
    var list2:List[Any] = ls.take(ind)
    list2 :+= elem
    var list3:List[Any] = ls.drop(ind)
    list2 = list2 ++ list3
    list2
  }}
trait List_del{
  def list_del(ls:List[Any], elem:Any) = {
    ls.filterNot(_ == elem)
  }}
trait List_print{
  def list_print(ls:List[Any], ind: Int) = {
    ls(ind)
  }}

class Mylist extends List_add with List_insert with List_del with List_print
var mylist = new Mylist
var list1:List[Any] = List("d", 5, "e", 4, 2, 1, 7, 8)
mylist.list_add(list1, "4")
mylist.list_insert(list1, 4, "jh")
mylist.list_del(list1, 5)
mylist.list_print(list1, 2)


//ЗАДАНИЕ 2
trait Insertion_sort{
  def insertion_sort(arr: Array[Int]) = {
    var a:Array[Int] = arr.clone()
    for (i <- a.indices) {
      var low:Int = i
      for (j <- i + 1 until a.length)
        if (a(j) < a(low)) low = j
      var tmp = a(i)
      a(i) = a(low)
      a(low) = tmp
    }
    a
  }}
trait Bubble_sort{
  def bubble_sort(arr: Array[Int]) = {
    var a:Array[Int] = arr.clone()
    for (i <- a.indices)
      for (j <- (a.length-1) until 0 by -1)
        if (a(j-1) > a(j)) {
          var tmp = a(j-1)
          a(j-1) = a(j)
          a(j) = tmp
        }
    a
  }}

class Sort1 extends Insertion_sort with Bubble_sort
var insertion = new Sort1
var arr1 = Array(2, 3, 5, 6, 11, 23, 65, 13, 0, 9, 54)
insertion.insertion_sort(arr1)
insertion.bubble_sort(arr1)

//ЗАДАНИЕ 3
trait Sqrt2 {
  def sqrt2(x: Double): Double = Math.sqrt(x)
}
trait Sqrt3 {
  def sqrt3(x: Double): Double = Math.cbrt(x)
}
trait Sqrt4 {
  def sqrt4(x: Double): Double = Math.pow(x, 1.0 / 4.0)
}
trait Sqrt5 {
  def sqrt5(x: Double): Double = Math.pow(x, 1.0 / 5.0)
}

trait Sqr3 {
  def sqr3(x: Double): Double = Math.pow(x, 3)
}

trait Sqr4 {
  def sqr4(x: Double): Double = Math.pow(x, 4)
}
trait Sqr5 {
  def sqr5(x: Double): Double = Math.pow(x, 5)
}

class Sqrt extends Sqrt2 with Sqrt3 with Sqrt4 with Sqrt5 with Sqr3 with Sqr4 with Sqr5
var x = new Sqrt
x.sqrt2(4)
x.sqrt3(8)
x.sqrt4(16)
x.sqrt5(32)
x.sqr3(2)
x.sqr4(2)
x.sqr5(2)
