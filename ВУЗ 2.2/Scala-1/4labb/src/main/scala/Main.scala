import scala.annotation.tailrec

object Main extends App {
  @tailrec
  def each(cond: => Boolean)(body: => Unit): Unit = {
    if (!cond) {
      println("nil")
    } else {
      body
      each(cond)(body)
    }
  }
  var mass = Array(1, 2, 3, 5, 6, 7, 8, 9,10)
  each(!mass.isEmpty) {
    if(mass.last % 2 == 0){
      println(mass.last + mass.last-1)
    } else {
    println(mass.last)}
    mass = mass.dropRight(1)
  }
}