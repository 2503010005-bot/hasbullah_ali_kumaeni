#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 5;

struct Stack {
    int data[MAX];
    int top = -1;

    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(int no) {
        if (isFull()) {
            cout << "[!] Stack Penuh!" << endl;
        } else {
            top++;
            data[top] = no;
            cout << "[+] Stack: Push T" << setfill('0') << setw(3) << no << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "[!] Stack Kosong!" << endl;
        } else {
            cout << "[-] Stack: Pop T" << setfill('0') << setw(3) << data[top] << endl;
            top--;
        }
    }

    void peek() {
        if (!isEmpty()) {
            cout << "[i] Stack Peek: T" << setfill('0') << setw(3) << data[top] << endl;
        }
    }

    void display() {
        cout << "Isi Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << "[T" << setfill('0') << setw(3) << data[i] << "] ";
        }
        cout << endl;
    }
};

struct Queue {
    string data[MAX];
    int front = -1;
    int rear = -1;

    bool isFull() { return rear == MAX - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "[!] Queue Penuh!" << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            data[rear] = nama;
            cout << "[+] Queue: Enqueue " << nama << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "[!] Queue Kosong!" << endl;
        } else {
            cout << "[-] Queue: Dequeue " << data[front] << endl;
            front++;
        }
    }

    void peek() {
        if (!isEmpty()) {
            cout << "[i] Queue Peek: " << data[front] << endl;
        }
    }

    void display() {
        cout << "Isi Queue: ";
        for (int i = front; i <= rear; i++) {
            if (i == -1) break;
            cout << "[" << data[i] << "] ";
        }
        cout << endl;
    }
};

int main() {

    cout << "=== BAGIAN A: STACK (RIWAYAT TRANSAKSI) ===" << endl;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.peek();
    s.pop();
    s.pop();
    s.display();

    cout << "\n" << string(40, '=') << "\n" << endl;

    cout << "=== BAGIAN B: QUEUE (ANTRIAN PELANGGAN) ===" << endl;
    Queue q;
    q.enqueue("Ali");
    q.enqueue("Frian");
    q.enqueue("Elvan");
    q.peek();
    q.dequeue();
    q.enqueue("Fabian");
    q.display();

    return 0;
}

