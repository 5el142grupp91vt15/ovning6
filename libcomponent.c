#include "libcomponent.h"
#include <stdlib.h>

#include <stdio.h>
int e_resistance(float orig_resistance, float *res_array)
{
	int N = 13;
	float E12[13] = {82.0,68.0,56.0,47.0,39.0,33.0,27.0,22.0,18.0,15.0,12.0,10.0,0.0};
	float R[3] =  {0.0};
	float R_t[3] = {0.0};
	float err = 82;
	float err_t = 82;
	
	int i,j,k = 0;
	for(i = 0; i < N; i++)  {
		R_t[0] = E12[i];
		for(j = 0; j < N; j++)  {
			R_t[1] = E12[j];
			for(k = 0; k < N; k++)  {
				R_t[2] = E12[k];
				err_t = abs(orig_resistance-R_t[0]-R_t[1]-R_t[2]);
				if(err_t < err) {
					R[0] = R_t[0];
					R[1] = R_t[1];
					R[2] = R_t[2];
					err = err_t;
				}
			}
		}
	}
		
	int c = 0;
	for(i = 0; i < 3; i++) {
		c += R[i] != 0.0;
	}
	
	res_array[0] = R[0];	
	res_array[1] = R[1];	
	res_array[2] = R[2];	

	printf("%.f\n",R[0]);
	printf("%.f\n",R[1]);
	printf("%.f\n",R[2]);


	return c;
}
