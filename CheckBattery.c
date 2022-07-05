#include <stdio.h>
#include <assert.h>
#include "CheckBattery.h"


int batteryIsOk(float temperature, float soc, float chargeRate) {
	return (!BATTERY_CHECK(temperature, TEMP_MIN, TEMP_MAX) && !BATTERY_CHECK(soc, SOC_MIN, SOC_MAX) && !CHARGERATE_CHECK(chargeRate, CHARGERATE_LIMIT));
}

int main(void) {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(46, 21, 0.6));
  assert(!batteryIsOk(44, 19, 0.1));
  assert(!batteryIsOk(1, 79, 0.9));
}
