import java.util.Scanner;

public class BoyerMoorVoting{
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }

        int count = 0;
        int element = -1;

        for(int i : arr){
            if(count == 0){
                count = 1;
                element = i;
            }else if(element == i){
                count++;
            }else{
                count--;
            }
        }

        count = 0;
        for(int i : arr){
            if(i == element){
                count++;
            }
        }

        if(count > n/2){
            System.out.println("Majority Element: " + element);
        }else{
            System.out.println("No Majority Element");
        }

        s.close();        
    }
}