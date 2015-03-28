#/*! \file componenttest.c
    \brief Test program for the component library
*/

include <stdio.h>
#include "libcomponent.h"


/*! \fn int main(int argc, char** argv) 
    \brief A test program for the component library 
    \param argc Not used
    \param argv Not used
    \return Always 0

    The test program uses a test vector with different resistance values as input to the 
    e_resistance function to test if the library can approximate the value with components from 
    the E12 series. The test vector values are chosen to test corner cases:
	- single values from the E12 series
	- values that are combinations of values from the E12 series
	- values outside the E12 series
	- values too small to be perfectly approximated
	- values too big to be perfectly approximated
   
    The result is printed for every value in the test vector with info about which
    test value tested, the error (difference between the test value and the replacement value),
    the number of components used and the component values used.
*/
int main(int argc, char** argv) {
	float orig_resistances[14] = {
		0.1,4.7,33.0,470,1800,68000,390000,1500000,15000000,820000000,
		0.0,8200000000,0.05,5150
	};
	int nrOfResistors;
	int i;
	float res_array[3];
	float err;
	for(i = 0; i < 14; i++) {
		res_array[0] = 0.0;
		res_array[1] = 0.0;
		res_array[2] = 0.0;
		nrOfResistors = e_resistance(orig_resistances[i], res_array);
		err = orig_resistances[i]-res_array[0]-res_array[1]-res_array[2];
		printf("-- %d --\n",i);
		printf("orig_resistance: %2.2f\n",orig_resistances[i]);
		printf("err: %2.2f\n",err);
		printf("nrOfResistors: %d\n",nrOfResistors);
		printf("res_array: %2.2f, %2.2f, %2.2f\n",res_array[0],res_array[1],res_array[2]);
		printf("-----------------------------\n");
	}
	return 0;
}
