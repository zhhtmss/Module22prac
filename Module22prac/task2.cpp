#include <iostream>
#include <stdexcept>

class CharStack {
private:
	char* stack;
	int top;
	int capacity;
public:
	CharStack(int size = 100) : capacity(size), top(-1) {
		if (size <= 0) {
			throw std::invalid_argument("Size must be positive");
		}
		stack = new char[capacity];
		if (!stack) {
			throw std::runtime_error("Memory allocation failed");
		}
	}

	~CharStack() {
		delete[] stack;
	}

	CharStack(const CharStack& other) : capacity(other.capacity), top(other.top) {
		stack = new char[capacity];
		if (!stack) {
			throw std::runtime_error("Memory allocation failed");
		}
		for (int i = 0; i <= top; ++i) {
			stack[i] = other.stack[i];
		}
	}

	CharStack& operator=(const CharStack& other) {
		if (this != &other) {
			delete[] stack;
			capacity = other.capacity;
			top = other.top;
			stack = new char[capacity];
			if (!stack) {
				throw std::runtime_error("Memory allocation failed");
			}
			for (int i = 0; i <= top; ++i) {
				stack[i] = other.stack[i];
			}
		}
		return *this;
	}

	void push(char value) {
		if (isFull()) {
			throw std::overflow_error("Stack overflow\n");
		}
		stack[++top] = value;
	}

	char pop() {
		if (isEmpty()) {
			throw std::underflow_error("Stack underflow\n");
		}
		return stack[top--];
	}

	int count() {
		return top + 1;
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == capacity - 1;
	}

	void cleer() {
		top = -1;
	}

	char peek() {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty\n");
		}
		return stack[top];
	}

	void print() {
		if (isEmpty()) {
			std::cout << "Empty" << std::endl;
			return;
		}
		std::cout << "Stack elements: ";
		for (int i = 0; i <= top; ++i) {
			std::cout << stack[i] << ' ';
		}
		std::cout << "\n";
	}
};

int main()
{
	CharStack stack(5);

	stack.push('A');
	stack.push('B');
	stack.push('C');
	stack.push('D');
	stack.push('E');
	stack.print();

	std::cout << "Count: " << stack.count() << std::endl;
	std::cout << "Is Empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
	std::cout << "Is Full: " << (stack.isFull() ? "Yes" : "No") << std::endl;

	std::cout << "Peeking top element: " << stack.peek() << std::endl;
	std::cout << "Popping top element: " << stack.pop() << std::endl;
	std::cout << "Popping top element: " << stack.pop() << std::endl;
	stack.print();

	std::cout << "Clearing stack." << std::endl;
	stack.cleer();
	std::cout << "Count after clearing: " << stack.count() << std::endl;
	std::cout << "Is Empty after clearing: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
	stack.print();
	std::cout << "Pushing 'F' 'G' 'T' onto stack." << std::endl;
	stack.push('F');
	stack.push('G');
	stack.push('T');

	stack.print();
	std::cout << "Peeking top element: " << stack.peek() << std::endl;
	std::cout << "Popping top element: " << stack.pop() << std::endl;
	stack.print();

	try {
		std::cout << "Attempting to push 'H' and 'I' onto stack." << std::endl;
		stack.push('H');
		stack.push('I');
		stack.push('J'); 
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Popping all elements from stack." << std::endl;
		while (true) {
			std::cout << "Popped: " << stack.pop() << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "Attempting to peek top element of empty stack." << std::endl;
		stack.peek();
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
