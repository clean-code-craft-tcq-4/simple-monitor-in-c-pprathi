#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80
#define CHARGERATE_LIMIT	0.8

#define BATTERY_PARAMATER_WITHIN_RANGE(param, min, max)		((param > min) && (param < max))
#define CHARGERATE_OUTOF_RANGE(param, limit)				(param > limit)

int 	validateTemperature	(float temperature);
int 	validateSOC			(float soc);
int 	validateChargeRate	(float chargeRate);
int 	batteryIsOk			(float temperature, float soc, float chargeRate);
