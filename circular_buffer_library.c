/**
 * @file example.c
 * @brief This file contains the implementation of ...
 * @author Justin Troth
 */

#include "xc.h"
#include "circular_buffer_library.h"

int AVERAGE_COUNT = 3;

volatile unsigned int inner_buffer[BUFFER_SIZE];
volatile unsigned int outer_buffer[BUFFER_SIZE];
volatile unsigned int inner_index = 0;
volatile unsigned int outer_index = 0;
volatile unsigned long inner_average = 0;
volatile unsigned long outer_average = 0;

// Initialize both buffers
void init_buffers() {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        inner_buffer[i] = 0;
        outer_buffer[i] = 0;
    }
}

// Add a new value to the inner buffer and calculate the inner average
void put_val_inner(unsigned int new_val) {
    inner_index++;
    if (inner_index >= BUFFER_SIZE) {
        inner_index = 0;
    }
    inner_buffer[inner_index] = new_val;

    unsigned long sum = 0;
    for (int i = 0; i < AVERAGE_COUNT; i++) {
        unsigned int buffer_index = (inner_index - i + BUFFER_SIZE) % BUFFER_SIZE;
        sum += inner_buffer[buffer_index];
    }
    inner_average = sum / AVERAGE_COUNT;
}

// Add a new value to the outer buffer and calculate the outer average
void put_val_outer(unsigned int new_val) {
    outer_index++;
    if (outer_index >= BUFFER_SIZE) {
        outer_index = 0;
    }
    outer_buffer[outer_index] = new_val;

    unsigned long sum = 0;
    for (int i = 0; i < AVERAGE_COUNT; i++) {
        unsigned int buffer_index = (outer_index - i + BUFFER_SIZE) % BUFFER_SIZE;
        sum += outer_buffer[buffer_index];
    }
    outer_average = sum / AVERAGE_COUNT;
}