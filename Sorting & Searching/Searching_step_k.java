// 1. You are given an array of integers. You are also given an element to be searched.
// 2. You are also given an integer k. The adjacent elements differ atmost 
// by difference of k.
// 3. We have to print the value of index if it is found, otherwise -1.


// import java.io.*;
import java.util.*;
// import java.text.*;
import java.lang.Math;
// import java.util.regex.*;

public class Searching_step_k {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        
        int x = s.nextInt();
        int k = s.nextInt();
        
        for (int i = 0; i < n; ) {
            if(arr[i] == x) {
                System.out.println(i);
                s.close();
                return;
            }else{
                i = i + (1 > (Math.abs(arr[i] - x)/k) ? 1 : (Math.abs(arr[i] - x)/k));
            }
        }
        
        System.out.println(-1);
        s.close();
    }
}