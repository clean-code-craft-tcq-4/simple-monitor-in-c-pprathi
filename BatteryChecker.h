#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80
#define CHARGERATE_MIN		0
#define CHARGERATE_MAX  	0.8
#define TOLERANCE			5/100

typedef enum{
	TEMPERATURE,
	SOC,
	CHARGERATE
}ten_BatteryParameter;

typedef enum{
	CELCIUS,
	FAHRENHEIT
}ten_TempUnit;

typedef enum{
	LOW_TEMP_BREACH,
	LOW_TEMP_WARNING,
	TEMP_NORMAL,
	HIGH_TEMP_WARNING,
	HIGH_TEMP_BREACH
}ten_BatteryTempStatus;

typedef enum{
	LOW_SOC_BREACH,
	LOW_SOC_WARNING,
	SOC_NORMAL,
	HIGH_SOC_WARNING,
	HIGH_SOC_BREACH,
}ten_BatterySOCStatus;

typedef enum{
	LOW_CHARGERATE_BREACH,
	LOW_CHARGERATE_WARNING,
	CHARGERATE_NORMAL,
	HIGH_CHARGERATE_WARNING,
	HIGH_CHARGERATE_BREACH
}ten_BatteryChargeRateStatus;

typedef struct{
   ten_BatteryTempStatus TempStatus;
   ten_BatterySOCStatus SOCStatus;
   ten_BatteryChargeRateStatus ChargeRateStatus;
}tst_BatteryStatus;

void UpdateForLowBreach(ten_BatteryParameter parameter);
void UpdateForHighBreach(ten_BatteryParameter parameter);
void UpdateForLowOrHighBreach(ten_BatteryParameter parameter, float value, float min, float max);
void UpdateForLowLimitWarning(ten_BatteryParameter parameter);
void UpdateForHighLimitWarning(ten_BatteryParameter parameter);
int CheckForWarning(ten_BatteryParameter parameter, float value, float min, float max);
float TempConversion(float temperature, ten_TempUnit tempUnit);
