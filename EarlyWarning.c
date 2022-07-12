#include <stdio.h>
#include "BatteryChecker.h"

int CheckForWarning(ten_BatteryParameter parameter, float value, float min, float max){
	int warningSts = 0;
	if((value > min) && (value <= min + max*TOLERANCE)){
		UpdateForLowLimitWarning(parameter);
		warningSts = 1;
	}
	else if((value >= max - max*TOLERANCE) && (value <= max)){
		UpdateForHighLimitWarning(parameter);
		warningSts = 1;
	}
	return warningSts;
}
