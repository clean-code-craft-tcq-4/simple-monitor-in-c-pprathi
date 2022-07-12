#include <stdio.h>
#include "BatteryChecker.h"

extern tst_BatteryStatus batteryStatus_st;

void UpdateForLowBreach(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = LOW_TEMP_BREACH;
		printf("\nLow Breach Temperature");
	}
	else if(parameter == SOC){
		batteryStatus_st.SOCStatus = LOW_SOC_BREACH;
		printf("\nLow Breach SOC");
	}
	else if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = LOW_CHARGERATE_BREACH;
		printf("\nLow Breach ChargeRate");
	}
}

void UpdateForHighBreach(ten_BatteryParameter parameter){
	if(parameter == TEMPERATURE){
		batteryStatus_st.TempStatus = HIGH_TEMP_BREACH;
		printf("\nHigh Breach Temperature");
	}
	else if(parameter == SOC){
		batteryStatus_st.SOCStatus = HIGH_SOC_BREACH;
		printf("\nHigh Breach SOC");
	}
	else if(parameter == CHARGERATE){
		batteryStatus_st.ChargeRateStatus = HIGH_CHARGERATE_BREACH;
		printf("\nHigh Breach ChargeRate");
	}
}

void UpdateForLowOrHighBreach(ten_BatteryParameter parameter, float value, float min, float max){
	if(value < min){
		UpdateForLowBreach(parameter);
	}
	else{
		UpdateForHighBreach(parameter);
	}
}
