import scala.io.StdIn.readLine
import scala.math._

sealed trait Tree[+A]
case object Nil extends Tree[Nothing]
case class Leaf[A](value: A) extends Tree[A]
case class Branch[A](value: A, var left: Tree[A], var right: Tree[A]) extends Tree[A]


object Methods
{

 def add(main_string: String): Tuple2[Tree[Char], String] =
  {

    def go(string: String): Tuple2[Tree[Char], String] = string.charAt(0) match
    {
      case '+' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '-' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '*' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '/' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '@' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '#' =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case '2' if ((string.length() > 2) && !string.charAt(1).equals('+') && !string.charAt(1).equals('-') && !string.charAt(1).equals('*') && !string.charAt(1).equals('/') && !string.charAt(1).equals('@') && !string.charAt(2).equals('+') && !string.charAt(2).equals('-') && !string.charAt(2).equals('*') && !string.charAt(2).equals('/') && !string.charAt(2).equals('@')) =>
      {
        val left = add(string.substring(1))
        val right = add(left._2)
        (Branch(string.charAt(0), left._1, right._1), right._2)
      }
      case _ => (Leaf(string.charAt(0)), string.substring(1))
    }

    go(main_string)

  }


  def eval(root: Tree[Char]): Double =
  {

    def go(node: Tree[Char]): Double = node match
    {

      case Branch(value, left, right) =>
      {

        val left_value = eval(left)
        val right_value = eval(right)
        
        value match
        {
            case '+' => left_value + right_value
            case '-' => left_value - right_value
            case '*' => left_value * right_value
            case '/' => left_value / right_value
            case '@' => pow(left_value, right_value)
            case '#' =>
            {
              if (left_value > right_value) left_value + right_value
              else left_value - right_value
            }
            case '2' => left_value / right_value
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
    print("Now write your problem (prefix or postfix): ")

    val user = "+45223" // readLine()
    print(user)
    val users_root = Methods.add(user)
    print('\n')
    print("The result is -> ")
    print(Methods.eval(users_root._1))
    print('\n')

    print("Now write your problem (prefix or postfix): ")
    val user_new = "#45" // readLine()
    print(user_new)
    print('\n')
    val users__new_root = Methods.add(user_new)
    print("The result is -> ")
    print(Methods.eval(users__new_root._1))
    print('\n')
    
  }

}
