#include <stdio.h>
#include "BatteryChecker.h"

void UpdateForLowOrHighBreach(ten_BatteryParameter parameter, float value, float min, float max){
	if(value < min){
		UpdateForLowBreach(parameter);
	}
	else{
		UpdateForHighBreach(parameter);
	}
}
