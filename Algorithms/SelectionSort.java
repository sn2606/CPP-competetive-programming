import java.util.Scanner;

public class SelectionSort {
    static void selectionSort(int A[], int n){
        if(n == 0 || n == 1) {
            return;
        }

        int min, temp, idx;
        for(int i = 0; i < n; i++) {
            min = A[i];
            idx = i;
            for(int j = i; j < n; j++) {
                if (min > A[j]) {
                    min = A[j];
                    idx = j;
                }
            }

            temp = A[i];
            A[i] = min;
            A[idx] = temp;
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

        selectionSort(arr, n);

        System.out.println("");
        for(int k : arr) {
            System.out.print(k + " ");
        }

        s.close();
    }
}
