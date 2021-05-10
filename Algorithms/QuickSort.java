public class QuickSort {
    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int pos = low - 1;
        int temp;

        for (int i = low; i <= high; i++) {
            if (arr[i] < pivot) {
                pos++;
                temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
            }
        }

        temp = arr[pos + 1];
        arr[pos + 1] = arr[high];
        arr[high] = temp;

        // System.out.println(pos + 1);

        return pos + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pos = partition(arr, low, high);
            quickSort(arr, low, pos - 1);
            quickSort(arr, pos + 1, high);
        }
    }

    static void printArr(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = { 12, 16, 1, 18, 9, 8, 45, 20, 76 };
        int n = 9;
        quickSort(arr, 0, 8);
        printArr(arr, n);
    }
}
