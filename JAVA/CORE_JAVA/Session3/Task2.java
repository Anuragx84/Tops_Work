//2.Create a Java class MovieAgeGate that asks the user for their age and uses an if-else-if ladder to print 'Kids Section' if age < 13, 'Teen Section' if age is between 13 and 17, and 'Adult Section' if age is 18 or above.<br><br><em><strong>Hint:</strong> Use Scanner for input and nested if-else for decision flow.</em>
import java.util.Scanner;

public class Task2{
    public static void main(String[] a){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter your age : ");
        int age  = s.nextInt();
        if(age>=18){
            System.out.println("Adult Section");
        }
        else if(age>=13){
            System.out.println("Teen Section");
        }
        else if(age<13){
            System.out.println("Kids Section");
        }
    }
}