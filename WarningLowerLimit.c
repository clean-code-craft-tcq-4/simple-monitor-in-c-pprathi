#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateTempForLowerLimit(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = LOW_TEMP_WARNING;
		printf("\nLow Temperature warning");
	}
}

void UpdateSOCForLowerLimit(ten_BatteryParameter parameter){
	if(parameter == SOC){
		batteryStatus_st.SOCStatus = LOW_SOC_WARNING;
		printf("\nLow SOC warning");
	}
}

void UpdateChargeRateForLowerLimit(ten_BatteryParameter parameter){
	if(parameter == CHARGERATE){
			batteryStatus_st.ChargeRateStatus = LOW_CHARGERATE_WARNING;
			printf("\nLow ChargeRate warning");
	}
}

void UpdateForLowLimitWarning(ten_BatteryParameter parameter){
	UpdateTempForLowerLimit(parameter);
	UpdateSOCForLowerLimit(parameter);
	UpdateChargeRateForLowerLimit(parameter);
}
