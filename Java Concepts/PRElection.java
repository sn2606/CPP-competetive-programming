import java.util.Random;

// Three students A, B and C of B.Tech- II year contest for the PR election. 
// With the total strength of 240 students in II year, simulate the vote casting 
// by generating 240 random numbers (1 for student A, 2 for B and 3 for C) and 
// store them in an array. Create four threads to equally share the task of counting 
// the number of votes cast for all the three candidates. Use synchronized method or 
// synchronized block to update the three count variables. 
// The main thread should receive the final vote count for all three contestants and 
// hence decide the PR based on the values received.

class CountVotes {
    int A = 0;
    int B = 0;
    int C = 0;

    synchronized void counting(int arr[]) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == 1){
                A++;
            }else if(arr[i] == 2) {
                B++;
            }else if(arr[i] == 3) {
                C++;
            }
            arr[i] = -1;
        }
    }
}


public class PRElection {
    public static void main(String[] args) {
        Random rand = new Random();
        int votes[] = new int[240];

        for(int i = 0; i < 240; i++) {
            // rand.nextInt(bound) produces a random integer between 0 and bound-1
            // adding 1 would make that range to 1 and bound
            votes[i] = rand.nextInt(3) + 1;
        }

        // for(int i : votes) {
        //     System.out.println(i);
        // }

        CountVotes counter = new CountVotes();

        new Thread("Counter Thread 1"){
            public void run() {
                counter.counting(votes);
            }
        }.start();

        new Thread("Counter Thread 2"){
            public void run() {
                counter.counting(votes);
            }
        }.start();

        new Thread("Counter Thread 3"){
            public void run() {
                counter.counting(votes);
            }
        }.start();

        new Thread("Counter Thread 4"){
            public void run() {
                counter.counting(votes);
            }
        }.start();

        System.out.println("A: " + counter.A);
        System.out.println("B: " + counter.B);
        System.out.println("C: " + counter.C);
        System.out.println((counter.A + counter.B + counter.C));
    }
    
}
