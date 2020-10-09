import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // code
    Stack<String> postfix = new Stack<>();
    Stack<String> prefix = new Stack<>();
    Stack<Character> operators = new Stack<>();

    for (int i = 0; i < exp.length(); i++) {
      char ch = exp.charAt(i);

      if (ch == '(') {
        operators.push(ch);
      } else if ((ch >='0' && ch <= '9') || (ch >='a' && ch <= 'z') || (ch >='A' && ch <= 'Z'))  {
        postfix.push(ch + "");
        prefix.push(ch + "");
      } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        while (operators.size() > 0 && operators.peek() != '(' && precedence(ch) <= precedence(operators.peek())) {
          char op = operators.pop();

          String postval2 = postfix.pop();
          String postval1 = postfix.pop();
          postfix.push(postval1 + postval2 + op);

          String preval2 = prefix.pop();
          String preval1 = prefix.pop();
          prefix.push(op + preval1 + preval2);
        }

        operators.push(ch);
      } else if (ch == ')') {
        while (operators.size() > 0 && operators.peek() != '(') {
          char op = operators.pop();

          String postval2 = postfix.pop();
          String postval1 = postfix.pop();
          postfix.push(postval1 + postval2 + op);

          String preval2 = prefix.pop();
          String preval1 = prefix.pop();
          prefix.push(op + preval1 + preval2);
        }

        if (operators.size() > 0) {
          operators.pop();
        }
      }
    }

    while (operators.size() > 0) {
      char op = operators.pop();

      String postval2 = postfix.pop();
      String postval1 = postfix.pop();
      postfix.push(postval1 + postval2 + op);

      String preval2 = prefix.pop();
      String preval1 = prefix.pop();
      prefix.push(op + preval1 + preval2);
    }

    System.out.println(postfix.peek());
    System.out.println(prefix.peek());
  }

  public static int precedence(char op) {
    if (op == '+') {
      return 1;
    } else if (op == '-') {
      return 1;
    } else if (op == '*') {
      return 2;
    } else {
      return 2;
    }
  }
}
