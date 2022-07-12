#include <stdio.h>
#include "BatteryChecker.h"

int CheckForWarning(ten_BatteryParameter parameter, float value, float min, float max){
	int warningSts = 0, lowLimitCheck = 0, highLimitCheck = 0;
	lowLimitCheck = (value > min) && (value <= min + max*TOLERANCE);
	highLimitCheck = (value >= max - max*TOLERANCE) && (value <= max);
	if(lowLimitCheck){
		UpdateForLowLimitWarning(parameter);
		warningSts = 1;
	}
	else if(highLimitCheck){
		UpdateForHighLimitWarning(parameter);
		warningSts = 1;
	}
	return warningSts;
}
