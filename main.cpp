#include <iostream>
#include "copy_stack.h"

int main() {
    std::stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::stack<int> copy;

    copy_stack(stack, copy);

    return 0;
}
