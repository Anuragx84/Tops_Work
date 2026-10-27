//5.Write a Java program that iterates through an array of cricket scores (one per match) and skips any score below 50 using continue, but stops processing completely if a score of 200 is found using break.

class Task5 {
    public static void main(String[] args) {
        int[] Score = new int[999];
        int i = -1;

        do {
            i++;
            Score[i] = (int) (Math.random() * 1000);

            if (Score[i] == 200) {
                System.out.println("200 found. Stopping.");
                break;
            }

            if (Score[i] < 50) {
                continue;
            }

            System.out.println(Score[i] + "\t" + i);

        } while (i < Score.length - 1);
    }
}
