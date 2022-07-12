#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

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
	else{
		batteryStatus_st.TempStatus = TEMP_NORMAL;
		batteryStatus_st.SOCStatus = SOC_NORMAL;
		batteryStatus_st.ChargeRateStatus = CHARGERATE_NORMAL;
	}
	return warningSts;
}
