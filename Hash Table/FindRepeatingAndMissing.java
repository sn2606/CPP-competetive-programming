// 1. You are given an arrya of integers whose size is n.
// 2. The array contains elements from 1 to n. It is given that one of the numbers
// is missing and one of the numbers is repeated.
// 3. You have to print repeating and missing element respectively.

import java.util.*;
import java.io.*;

public class FindRepeatingAndMissing {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        if (n == 1) {
            System.out.println(-1);
            return;
        }

        int[] arr = new int[n];
        int[] hashT = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
            hashT[arr[i] - 1]++;
        }

        int missing = 0, repeating = 0;

        for (int i = 0; i < n; i++) {
            if (hashT[i] == 0) {
                missing = i + 1;
            }

            if (hashT[i] > 1) {
                repeating = i + 1;
            }
        }

        System.out.println(repeating);
        System.out.println(missing);
    }
}
