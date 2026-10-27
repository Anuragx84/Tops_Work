//3.Create a Java program that uses a do-while loop to repeatedly ask the user to enter their favorite music artist until they type 'exit', then print how many artists they entered.
import java.util.Scanner;
class Task3{
    public static void main(String[] args){
        Scanner sc  =new Scanner(System.in);
        String artist;
        int count = 0;
        do{
            System.out.println("Enter artist or (exit) for exit : ");
            artist = sc.next();
            count++;
            System.out.println(artist);
        }while(!artist.equals("exit"));
        System.out.println("You have entered total " + count + " artist");
    }
}