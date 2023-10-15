#ifndef SDP_COPY_STACK_H
#define SDP_COPY_STACK_H

#include <stack>

template<typename T>
void copy_stack(std::stack<T>& stack, std::stack<T>& copy) {
    // Remove all elements of the copy stack, if there are any
    while(!copy.empty()) {
        copy.pop();
    }

    std::stack<T> temp;
    while(!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }
    while(!temp.empty()) {
        stack.push(temp.top());
        copy.push(temp.top());
        temp.pop();
    }
}


#endif //SDP_COPY_STACK_H
