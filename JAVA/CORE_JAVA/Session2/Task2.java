//2.Write a Java program that takes a user's Zomato wallet balance (double) and applies a 10% cashback if the balance is above ₹500, otherwise no cashback. Use arithmetic and relational operators to calculate and display the final balance.
import java.util.Scanner;
class Task2{
    public static void main(String[] a){
        Scanner scn = new Scanner(System.in);
        System.out.println("user's Zomato wallet balance : ");
        double walletBalance = scn.nextDouble();        
        if(walletBalance>500){
            System.out.println("You are eligible for 10% cashback");
        }
        else{
            System.out.println("You are not eligible for any CashBack");
        }
    }
}