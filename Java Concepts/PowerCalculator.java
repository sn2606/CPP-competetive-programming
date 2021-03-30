/*
 * Complete the function power in class MyCalculator and return the appropriate result
 * after the power operation or an appropriate exception as detailed above.
 * Exception handling question
 */

import java.lang.Math;
import java.util.Scanner;

public class PowerCalculator {

    static long power(int n, int p) throws Exception {
        if(n == 0 && p == 0){
            throw new Exception("N and P should not be negative");
        }else if (n < 0 || p < 0){
            throw new Exception("N or P should nt be negative");
        }else {
            return (long)Math.pow(n, p);
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = s.nextInt();
        // System.out.println();
        System.out.print("Enter p: ");
        int p = s.nextInt();

        try {
            System.out.println("n raised to p: " + power(n, p));
        } catch (Exception e) {
            System.out.println(e);
        }  
        
        s.close();        
    }    
}
