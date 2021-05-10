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

        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }

        Arrays.sort(arr);
        int missing = 0, repeating = 0, k = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + k) {
                if (i > 0 && arr[i] == arr[i - 1]) {
                    repeating = arr[i];
                    k--;
                    continue;
                } else {
                    missing = i + 1;
                    break;
                }
            }
        }

        if (missing == 0) {
            missing = n;
        }

        if (repeating == 0) {
            for (int i = 1; i < n; i++) {
                if (arr[i] == arr[i - 1]) {
                    repeating = arr[i];
                    break;
                }
            }
        }

        System.out.println(repeating);
        System.out.println(missing);
    }
}
