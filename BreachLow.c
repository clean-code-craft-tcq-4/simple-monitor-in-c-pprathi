#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateTempForLowBreach(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = LOW_TEMP_BREACH;
		printf("\nLow Breach Temperature");
	}
}

void UpdateSOCForLowBreach(ten_BatteryParameter parameter){
	if(parameter == SOC){
		batteryStatus_st.SOCStatus = LOW_SOC_BREACH;
		printf("\nLow Breach SOC");
	}
}

void UpdateChargeRateForLowBreach(ten_BatteryParameter parameter){
	if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = LOW_CHARGERATE_BREACH;
		printf("\nLow Breach ChargeRate");
	}
}

void UpdateForLowBreach(ten_BatteryParameter parameter){
	UpdateTempForLowBreach(parameter);
	UpdateSOCForLowBreach(parameter);
	UpdateChargeRateForLowBreach(parameter);
}
