#include "libpower.h"
#include "libresistance.h"

float calc_power_r(float volt, float resistance) {
    
    float result = 0;
    
    if(volt == 0 || resistance == 0) {
        return 0;
    }
    
    result = (volt * volt) / resistance;
    
    return result;
}

float calc_power_i(float volt, float current) {
    
    if(volt == 0 || current == 0) {
        return 0;
    }
    
    float result = 0;
    
    result = volt * current;
    
    return result;
}