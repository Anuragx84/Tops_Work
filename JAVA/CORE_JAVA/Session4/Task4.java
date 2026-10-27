//4.Build a nested loop that prints a table showing the number of likes received on Instagram posts for each week (4 weeks, 7 days per week).<br><br><em><strong>Hint:</strong> Use an outer loop for weeks and an inner loop for days, and generate random like counts for each cell.</em>
class Task4{
    public static void main(String[] args){
        int like[][] = new int[4][7];
        for(int i=0;i<like.length;i++){
            System.out.print("Week : " + (i+1) + " ->\t");
            for(int j=0;j<like[i].length;j++){
                like[i][j] = (int) (Math.random()*1000);
                System.out.print(like[i][j] + "\t");
            }
            System.out.println();
        }
    }
}