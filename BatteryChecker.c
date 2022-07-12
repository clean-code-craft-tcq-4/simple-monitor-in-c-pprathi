#include <stdio.h>
#include <assert.h>
#include "BatteryChecker.h"

tst_BatteryStatus batteryStatus_st;

int BatteryParamInRange(ten_BatteryParameter parameter, float value, float min, float max){
	return ((value >= min) && (value <= max));
}

int CheckBatteryPerformance(ten_BatteryParameter parameter, float value, float min, float max){
	int paramSts = 0, warningSts = 0;
	paramSts = BatteryParamInRange(parameter, value, min, max);
	if(paramSts == 0){
		printf("\nParameter is out of range");
		UpdateForLowOrHighBreach(parameter, value, min, max);
	}
	else{
		warningSts = CheckForWarning(parameter, value, min, max);
	}
	return paramSts && !warningSts;
}

int batteryIsOk(float temperature, ten_TempUnit tempUnit, float soc, float chargeRate) {
	float temperatureInCelcius = 0;
	temperatureInCelcius = TempConversion(temperature, tempUnit);
	return (CheckBatteryPerformance(TEMPERATURE, temperatureInCelcius, TEMP_MIN, TEMP_MAX) && CheckBatteryPerformance(SOC, soc, SOC_MIN, SOC_MAX) &&
			CheckBatteryPerformance(CHARGERATE, chargeRate, CHARGERATE_MIN, CHARGERATE_MAX));
}

int main(void) {
  assert(batteryIsOk(25, CELCIUS, 70, 0.7)); 		//All params in Range
  assert(!batteryIsOk(-1, CELCIUS, 24, 0.08));		//Temperature low breach / out of range
  assert(!batteryIsOk(2, CELCIUS, 26, 0.7)); 		//Temperature, low temp warning
  assert(!batteryIsOk(46, CELCIUS, 31, 0.6));		//Temperture high breach / out of range
  assert(!batteryIsOk(44, CELCIUS, 49, 0.1));		//Temperature, high temp warning
  assert(batteryIsOk(77, FAHRENHEIT, 70, 0.7)); 	//All params in Range
  assert(!batteryIsOk(30.2, FAHRENHEIT, 24, 0.08));	//Temperature low breach / out of range
  assert(!batteryIsOk(35.6, FAHRENHEIT, 26, 0.7)); 	//Temperature, low temp warning
  assert(!batteryIsOk(114.8, FAHRENHEIT, 31, 0.6));	//Temperture high breach / out of range
  assert(!batteryIsOk(111.2, FAHRENHEIT, 49, 0.1));	//Temperature, high temp warning
  assert(!batteryIsOk(30, CELCIUS, 19, 0.05));		//SOC low breach / out of range
  assert(!batteryIsOk(41.25, CELCIUS, 23, 0.70)); 	//SOC, low SOC warning
  assert(!batteryIsOk(2.5, CELCIUS, 81, 0.65));		//SOC high breach / out of range
  assert(!batteryIsOk(40.75, CELCIUS, 76, 0.5));	//SOC, high SOC warning
  assert(!batteryIsOk(42.25, CELCIUS, 25, -0.01));	//ChargeRate low breach / out of range
  assert(!batteryIsOk(12, CELCIUS, 26, 0.03)); 		//ChargeRate, low ChargeRate warning
  assert(!batteryIsOk(36, CELCIUS, 31, 0.9));		//ChargeRate high breach / out of range
  assert(!batteryIsOk(27, CELCIUS, 27, 0.77));		//ChargeRate, high chargerate warning
}
