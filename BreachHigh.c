#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateTempForHighBreach(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = HIGH_TEMP_BREACH;
		printf("\nHigh Breach Temperature");
	}
}

void UpdateSOCForHighBreach(ten_BatteryParameter parameter){
	if(parameter == SOC){
		batteryStatus_st.SOCStatus = HIGH_SOC_BREACH;
		printf("\nHigh Breach SOC");
	}
}

void UpdateChargeRateForHighBreach(ten_BatteryParameter parameter){
	if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = HIGH_CHARGERATE_BREACH;
		printf("\nHigh Breach ChargeRate");
	}
}

void UpdateForHighBreach(ten_BatteryParameter parameter){
	UpdateTempForHighBreach(parameter);
	UpdateSOCForHighBreach(parameter);
	UpdateChargeRateForHighBreach(parameter);
}
