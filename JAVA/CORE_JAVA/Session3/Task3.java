//3.Build a Java program called ZomatoCuisineFilter that takes a string input for cuisine ('Indian', 'Chinese', 'Italian', 'Mexican') and uses a switch statement to print a list of 2-3 sample restaurants for the selected cuisine. Print 'Cuisine Not Found' for any other input.

import java.util.Scanner;

public class Task3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter cuisine : ");
        String cuisine = sc.next();
        switch(cuisine){
            case "Indian" : 
                System.out.println("1. Shree Krishna Restaurant");
                System.out.println("2. Indian Coffee House");
                System.out.println("3. Haldiram's");
                break;
            
            case "Chinese" : 
                System.out.println("1. Mainland China");
                System.out.println("2. Chinese Wok");
                System.out.println("3. Wow! China");
                break;

            case "Italian" : 
                System.out.println("1. Domino's Pizza");
                System.out.println("2. Pizza Hut");
                System.out.println("3. La Pino'z Pizza");
                break;

            case "Mexican" : 
                System.out.println("1. California Burrito");
                System.out.println("2. Taco Bell");
                System.out.println("3. Chili's");
                break;

            default :
                System.out.println("Cuisine Not found");
        }
    }
}