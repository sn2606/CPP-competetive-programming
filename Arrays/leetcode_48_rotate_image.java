// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.

public class leetcode_48_rotate_image {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int r = n / 2;
        int c = n / 2;
        int temp;

        // System.out.println(c);
        r = (n % 2 == 1) ? r + 1 : r;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
}
