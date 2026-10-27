//5.Demonstrate both implicit and explicit type casting in Java by converting a float rating (e.g., 4.7) to an int and then back to double. Print all values to show the effect of casting.<br><br><em><strong>Constraint:</strong> Do not use any external libraries; use only standard Java casting syntax.</em>
class Task5{
    public static void main(String[] args){
        float floatRating = 4.7f;
        System.out.println("float Rating : " + floatRating);

        //explicit casting 
        int intRating = (int) floatRating;
        System.out.println("explicit float to int : " + intRating);

        
        //implicit casting 
        double doubleRating = intRating;
        System.out.println("implicit int to double : " + doubleRating);
        
    }
}