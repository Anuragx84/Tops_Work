// 4. Write a Java program that takes an integer representing the number of unread WhatsApp messages and prints 'No new messages', 'Few messages', or 'Too many messages' using the ternary operator.<br><br><em><strong>Hint:</strong> Use nested ternary operators for three possible outputs.</em>
import java.util.Scanner;

class Task4{
    public static void main(String[] arg){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of unread messsages : ");
        int noMessage = s.nextInt();
        System.out.println(
        (noMessage == 0) ? "No new messages" :         
        (noMessage <= 50) ?  "Few messages" : 
        "Too many messages"
        ); 
    }
}