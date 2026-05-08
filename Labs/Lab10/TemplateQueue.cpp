#include <iostream>
using namespace std;

template <class T>
class AbstractArray {
protected:
    T* data;
    int capacity;
    int currentSize;
public:
    AbstractArray(int cap) : capacity(cap), currentSize(0) {
        data = new T[capacity];
    }
    virtual void resize() = 0;
    virtual ~AbstractArray() {
        delete[] data;
    }
};

template <class T>
class Queue : public AbstractArray<T> {
private:
    int frontIndex;
    int rearIndex;

public:
    Queue(int cap) : AbstractArray<T>(cap) {
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isFull() {
        return this->currentSize == this->capacity;
    }

    bool isEmpty() {
        return this->currentSize == 0;
    }

    int size() {
        return this->currentSize;
    }

    T Front() {
        if (!isEmpty()) return this->data[frontIndex];
        throw runtime_error("Queue is empty");
    }

    T Rear() {
        if (!isEmpty()) return this->data[rearIndex];
        throw runtime_error("Queue is empty");
    }

    void resize() override {
        int newCapacity = this->capacity * 2;
        T* newData = new T[newCapacity];
        
        for (int i = 0; i < this->currentSize; i++) {
            newData[i] = this->data[(frontIndex + i) % this->capacity];
        }

        delete[] this->data;
        this->data = newData;
        this->capacity = newCapacity;
        frontIndex = 0;
        rearIndex = this->currentSize - 1;
    }

    void enqueue(T value) {
        if (isFull()) {
            resize();
        }
        rearIndex = (rearIndex + 1) % this->capacity;
        this->data[rearIndex] = value;
        this->currentSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % this->capacity;
        this->currentSize--;
    }
};

int main() {
    Queue<int> q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Size before resize: " << q.size() << endl;
    q.enqueue(40); 
    cout << "Size after resize: " << q.size() << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    q.dequeue();
    cout << "Front after dequeue: " << q.Front() << endl;

    return 0;
}