#include <stdio.h>
#include "libresistance.h"


float calc_resistance(int count, char conn, float *array){
    float result = 0.0;
    
    if(conn != 'P' && conn != 'S') {
        return -1;
    }
    
    if(array == 0) {
        return -1;
    }
    
    for(int i = 0; i < count; i++) {
        if(conn == 'P') {
            if(array[i] == 0){
                return 0;
            }
            result += (1/array[i]);
            if(i == count-1){
                result = 1/result;
            }  
        } 
        else{
            result += array[i];
        }
    }
    return result;  
}