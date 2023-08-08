#include <iostream>
#include <stack>
#include <stdexcept>

class StackQueue {
private:
    std::stack<int> stackA;
    std::stack<int> stackB;

public:
    // Enqueue operation
    void enQueue(int element) {
        stackA.push(element);
    }

    // Dequeue operation
    int deQueue() {
        if (stackB.empty()) {
            if (stackA.empty()) {
                throw std::runtime_error("Queue is empty.");
            }
            transfer();
        }
        int frontElement = stackB.top();
        stackB.pop();
        return frontElement;
    }

private:
    // Transfer elements from stackA to stackB
    void transfer() {
        while (!stackA.empty()) {
            stackB.push(stackA.top());
            stackA.pop();
        }
    }
};

int main() {
    StackQueue stackQueue;

    stackQueue.enQueue(1);
    stackQueue.enQueue(2);
    stackQueue.enQueue(3);

    std::cout << stackQueue.deQueue() << std::endl;
    std::cout << stackQueue.deQueue() << std::endl;

    stackQueue.enQueue(4);

    std::cout << stackQueue.deQueue() << std::endl;
    std::cout << stackQueue.deQueue() << std::endl;

    return 0;
}
