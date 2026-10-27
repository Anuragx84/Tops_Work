//1.Write a Java program using a for loop to display the daily step count for each day of a week, where the step counts are stored in an array.
public class Task1 {
    public static void main(String[] args){
        int[] stepCount = {2456,3254,1245,6315,2154,3214,1246};
        System.out.println("Daily steps : ");
        for(int i=0;i<stepCount.length;i++){
            System.out.println(stepCount[i]);
        }
    }
}
