#include<iostream>
#include<vector>
using namespace std;

class myStack {
    vector<int> arr;

public:

    // push operation
    void push(int x) {
        arr.push_back(x);
    }

    // pop operation
    int pop() {
        if (arr.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    // peek operation
    int peek() {
        if (arr.empty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr.back();
    }

    // check if stack is empty
    bool isEmpty() {
        return arr.empty();
    }
    
    // current size
    int size() {
        return arr.size();
    }
};

int main() {
    myStack st;

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << endl;

    // checking top element
    cout << "Top element: " << st.peek() << endl;

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;
    
    // checking current size
    cout << "Current size: " << st.size() << endl;
}