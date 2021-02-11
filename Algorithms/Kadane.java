import java.util.Scanner;

public class Kadane {

    public static void main (String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }
        s.close();
        
        System.out.println("Maximum contiguous sum is " + maxSubArraySum(arr));
    }
 
    static int maxSubArraySum(int a[])
    {
        int size = a.length;
        int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;
 
        for (int i = 0; i < size; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here){
                max_so_far = max_ending_here;
            }
            if (max_ending_here < 0){
                max_ending_here = 0;
            }
        }
        return max_so_far;
    }    
}
