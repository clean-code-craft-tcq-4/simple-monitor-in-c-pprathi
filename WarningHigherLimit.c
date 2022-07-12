#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateTempForHighLimit(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = HIGH_TEMP_WARNING;
		printf("\nHigh Temperature warning");
	}
}

void UpdateSOCForHighLimit(ten_BatteryParameter parameter){
	if(parameter == SOC){
		batteryStatus_st.SOCStatus = HIGH_SOC_WARNING;
		printf("\nHigh SOC warning");
	}
}

void UpdateChargeRateForHighLimit(ten_BatteryParameter parameter){
	if(parameter == CHARGERATE){
			batteryStatus_st.ChargeRateStatus = HIGH_CHARGERATE_WARNING;
			printf("\nHigh ChargeRate warning");
	}
}

void UpdateForHighLimitWarning(ten_BatteryParameter parameter){
	UpdateTempForHighLimit(parameter);
	UpdateSOCForHighLimit(parameter);
	UpdateChargeRateForHighLimit(parameter);
}

