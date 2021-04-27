// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
// While moving from building i to building i+1 (0-indexed),
// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

import java.util.PriorityQueue;

public class Leetcode_1642_furthest_building {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue <Integer> diff = new PriorityQueue <Integer>();
        
        for(int i = 0; i < heights.length-1; i++){
            int d = heights[i+1] - heights[i];
            if(d > 0){
                diff.add(d);
            }
            
            if(diff.size() > ladders){
                bricks -= diff.poll();
            }
            
            if(bricks < 0){
                return i;
            }            
        }
        
        return heights.length-1;
    }
}
