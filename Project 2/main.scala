import scala.io.StdIn.readLine

sealed trait Tree[+A]
case object Nil extends Tree[Nothing]
case class Leaf[A](value: A) extends Tree[A]
case class Branch[A](value: A, var left: Tree[A], var right: Tree[A]) extends Tree[A]


object Methods
{

 def add(main_string: String): Tuple2[Tree[Char], String] =
  {

    def go(string: String): Tuple2[Tree[Char], String] =
    {
      if (string.charAt(0).equals('+') || string.charAt(0).equals('-') || string.charAt(0).equals('*') || string.charAt(0).equals('/'))
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        return (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      else return (Leaf(string.charAt(0)), string.substring(1))
    }

    go(main_string)

  }


  def eval(root: Tree[Char]): Double =
  {

    def go(node: Tree[Char]): Double = node match
    {

      case Branch(value, left, right) =>
      {
        if (value.equals('+'))
        {
          val left_value = eval(left)
          val right_value = eval(right)
          return (left_value + right_value)
        }
  
        if (value.equals('-'))
        {
          val left_value = eval(left)
          val right_value = eval(right)
          return (left_value - right_value)
        }
  
        if (value.equals('*'))
        {
          val left_value = eval(left)
          val right_value = eval(right)
          return (left_value * right_value)
        }
  
        else
        {
          val left_value = eval(left)
          val right_value = eval(right)
          return (left_value / right_value)
        }
      }
  
      case Leaf(value) => 
      {
        val number = value.toInt-'0'
        return number
      }
  
      case _ => return 0

    }

    go(root)

  }

}


object Main
{

  def main(args: Array[String]): Unit =
  {
    print("This is an example of rpn with a tree data structure: ")
    val string = "*+95-78"
    println(string)

    val root = Methods.add(string)

    print("The result is -> ")
    print(Methods.eval(root._1))
    
    print('\n')
    print("Now write your problem: ")

    val user = readLine()
    val users_root = Methods.add(user)
    print("The result is -> ")
    print(Methods.eval(users_root._1))
    print('\n')
    
  }

}
