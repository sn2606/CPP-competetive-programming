
class MyStack {
    int maxSize;
    int stck[];
    int pos;

    MyStack(int n){
        maxSize = n;
        stck = new int[maxSize];
        pos = 0;
    }

    synchronized void push(int num) {
        if(pos == maxSize){
            System.out.println("Stack Overflow!");
            this.display();
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted Exception");
            }
        }

        stck[pos] = num;
        System.out.println("Pushed " + num);
        pos++;
        notify();
    }

    synchronized int pop() {
        if(pos == 0){
            System.out.println("Stack Underflow");
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted Exception");
            }
        }

        pos--;
        int t = stck[pos];
        stck[pos] = 0;
        System.out.println("Popped " + t);
        notify();
        return t;
    }

    synchronized int getTop() {
        if(pos == 0){
            System.out.println("Stack Underflow");
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted Exception");
            }
        }

        int t = stck[pos - 1];
        return t;
    }

    synchronized void display() {
        System.out.println("Current stack: ");
        
        for(int i = 0; i < pos; i++){
            System.out.print(stck[i] + " ");
        }

        System.out.println("\n");
    }
}



public class StackMultithreading {
    public static void main(String[] args) {
        MyStack s = new MyStack(10);
        // int t;

        new Thread("Stack Thread 1"){
            public void run() {
                // int t;
                s.push(10);
                s.pop();
                s.pop();
                s.push(17);
                s.push(15);
                s.display();
                s.push(18);
                s.pop();
                s.display();
                s.pop();
            }
        }.start();

        new Thread("Stack Thread 2"){
            public void run() {
                s.push(18);
                s.push(19);
                s.pop();
                s.push(16);
                s.push(1);
                // s.pop();
                s.push(8);
                s.push(14);
                s.display();
                s.push(13);
                s.push(12);
                // s.pop();
                s.push(11);
                s.push(10);
                s.push(4);
                s.pop();
                s.pop();
                s.display();
            }
        }.start();
        
    }
}