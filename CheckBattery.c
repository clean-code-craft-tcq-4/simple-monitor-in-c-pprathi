#include <stdio.h>
#include <assert.h>
#include "CheckBattery.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
	return (!BATTERY_PARAM_NOTINRANGE(temperature, TEMP_MIN, TEMP_MAX) && !BATTERY_PARAM_NOTINRANGE(soc, SOC_MIN, SOC_MAX) && 
		!CHARGERATE_NOTINRANGE(chargeRate, CHARGERATE_LIMIT));
}

int main(void) {
  assert(batteryIsOk(25, 70, 0.7)); 	//All params in Range
  assert(!batteryIsOk(50, 85, 0)); 	//Temperature, SOC out of range
  assert(!batteryIsOk(46, 21, 0.6));	//Temperture out of range
  assert(!batteryIsOk(44, 19, 0.1));	//SOC out of range
  assert(!batteryIsOk(1, 79, 0.9));	//ChargeRate out of range
  assert(!batteryIsOk(-1, 80, 0.8));	//Temperature out of range
}
