#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "stdint.h"
#include<math.h>
#include <stdbool.h>
#define PI 3.142857
#define R  6371000 // earth radius

struct point{
	float latitude_deg;
	float latitude_min;
	float latitude_sec;
	float longitude_deg;
	float longitude_min;
	float longitude_sec;
	bool is_vaild;
};

struct point get_coordinates(char rawData[],int lenght);
double calculate_distance(struct point point1 ,struct point point2, double *distance);


struct point get_coordinates(char rawData[],int length){
    char  data[15][20];
    int index1=0,index2=0;
    int num=0;
    for(int i = 0;i<length;i++){
        if(rawData[i] == ','){
            index2 = i;
            int k = 0;
            for(int j = index1+1;j<index2;j++,k++){
                data[num][k] = rawData[j];
            }
            printf("\n");
            num++;
            index1 = index2;
                
            }
        }
    float latdeg  = (data[2][0] - '0')*10 +(data[2][1] - '0');
    float latmin  = (data[2][2] - '0')*10 +(data[2][3] - '0');
    float latsec  = ((float)(data[2][5] - '0')*10 +(data[2][6] - '0'))*(60)/(100);
        
    float longdeg = (data[4][0] - '0')*100 +(data[4][1] - '0')*10 + (data[4][2] - '0');
    float longmin = (data[4][3] - '0')*10 +(data[4][4] - '0');
    float longsec = ((float)(data[4][6] - '0')*10 +(data[4][7] - '0'))*(60)/(100);
    struct point p1 ;
    if(data[6][0]== '0'){
        p1.is_vaild =false;
    }
        
        
    p1.latitude_deg  = latdeg;
	p1.latitude_min  = latmin;
	p1.latitude_sec  = latsec;
	    
	p1.longitude_deg = longdeg;
	p1.longitude_min = longmin;
	p1.longitude_sec = longsec;
    return p1;
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
