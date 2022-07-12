#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateForLowLimitWarning(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = LOW_TEMP_WARNING;
		printf("\nLow Temperature warning");
	}
	else if(parameter == SOC){
		batteryStatus_st.SOCStatus = LOW_SOC_WARNING;
		printf("\nLow SOC warning");
	}
	else if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = LOW_CHARGERATE_WARNING;
		printf("\nLow ChargeRate warning");
	}
}

void UpdateForHighLimitWarning(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = HIGH_TEMP_WARNING;
		printf("\nHigh Temperature warning");
	}
	else if(parameter == SOC){
		batteryStatus_st.SOCStatus = HIGH_SOC_WARNING;
		printf("\nHigh SOC warning");
	}
	else if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = HIGH_CHARGERATE_WARNING;
		printf("\nHigh ChargeRate warning");
	}
}

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
