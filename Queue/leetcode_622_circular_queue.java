// Design your implementation of the circular queue. The circular queue is a linear data structure 
// in which the operations are performed based on FIFO (First In First Out) principle and the last 
// position is connected back to the first position to make a circle. It is also called "Ring Buffer".

// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
// In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a 
// space in front of the queue. But using the circular queue, we can use the space to store new values.

// Implementation the MyCircularQueue class:

// MyCircularQueue(k) Initializes the object with the size of the queue to be k.
// int Front() Gets the front item from the queue. If the queue is empty, return -1.
// int Rear() Gets the last item from the queue. If the queue is empty, return -1.
// boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
// boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
// boolean isEmpty() Checks whether the circular queue is empty or not.
// boolean isFull() Checks whether the circular queue is full or not.


class MyCircularQueue {
    int cqueue[];
    int k;
    int front;
    int rear;
    
    public MyCircularQueue(int k) {
        this.k = k;
        cqueue = new int[this.k];
        for(int i = 0; i < k; i++){
            cqueue[i] = -1;
        }
        front = -1;
        rear = -1;
    }
    
    public boolean enQueue(int value) {
        if(front == rear && front == -1){
            front++;
            rear = (rear+1)%k;
            cqueue[rear] = value;
            return true;
        }else{
            if((rear+1)%k == front){
                return false;
            }else{
                rear = (rear+1)%k;
                cqueue[rear] = value;
                return true;
            }
        }       
    }
    
    public boolean deQueue() {
        if(front == rear && front != 0){
            return false;
        }else{
            if((front+1)%k == rear){
                cqueue[front] = -1;
                cqueue[0] = cqueue[rear];
                front = 0;
                rear = 0;
                return true;
            }else if(front == rear && front == 0){
                cqueue[front] = -1;
                front = -1;
                rear = -1;
                return true;
            }else{
                cqueue[front] = -1;
                front = (front + 1)%k;
                return true;
            }
        }
        
    }
    
    public int Front() {
        if(front == rear && front == -1){
            return -1;
        }else{
            return cqueue[front];
        }
        
    }
    
    public int Rear() {
        if(front == rear && front == -1){
            return -1;
        }else{
            return cqueue[rear];
        }
        
    }
    
    public boolean isEmpty() {
        if(front == rear && front == -1){
            return true;
        }else{
            return false;
        }
        
    }
    
    public boolean isFull() {
        if((rear + 1)%k == front){
            return true;
        }else{
            return false;
        }        
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */