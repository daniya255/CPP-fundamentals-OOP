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
    Queue<string> printerQueue(5);


    printerQueue.enqueue("Assignment_Final.pdf");
    printerQueue.enqueue("Wedding_Invite_Draft.png");
    printerQueue.enqueue("Company_Report_2026.docx");

    cout << "Current jobs in line: " << printerQueue.size() << endl;

    while (!printerQueue.isEmpty()) {
        string currentJob = printerQueue.Front();
        
        cout << "\n>> Now Printing: " << currentJob << "..." << endl;
        cout << "Printing complete." << endl;

        printerQueue.dequeue();

        if (!printerQueue.isEmpty()) {
            cout << "Next in line: " << printerQueue.Front() << endl;
        } else {
            cout << "Queue is now empty. Printer is idle." << endl;
        }
    }

    return 0;
}