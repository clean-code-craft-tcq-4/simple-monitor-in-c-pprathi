#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80
#define CHARGERATE_LIMIT	0.8

#define BATTERY_PARAM_NOTINRANGE(param, min, max)		((param < min) || (param > max))
#define CHARGERATE_NOTINRANGE(param, limit)				  (param > limit)
