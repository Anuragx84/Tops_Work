//1.Write a Java program called FoodieBalanceChecker that takes an integer input for wallet balance and prints 'Low Balance Warning.' if the balance is less than 100, otherwise prints 'Sufficient Balance.' using an if-else statement.
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter waaallet balance : ");
        double walletBalance = s.nextDouble();
        if(walletBalance>100){
            System.out.println("Sufficient Balance");
        }
        else{
            System.out.println("Low balance");
        }
    }    
}
