#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"
#include "libpower.h"
#include "libcomponent.h"

int main(int argc, char** argv)
{
	float *p_array;
  	float voltage, resistance;
  	char sp;
  	int count, i;
  	float *components;
  	p_array = (float *)malloc(sizeof(float) *3);

  	printf("Ange spänningskälla i V:");
  	scanf("%f",&voltage);
  	printf("Ange koppling[S|P]:");
  	scanf(" %c", &sp);
  	printf("Antal komponenter:");
  	scanf("%d", &count);

  	components = (float *)malloc(sizeof(float) *count);
  
  	for(i = 0; i < count; i++){
    	printf("Komponent %d i ohm:", i+1);
    	scanf("%f", &components[i]);
  	}
  
  	resistance =  calc_resistance(count,sp,components);
  	printf("Ersättningsresistans: %.1f ohm\n", resistance) ; 
  	printf("Effekt: %.2f W\n",  calc_power_r(voltage, resistance));
   
  	int value = e_resistance(resistance, p_array);
  	printf("Ersättningsresistanser i E12-serien kopplade i serie:  %.1f %.1f %.1f \n", p_array[0], p_array[1], p_array[2]);
  	free(p_array);
  	free(components);

	return 0;
}
