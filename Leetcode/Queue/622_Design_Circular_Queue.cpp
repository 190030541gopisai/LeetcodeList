// 622. Design Circular Queue
class MyCircularQueue {
    int size, *arr, f, r, eleCount;
public:
    MyCircularQueue(int k) {
        eleCount = 0;
        f = 0; 
        r = -1;
        size = k;
        arr = new int[size];
        memset(arr, -1, k * sizeof(int));
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        eleCount++;
        r = (r + 1) % size;
        arr[r] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        eleCount--;
        arr[f] = -1;
        f = (f+1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[r];
    }
    
    bool isEmpty() {
        return eleCount == 0; 
    }
    
    bool isFull() {
        return eleCount == size;
    }
};
