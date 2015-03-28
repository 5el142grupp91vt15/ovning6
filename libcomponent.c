/*! \file libcomponent.c
    \brief Implementation of the library 
*/

#include "libcomponent.h"
#include <float.h>
#include <math.h>

int e_resistance(float orig_resistance, float *res_array)
{
	int N = 121;
	int idx[3] = {0};
	float err = FLT_MAX;
	float err_t = FLT_MAX;
	int exit_search = 0;
	
	int i,j,k = 0;
	for(i = 0; i < N; i++)  {
		for(j = 0; j < N; j++)  {
			for(k = 0; k < N; k++)  {
				err_t = fabs(orig_resistance-E12[i]-E12[j]-E12[k]);
				if(err_t < err) {
					idx[0] = i;
					idx[1] = j;
					idx[2] = k;
					err = err_t;
				}
				if(err == 0.0) {
					exit_search = 1;
					break;
				}
			}
			if(exit_search) {
				break;
			}
		}
		if(exit_search) {
			break;
		}
	}
		
	int c = 0;
	for(i = 0; i < 3; i++) {
		c += E12[idx[i]] != 0.0;
	}
	
	res_array[0] = E12[idx[0]];	
	res_array[1] = E12[idx[1]];	
	res_array[2] = E12[idx[2]];	

	return c;
}
