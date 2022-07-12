#include <stdio.h>
#include "BatteryChecker.h"

float TempConversion(float temperature, ten_TempUnit tempUnit){
	float temperatureInCelcius = temperature;
	if(tempUnit == FAHRENHEIT){
		temperatureInCelcius = ((temperature - 32)*5)/9;
	}
	return temperatureInCelcius;
}
