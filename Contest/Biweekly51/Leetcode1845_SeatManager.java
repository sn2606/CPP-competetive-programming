package Biweekly51;

// Design a system that manages the reservation state of n seats that are numbered from 1 to n.
// Implement the SeatManager class:
// SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. 
// All seats are initially available.
// int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
// void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

class SeatManager {
    int[] seats;
    int available;
    int n;

    public SeatManager(int n) {
        this.n = n;
        seats = new int[n];
        available = 1;
    }
    
    public int reserve() {
        // seats[available - 1] = -1;
        for(int i = available-1; i < n; i++){
            if(seats[i] == 0){
                available = i+1;
                break;
            }
        }
        seats[available - 1] = -1;
        return available;
    }
    
    public void unreserve(int seatNumber) {
        seats[seatNumber - 1] = 0;
        available = seatNumber < available ? seatNumber : available;        
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */