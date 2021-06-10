#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include "stdint.h"
#include<math.h>
#include <stdio.h>
#include <stdbool.h>
#define PI 3.142857
#define R  6371000 // earth radius

struct point {
	float latitude_deg;
	float latitude_min;
	float latitude_sec;
	float longitude_deg;
	float longitude_min;
	float longitude_sec;
	bool is_vaild;
};


struct point get_coordinates(char rawData[], int length) {
	char  data[3][15];
	int index1 = 0, index2 = 0;
	int num = 0;
	int idx=0;
	for (int i = 0; i < length; i++) {
		if (rawData[i] == ',') {
			index2 = i;
			int k = 0;
			if (num == 2 || num == 4 || num == 6 ) {
				for (int j = index1 + 1; j < index2; j++, k++) {
					data[idx][k] = rawData[j];
				}
				idx++;
			}

			num++;
			index1 = index2;

		}
	}

	struct point p1;
	if (data[2][0] == '0') {
		p1.is_vaild = false;
	}
	else {
		float latdeg = (data[0][0] - '0') * 10 + (data[0][1] - '0');
		float latmin = (data[0][2] - '0') * 10 + (data[0][3] - '0');
		float latsec = ((float)(data[0][5] - '0') * 1000 + (data[0][6] - '0') * 100 + (data[0][7] - '0') * 10 + (data[0][8] - '0')) * (60) / (10000);

		float longdeg = (data[1][0] - '0') * 100 + (data[1][1] - '0') * 10 + (data[1][2] - '0');
		float longmin = (data[1][3] - '0') * 10 + (data[1][4] - '0');
		float longsec = ((float)(data[1][6] - '0') * 1000 + (data[1][7] - '0') * 100 + (data[1][8] - '0') * 10 + (data[1][9] - '0')) * (60) / (10000);

		p1.latitude_deg = latdeg;
		p1.latitude_min = latmin;
		p1.latitude_sec = latsec;

		p1.longitude_deg = longdeg;
		p1.longitude_min = longmin;
		p1.longitude_sec = longsec;

	}



	return p1;
}



double calculate_distance(struct point point1, struct point point2) {
	double phi_1 = (point1.latitude_deg + (double)(point1.latitude_min + (double)point1.latitude_sec / 60) / 60) * (PI / 180);
	double phi_2 = (point2.latitude_deg + (double)(point2.latitude_min + (double)point2.latitude_sec / 60) / 60) * (PI / 180);

	double lamda_1 = (point1.longitude_deg + (double)(point1.longitude_min + (double)point1.longitude_sec / 60) / 60) * (PI / 180);
	double lamda_2 = (point2.longitude_deg + (double)(point2.longitude_min + (double)point2.longitude_sec / 60) / 60) * (PI / 180);
	double delta_phi = (phi_1 - phi_2);
	double delta_lamda = lamda_1 - lamda_2;

	double a = sin(delta_phi / 2) * sin(delta_phi / 2) + cos(phi_1) * cos(phi_2) * sin(delta_lamda / 2) * sin(delta_lamda / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	return c * R;
}

#endif // DATA_H_INCLUDED
