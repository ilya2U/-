import scala.util.Random
trait role{
  val role:String
  var status:String
  var st:Int
}
abstract class Account extends role

case class SomethingStrange() extends Account {
  val role = "??"
  var status=""
  var st = 0
  def getstatus(): Unit ={
    status="??"
    println(status)
  }
}
case class User(name: String) extends Account {
  val role = "User"
  var status = ""
  var st = 0
}

abstract case class Moderator (name: String) extends Account {
  val role = "Moderator"
  val status = ""
  var st = 2
  def Ulta(obj:User): Unit ={
    obj.status = "Mute"
    print(obj.status)
  }
}

case class SuperUser(name: String,email: String) extends Account {
  override val role = "SuperUser"
  var status = " "
  var st = 1
  val R = Random.between(0, 10)
}

def matcherFunc(obj: Account):Unit= {
  obj match {
    case User(name) =>
      println("Name: " + name)
      println("Email: none")
      println("Role: " + obj.role)

    case SuperUser(name, email) =>
      println("Name: " + name)
      println("Email: " + email)
      println("Role: " + obj.role)

    case SomethingStrange() =>
      println("Name: ??")
      println("Email: ??")
      println("Role: ??")

  }
}

matcherFunc(User("NiceName"))
matcherFunc(SuperUser("NiceName^2","NiceName2012@mail.ru"))
matcherFunc(SomethingStrange())
Moderator("123").Ulta(User("NiceName"))