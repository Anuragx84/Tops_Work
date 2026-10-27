//4.Given this Java snippet: <br><br>int cartTotal = 450;<br>String status = (cartTotal >= 500) ? "Eligible for Free Delivery" : "Add more items for Free Delivery";<br><br>Use ChatGPT to generate two alternate ways to write this logic using if-else and nested conditions. Copy and implement both in your code, then comment on which one you find clearer.
class Task4{
    public static void main(String[] a){
        int cartTotal = 450;
        String status;

        //This one is clear and simple 
        if (cartTotal >= 500) {
            status = "Eligible for Free Delivery";
        } else {
            status = "Add more items for Free Delivery";
        }
        System.out.println(status);


        if (cartTotal >= 500) {
            if (cartTotal >= 1000) {
                status = "Eligible for Free Delivery";
            } else {
                status = "Eligible for Free Delivery";
            }
        } else {
            status = "Add more items for Free Delivery";
        }

        System.out.println(status);
    }
}