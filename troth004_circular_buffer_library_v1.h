/* 
 * File:   troth004_lab6a_circular_buffer_library_v001.h
 * Author: ryoth
 *
 * Created on November 4, 2024, 10:34 AM
 */

#ifndef TROTH004_CIRCULAR_BUFFER_LIBRARY_V1_H
#define	TROTH004_CIRCULAR_BUFFER_LIBRARY_V1_H

#define BUFFER_SIZE 128  // Max size, assuming sample rate may change during runtime

extern int AVERAGE_COUNT;

extern volatile unsigned int inner_buffer[BUFFER_SIZE];
extern volatile unsigned int outer_buffer[BUFFER_SIZE];
extern volatile unsigned int inner_index;
extern volatile unsigned int outer_index;
extern volatile unsigned long inner_average;
extern volatile unsigned long outer_average;

#ifdef	__cplusplus
extern "C" {
#endif
    void init_buffers();                        // set all buffer vals to zero
	void put_val_inner(unsigned int new_val);	// add a new value to the buffer
    void put_val_outer(unsigned int new_val);	// add a new value to the buffer
    
#ifdef	__cplusplus
}
#endif

#endif	/* TROTH004_CIRCULAR_BUFFER_LIBRARY_H */

