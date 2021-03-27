import java.util.Scanner;

public class BubbleSort {

    static void bubbleSort(int A[], int n){
        boolean sorted = false;
        int temp;

        while(!sorted) {
            sorted = true;

            for(int i = 0; i < n-1; i++){
                if(A[i] > A[i+1]){
                    temp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = temp;
                    sorted = false;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }

        for(int k : arr) {
            System.out.print(k + " ");
        }

        bubbleSort(arr, n);

        System.out.println("");
        for(int k : arr) {
            System.out.print(k + " ");
        }

        s.close();
    }    
}
