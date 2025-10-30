import java.util.Scanner;

public class SumAndAverage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input: number of elements
        System.out.print("Enter how many numbers: ");
        int n = sc.nextInt();

        int sum = 0;

        // Loop to read numbers and calculate sum
        System.out.println("Enter " + n + " numbers:");
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            sum += num;
        }

     
        double average = (double) sum / n;

     
        System.out.println("Sum = " + sum);
        System.out.println("Average = " + average);

        sc.close();
    }
}

