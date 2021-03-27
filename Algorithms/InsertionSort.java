import java.util.Scanner;

public class InsertionSort {
    static void insertionSort(int A[], int n){
        if(n == 0 || n == 1) {
            return;
        }

        int key;
        for(int i = 1; i < n; i++) {
            key = A[i];
            for(int j = i-1; j >= 0; j--) {
                if(A[j] > key){
                    A[j+1] = A[j];
                    A[j] = key;
                }else{
                    break;
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

        insertionSort(arr, n);

        System.out.println("");
        for(int k : arr) {
            System.out.print(k + " ");
        }

        s.close();
    }
}
