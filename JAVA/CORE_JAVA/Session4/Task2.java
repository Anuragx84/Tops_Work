//2.Simulate a Zomato-style order summary: Given an array of order amounts for a month, use a while loop to calculate and print the total amount spent.
class Task2{
    public static void main(String[] argss){
        double array[] = {450, 1200, 750, 300, 2000, 950, 1500};
        double sum = 0;
        int i=0;
        while(i<array.length){
            sum += array[i];
            i++;
        }
        System.out.println("Total amount : " + sum);
    }
}