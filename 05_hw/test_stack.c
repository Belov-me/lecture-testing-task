#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


// Тесты
void test_initStack() {
    Stack stack;
    initStack(&stack);
    assert(stack.top == NULL);
    printf("Test initStack passed.\n");
}

void test_createNode() {
    Node* node = createNode(42);
    assert(node != NULL && node->data == 42 && node->next == NULL);
    free(node);
    printf("Test createNode passed.\n");
}

void test_push() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    assert(stack.top != NULL);
    assert(stack.top->data == 30);
    assert(stack.top->next->data == 20);
    assert(stack.top->next->next->data == 10);

    printf("Test push passed.\n");
}

void test_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    pop(&stack);

    assert(stack.top != NULL);
    assert(stack.top->data == 10);

    pop(&stack);

    assert(stack.top == NULL);

    printf("Test pop passed.\n");
}

void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 20);
    assert(result != NULL);
    assert(result->data == 20);

    result = searchByValue(&stack, 40);
    assert(result == NULL);

    printf("Test searchByValue passed.\n");
}

void test_getTop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    Node* topElement = getTop(&stack);
    assert(topElement != NULL);
    assert(topElement->data == 20);

    pop(&stack);
    topElement = getTop(&stack);
    assert(topElement != NULL);
    assert(topElement->data == 10);

    printf("Test getTop passed.\n");
}

void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    traverseStack(&stack);

    printf("Test traverseStack passed.\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);

    printf("Test isEmpty passed.\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20); // Элемент по индексу 1 найден

    result = searchByIndex(&stack, 0);
    assert(result != NULL && result->data == 30); // Элемент по индексу 0 найден

    result = searchByIndex(&stack, 5);
    assert(result == NULL); // Индекс вне пределов

    // Проверка на пустом стеке
    Stack emptyStack;
    initStack(&emptyStack);
    result = searchByIndex(&emptyStack, 0);
    assert(result == NULL);
    printf("Test search_by_index passed\n");
    destroyStack(&stack);
}

void test_DestroyStack() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    destroyStack(&stack);
    assert(stack.top == NULL); // После уничтожения вершина должна быть NULL
    printf("Test destroy_stack passed\n");
}

int main() {
    test_createNode();
    test_initStack();
    test_push();
    test_pop();
    test_searchByValue();
    test_searchByIndex();
    test_DestroyStack();
    test_getTop();
    test_traverseStack();
    test_isEmpty();

    printf("All tests passed!\n");
    return 0;
}
