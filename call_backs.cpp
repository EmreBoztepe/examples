#include <stdio.h>    


typedef char uint8_t;
typedef unsigned int uint16_t;

uint16_t sum(uint8_t a, uint8_t b) {
    return a + b;
}
uint16_t mul(uint8_t a, uint8_t b) {
    return a * b;
}
uint16_t arithm_op (uint16_t (*callback_func)(uint8_t, uint8_t),uint8_t a, uint8_t b) {   
    return callback_func(a,b);
}

int main() {
    printf("%d",arithm_op(mul,4,10)); 		/* Multiplication: 4x10*/
    printf("%d",arithm_op(sum,9,5));  					/*  Addition: 9+5 */
    
    return 0;
}
