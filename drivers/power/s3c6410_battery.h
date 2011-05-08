/*
 * linux/drivers/power/s3c6410_battery.h
 *
 * Battery measurement code for S3C6410 platform.
 *
 * Copyright (C) 2009 Samsung Electronics.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#define DRIVER_NAME	"spica-battery"

/*
 * Spica Rev00 board Battery Table
 */

#define BATT_CAL		2447
#define BATT_MAXIMUM		605
#define BATT_FULL		480
#define BATT_PRE_FULL		420
#define BATT_SAFE_RECHARGE	480
#define BATT_ALMOST_FULL	305
#define BATT_HIGH		152
#define BATT_MED		92
#define BATT_LOW		(1)
#define BATT_CRITICAL		(-74)
#define BATT_MINIMUM		(-114)
#define BATT_OFF		(-356)

/*
 * Spica Rev00 board Temperature Table
 */
const int temper_table[][2] =  {
	/* ADC, Temperature (C) */
	{ 1632,		-50	},
	{ 1616,		-40	},
	{ 1599,		-30	},
	{ 1583,		-20	},
	{ 1566,		-10	},
	{ 1550,		0	},
	{ 1530,		10	},
	{ 1510,		20	},
	{ 1490,		30	},
	{ 1470,		40	},
	{ 1450,		50	},
	{ 1428,		60	},
	{ 1406,		70	},
	{ 1384,		80	},
	{ 1362,		90	},
	{ 1340,		100	},
	{ 1317,		110	},
	{ 1294,		120	},
	{ 1270,		130	},
	{ 1247,		140	},
	{ 1224,		150	},
	{ 1202,		160	},
	{ 1179,		170	},
	{ 1157,		180	},
	{ 1134,		190	},
	{ 1112,		200	},
	{ 1088,		210	},
	{ 1065,		220	},
	{ 1041,		230	},
	{ 1018,		240	},
	{ 994,		250	},
	{ 972,		260	},
	{ 951,		270	},
	{ 929,		280	},
	{ 908,		290	},
	{ 886,		300	},
	{ 866,		310	},
	{ 845,		320	},
	{ 825,		330	},
	{ 804,		340	},
	{ 784,		350	},
	{ 764,		360	},
	{ 744,		370	},
	{ 724,		380	},
	{ 704,		390	},
	{ 684,		400	},
	{ 666,		410	},
	{ 648,		420	},
	{ 629,		430	},
	{ 611,		440	},
	{ 593,		450	},
	{ 577,		460	},
	{ 560,		470	},
	{ 544,		480	},
	{ 527,		490	},
	{ 511,		500	},
	{ 497,		510	},
	{ 482,		520	},
	{ 468,		530	},
	{ 453,		540	},
	{ 439,		550	},
	{ 426,		560	},
	{ 414,		570	},
	{ 401,		580	},
	{ 388,		590	},
	{ 375,		600	},
	{ 364,		610	},
	{ 354,		620	},
	{ 343,		630	},
	{ 334,		640	},
	{ 324,		650	},
};

#define TEMP_HIGH_BLOCK		temper_table[68][0]
#define TEMP_HIGH_RECOVER	temper_table[63][0]
#define TEMP_LOW_BLOCK		temper_table[0][0]
#define TEMP_LOW_RECOVER	temper_table[5][0]

/*
 * Spica Rev00 board ADC channel
 */
typedef enum s3c_adc_channel {
	S3C_ADC_VOLTAGE = 0,
	S3C_ADC_TEMPERATURE,
	S3C_ADC_V_F,
	S3C_ADC_EAR,
	S3C_ADC_CHG_CURRENT,
	ENDOFADC
} adc_channel_type;

#define IRQ_TA_CONNECTED_N	IRQ_EINT(19)
#define IRQ_TA_CHG_N		IRQ_EINT(25)

/*
 * Spica GPIO for battery driver
 */
const unsigned int gpio_ta_connected	= GPIO_TA_CONNECTED_N;
const unsigned int gpio_ta_connected_af	= GPIO_TA_CONNECTED_N_AF;
const unsigned int gpio_chg_ing		= GPIO_TA_CHG_N;
const unsigned int gpio_chg_ing_af	= GPIO_TA_CHG_N_AF;
const unsigned int gpio_chg_en		= GPIO_TA_EN;
const unsigned int gpio_chg_en_af	= GPIO_TA_EN_AF;

/******************************************************************************
 * Battery driver features
 * ***************************************************************************/
/* #define __TEMP_ADC_VALUE__ */
/* #define __USE_EGPIO__ */
/* #define __CHECK_BATTERY_V_F__ */
#define __BATTERY_V_F__
#define __BATTERY_COMPENSATION__
/* #define __CHECK_BOARD_REV__ */
/* #define __BOARD_REV_ADC__ */
#define __TEST_DEVICE_DRIVER__
/* #define __ALWAYS_AWAKE_DEVICE__  */
#define __TEST_MODE_INTERFACE__
//#define __ADJUST_RECHARGE_ADC__
/*****************************************************************************/

#define TOTAL_CHARGING_TIME	(6*60*60*1000)	/* 6 hours */
#define TOTAL_RECHARGING_TIME	(3*30*60*1000)	/* 1.5 hours */

#ifdef __BATTERY_COMPENSATION__
#define COMPENSATE_VIBRATOR		20
#define COMPENSATE_CAMERA		50
#define COMPENSATE_MP3			25
#define COMPENSATE_VIDEO		30
#define COMPENSATE_VOICE_CALL_2G	13
#define COMPENSATE_VOICE_CALL_3G	15
#define COMPENSATE_DATA_CALL		35
#define COMPENSATE_LCD			40
#define COMPENSATE_TA			0
#define COMPENSATE_CAM_FALSH		0
#define COMPENSATE_BOOTING		50
#endif /* __BATTERY_COMPENSATION__ */

#define convert_adc2voltage(x)		((x - 2170) * 10 / 7 / 100 * 100 + 3200)

