// There are n different online courses numbered from 1 to n. You are given an array 
// courses where courses[i] = [durationi, lastDayi] indicate that the ith course should 
// be taken continuously for durationi days and must be finished before or on lastDayi.
// You will start on the 1st day and you cannot take two or more courses simultaneously.
// Return the maximum number of courses that you can take.

import java.util.PriorityQueue;
import java.util.Arrays;
import java.util.Comparator;

class Solution630 {
    public int scheduleCourse(int[][] courses) {
        int r = courses.length;
        int c = courses[0].length;

        if (r == 1)
            return 1;

        Arrays.sort(courses, new Comparator<int[]>() {
            @Override
            public int compare(int[] r1, int[] r2) {
                return r1[1] - r2[1];
            }
        });

        // for(int i = 0; i < r; i++){
        // for(int j = 0; j < c; j++){
        // System.out.print(courses[i][j] + " ");
        // }
        // System.out.println();
        // }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int time = 0;
        for (int i = 0; i < r; i++) {
            time += courses[i][0];
            pq.add(courses[i][0]);
            if (time > courses[i][1])
                time -= pq.poll();
        }

        return pq.size();
    }
}