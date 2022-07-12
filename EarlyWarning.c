#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

int CheckForLowLimitWarning(ten_BatteryParameter parameter, float value, float min, float max){
	int retSts = 0;
	if((value > min) && (value <= min + max*TOLERANCE)){
		UpdateForLowLimitWarning(parameter);
		retSts = 1;
	}
	return retSts;
}
int CheckForHighLimitWarning(ten_BatteryParameter parameter, float value, float min, float max){
	int retSts = 0;
	if((value >= max - max*TOLERANCE) && (value <= max)){
		UpdateForHighLimitWarning(parameter);
		retSts = 1;
	}
	return retSts;
}

int CheckForWarning(ten_BatteryParameter parameter, float value, float min, float max){
	int LowLimitSts = 0, HighLimitSts = 0;
	batteryStatus_st.TempStatus = TEMP_NORMAL;
	batteryStatus_st.SOCStatus = SOC_NORMAL;
	batteryStatus_st.ChargeRateStatus = CHARGERATE_NORMAL;

	LowLimitSts = CheckForLowLimitWarning(parameter, value, min, max);
	HighLimitSts = CheckForHighLimitWarning(parameter, value, min, max);
	return (LowLimitSts || HighLimitSts);
}
