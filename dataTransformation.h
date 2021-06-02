#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "stdint.h"
#include<math.h>
#include <stdbool.h>
#define PI 3.142857
#define R  6371000 // earth radius

struct point{
	int16_t latitude_deg;
	int16_t latitude_min;
	int16_t latitude_sec;
	int16_t longitude_deg;
	int16_t longitude_min;
	int16_t longitude_sec;
	bool is_vaild;
};

struct point get_coordinates(char rawData[]);
double calculate_distance(struct point point1 ,struct point point2, double *distance);




struct point get_coordinates(char rawData[]){

}

double calculate_distance(struct point point1 ,struct point point2, double *distance){
	double phi_1 = (point1.latitude_deg +  (double)(point1.latitude_min + (double)point1.latitude_sec/60) /60 ) * (PI / 180);
	double phi_2 = (point2.latitude_deg +  (double)(point2.latitude_min + (double)point2.latitude_sec/60) /60 ) * (PI / 180);

	double lamda_1 = (point1.longitude_deg +  (double)(point1.longitude_min + (double)point1.longitude_sec/60) /60 ) * (PI / 180);
	double lamda_2 = (point2.longitude_deg +  (double)(point2.longitude_min + (double)point2.longitude_sec/60) /60 ) * (PI / 180);
	double delta_phi = (phi_1 - phi_2) ;
	double delta_lamda = lamda_1 - lamda_2;

	double a = sin(delta_phi/2) * sin(delta_phi/2) +cos(phi_1) * cos(phi_2) *sin(delta_lamda/2) * sin(delta_lamda/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	*distance = *distance + c * R;
	return *distance;
}

#endif // DATA_H_INCLUDED
