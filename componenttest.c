#include <stdio.h>
#include "libcomponent.h"

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
