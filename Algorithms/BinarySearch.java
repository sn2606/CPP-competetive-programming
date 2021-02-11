import java.util.Scanner;

// Search a sorted array by repeatedly dividing the search interval in half. 
// Begin with an interval covering the whole array. 
// If the value of the search key is less than the item in the middle of the interval, 
// narrow the interval to the lower half. Otherwise narrow it to the upper half. 
// Repeatedly check until the value is found or the interval is empty.

public class BinarySearch {

    int binarySearch(int arr[], int low, int high, int key){
        int mid;

        while(low <= high){

            mid = (low + high)/2;

            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] < key){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }

        int key = s.nextInt();

        BinarySearch bs = new BinarySearch();
        int ans = bs.binarySearch(arr, 0, n-1, key);

        if(ans == -1){
            System.out.println(key + " is not present int the array.");
        }else{
            System.out.println("Given key " + key + " is at index: " + ans);
        }

        s.close();       
    }
}