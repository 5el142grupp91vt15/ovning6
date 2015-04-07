#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

int main(int argc, char** argv)
{
    int c, i;
	  float *p_array, *comp;
  	float volt, res;
  	char sp;
  	p_array = (float *)malloc(sizeof(float) *3);

  	printf("Ange spänningskälla i V:");
  	scanf("%f",&volt);
  	printf("Ange koppling[S|P]:");
  	scanf(" %c", &sp);
  	printf("Antal komponenter:");
  	scanf("%d", &c);

  	comp = (float *)malloc(sizeof(float) *c);
  
  	for(i = 0; i < c; i++){
    	printf("Komponent %d i ohm:", i+1);
    	scanf("%f", &comp[i]);
  	}
  
  	res =  calc_resistance(c,sp,comp);
  	printf("Ersättningsresistans: %.0f ohm\n", res) ; 
  	printf("Effekt: %.3f W\n",  calc_power_r(volt, res));
   
  	int value = e_resistance(res, p_array);
  	printf("Ersättningsresistanser i E12-serien kopplade i serie:  %.1f %.1f %.1f \n", p_array[0], p_array[1], p_array[2]);
  	free(p_array);
  	free(comp);

	return 0;
}
