#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h" 

// Измерение времени для push
void benchmark_push(int num_operations) {
    Stack stack;
    clock_t start_time = clock();

    for (int i = 0; i < num_operations; ++i) {
        push(&stack, i); 
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Push: %d operations took %f seconds\n", num_operations, elapsed_time);
}

// Измерение времени для pop
void benchmark_pop(int num_operations) {
    Stack stack;
    for (int i = 0; i < num_operations; ++i) {
        push(&stack, i); // Заполняем стек
    }

    clock_t start_time = clock();

    for (int i = 0; i < num_operations; ++i) {
        pop(&stack); 
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Pop: %d operations took %f seconds\n", num_operations, elapsed_time);
}

int main() {
    int num_operations = 1000000; // Количество операций

    printf("Benchmarking stack operations...\n");
    benchmark_push(num_operations);
    benchmark_pop(num_operations);

    return 0;
}
