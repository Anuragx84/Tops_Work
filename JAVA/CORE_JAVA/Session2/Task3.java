//3.Create a Java snippet that checks if a user can book a movie ticket on BookMyShow: declare variables for userAge (int) and hasPaymentMethod (boolean). Use logical and relational operators to print 'Booking allowed' only if the user is 18 or older and has a payment method linked.
import java.util.Scanner;

class Task3{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter your age : ");
        int userAge = s.nextInt();
        System.out.println("Have you any payment Method (true/false) : ");
        boolean hasPaymentMethod = s.nextBoolean();
        if(hasPaymentMethod && userAge>=18){
            System.out.println("Booking Allowed");
        }
        else{
            System.out.println("Booking Not Allowed");
        }
    }
}