/**
 * @file circular_buffer_library.h
 * @brief This file contains the implementation of the circular buffer used to smooth the output angle of the servos driving the brachiograph.
 * @author Justin Troth
 */

#ifndef CIRCULAR_BUFFER_LIBRARY_H
#define	CIRCULAR_BUFFER_LIBRARY_H

/**
 * @brief Defines the maximum buffer size. 
 *  This value can be used to accommodate changes in the sample rate during runtime.
 */
#define BUFFER_SIZE 128

/**
 * @brief The number of values to average. 
 *  This value determines the size of the averaging window.
 */
extern int AVERAGE_COUNT;

/**
 * @brief Buffer to store inner data samples. 
 *  Size is defined by BUFFER_SIZE.
 */
extern volatile unsigned int inner_buffer[BUFFER_SIZE];

/**
 * @brief Buffer to store outer data samples. 
 *  Size is defined by BUFFER_SIZE.
 */
extern volatile unsigned int outer_buffer[BUFFER_SIZE];

/**
 * @brief Index for the current position in the inner buffer.
 */
extern volatile unsigned int inner_index;

/**
 * @brief Index for the current position in the outer buffer.
 */
extern volatile unsigned int outer_index;

/**
 * @brief The calculated average of the values in the inner buffer.
 */
extern volatile unsigned long inner_average;

/**
 * @brief The calculated average of the values in the outer buffer.
 */
extern volatile unsigned long outer_average;


#ifdef	__cplusplus
extern "C" {
#endif
    /**
    * @brief Initializes buffers for the inner and outer angles.
    *   Sets all values in the allotted memory to 0.
    */
    void init_buffers();
    
    /**
    * @brief Puts a value into the inner angle buffer. Increments its pointer by 1, or rolls over to the start.
    * 
    * @param new_val The unsigned int to put in the buffer.
    */
	void put_val_inner(unsigned int new_val);
    
    /**
    * @brief Puts a value into the outer angle buffer. Increments its pointer by 1, or rolls over to the start.
    * 
    * @param new_val The unsigned int to put in the buffer.
    */    
    void put_val_outer(unsigned int new_val);
    
#ifdef	__cplusplus
}
#endif

#endif	/* CIRCULAR_BUFFER_LIBRARY_H */

