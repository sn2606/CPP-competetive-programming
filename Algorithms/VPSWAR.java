// Variabla Precision SWAR algorithm

import java.util.Scanner;

public class VPSWAR {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = n * 0x01010101;
        n = n >> 24;

        System.out.println(n);

        s.close();
        
    }
}