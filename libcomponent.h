/*! \file libcomponent.h
    \brief Header file for the library 
*/
/*! \mainpage Component libray
    A library that is able to calculate the replacement resistance with components from the E12 series.
    This documentation includes the library and a test program.
*/

/*! \var static const float E12[130]
    \brief All resistance values (ohm) in the E12 series
*/
static const float E12[130] = {
	820000000,680000000,560000000,470000000,390000000,330000000,270000000,220000000,180000000,150000000,120000000,100000000,
	82000000,68000000,56000000,47000000,39000000,33000000,27000000,22000000,18000000,15000000,12000000,10000000,
	8200000,6800000,5600000,4700000,3900000,3300000,2700000,2200000,1800000,1500000,1200000,1000000,
	820000,680000,560000,470000,390000,330000,270000,220000,180000,150000,120000,100000,
	82000,68000,56000,47000,39000,33000,27000,22000,18000,15000,12000,10000,
	8200,6800,5600,4700,3900,3300,2700,2200,1800,1500,1200,1000,
	820,680,560,470,390,330,270,220,180,150,120,100,
	82.0,68.0,56.0,47.0,39.0,33.0,27.0,22.0,18.0,15.0,12.0,10.0,
	.2,6.8,5.6,4.7,3.9,3.3,2.7,2.2,1.8,1.5,1.2,1.0,
	0.82,0.68,0.56,0.47,0.39,0.33,0.27,0.22,0.18,0.15,0.12,0.1,
	.0
};

/*! \fn int e_resistance(float orig_resistance, float *res_array)  
    \brief Calculates what replacement resistance you get with three values from the E12 series
    \param orig_resistance The original resistance to approximate
    \param res_array An array with tree or less values from the E12 series used
    \return The number of elements from the E12 series used
*/
int e_resistance(float orig_resistance, float *res_array);
