#include <stdio.h>
#include <assert.h>
#include "CheckBattery.h"


int validateTemperature(float temperature){
	int retstatus = 1;
	if(!BATTERY_PARAMATER_WITHIN_RANGE(temperature, TEMP_MIN, TEMP_MAX)){
		printf("\nTemperature is out of Range");
		retstatus = 0;
	}
	return retstatus;
}

int validateSOC(float soc){
	int retstatus = 1;
	if(!BATTERY_PARAMATER_WITHIN_RANGE(soc, SOC_MIN, SOC_MAX)){
		printf("\nSOC is out of Range");
		retstatus = 0;
	}
	return retstatus;
}

int validateChargeRate(float chargeRate){
	int retstatus = 1;
	if(CHARGERATE_OUTOF_RANGE(chargeRate, CHARGERATE_LIMIT)){
		printf("\nChargeRate is out of Range");
		retstatus = 0;
	}
	return retstatus;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

	int validtemp = 0, validsoc = 0, validchargerate = 0, retstatus = 0;
	validtemp = validateTemperature(temperature);
	validsoc = validateSOC(soc);
	validchargerate = validateChargeRate(chargeRate);
	if(validtemp && validsoc && validchargerate)
	{
		retstatus = 1;
	}
	return retstatus;
}

int main(void) {

  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(45, 21, 0.6));
  assert(!batteryIsOk(44, 20, 0.1));
  assert(!batteryIsOk(1, 79, 0.9));
}
