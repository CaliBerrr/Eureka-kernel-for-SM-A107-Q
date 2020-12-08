/*
 * batt_cisd.h
 * Battery Driver
 *
 * Copyright (C) 2015 Samsung Electronics, Inc.
 *
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __SEC_CISD_H
#define __SEC_CISD_H __FILE__

#define CISD_STATE_NONE			0x00
#define CISD_STATE_OVER_VOLTAGE	0x01

enum cisd_data {
	CISD_DATA_RESET_ALG = 0,
	CISD_DATA_ALG_INDEX,
	CISD_DATA_FULL_COUNT,
	CISD_DATA_CAP_MAX,
	CISD_DATA_CAP_MIN,
	CISD_DATA_RECHARGING_COUNT,
	CISD_DATA_VALERT_COUNT,
	CISD_DATA_CYCLE,
	CISD_DATA_WIRE_COUNT,
	CISD_DATA_WIRELESS_COUNT,
	CISD_DATA_HIGH_TEMP_SWELLING,

	CISD_DATA_LOW_TEMP_SWELLING,
	CISD_DATA_WC_HIGH_TEMP_SWELLING,
	CISD_DATA_SWELLING_FULL_CNT,
	CISD_DATA_SWELLING_RECOVERY_CNT,
	CISD_DATA_AICL_COUNT,
	CISD_DATA_BATT_TEMP_MAX,
	CISD_DATA_BATT_TEMP_MIN,
	CISD_DATA_CHG_TEMP_MAX,
	CISD_DATA_CHG_TEMP_MIN,
	CISD_DATA_WPC_TEMP_MAX,

	CISD_DATA_WPC_TEMP_MIN,
	CISD_DATA_USB_TEMP_MAX,
	CISD_DATA_USB_TEMP_MIN,
	CISD_DATA_CHG_BATT_TEMP_MAX,
	CISD_DATA_CHG_BATT_TEMP_MIN,
	CISD_DATA_CHG_CHG_TEMP_MAX,
	CISD_DATA_CHG_CHG_TEMP_MIN,
	CISD_DATA_CHG_WPC_TEMP_MAX,
	CISD_DATA_CHG_WPC_TEMP_MIN,
	CISD_DATA_CHG_USB_TEMP_MAX,

	CISD_DATA_CHG_USB_TEMP_MIN,
	CISD_DATA_USB_OVERHEAT_CHARGING, /* 32 */
	CISD_DATA_UNSAFETY_VOLTAGE,
	CISD_DATA_UNSAFETY_TEMPERATURE,
	CISD_DATA_SAFETY_TIMER,
	CISD_DATA_VSYS_OVP,
	CISD_DATA_VBAT_OVP,
	CISD_DATA_USB_OVERHEAT_RAPID_CHANGE,
	CISD_DATA_BUCK_OFF,
	CISD_DATA_USB_OVERHEAT_ALONE,

	CISD_DATA_DROP_VALUE,

	CISD_DATA_MAX,
};

enum cisd_data_per_day {
	CISD_DATA_FULL_COUNT_PER_DAY = CISD_DATA_MAX,

	CISD_DATA_CAP_MAX_PER_DAY,
	CISD_DATA_CAP_MIN_PER_DAY,
	CISD_DATA_RECHARGING_COUNT_PER_DAY,
	CISD_DATA_VALERT_COUNT_PER_DAY,
	CISD_DATA_WIRE_COUNT_PER_DAY,
	CISD_DATA_WIRELESS_COUNT_PER_DAY,
	CISD_DATA_HIGH_TEMP_SWELLING_PER_DAY,
	CISD_DATA_LOW_TEMP_SWELLING_PER_DAY,
	CISD_DATA_WC_HIGH_TEMP_SWELLING_PER_DAY,
	CISD_DATA_SWELLING_FULL_CNT_PER_DAY,

	CISD_DATA_SWELLING_RECOVERY_CNT_PER_DAY,
	CISD_DATA_AICL_COUNT_PER_DAY,
	CISD_DATA_BATT_TEMP_MAX_PER_DAY,
	CISD_DATA_BATT_TEMP_MIN_PER_DAY,
	CISD_DATA_CHG_TEMP_MAX_PER_DAY,
	CISD_DATA_CHG_TEMP_MIN_PER_DAY,
	CISD_DATA_WPC_TEMP_MAX_PER_DAY,
	CISD_DATA_WPC_TEMP_MIN_PER_DAY,
	CISD_DATA_USB_TEMP_MAX_PER_DAY,
	CISD_DATA_USB_TEMP_MIN_PER_DAY,

	CISD_DATA_CHG_BATT_TEMP_MAX_PER_DAY,
	CISD_DATA_CHG_BATT_TEMP_MIN_PER_DAY,
	CISD_DATA_CHG_CHG_TEMP_MAX_PER_DAY,
	CISD_DATA_CHG_CHG_TEMP_MIN_PER_DAY,
	CISD_DATA_CHG_WPC_TEMP_MAX_PER_DAY,
	CISD_DATA_CHG_WPC_TEMP_MIN_PER_DAY,
	CISD_DATA_CHG_USB_TEMP_MAX_PER_DAY,
	CISD_DATA_CHG_USB_TEMP_MIN_PER_DAY,
	CISD_DATA_USB_OVERHEAT_CHARGING_PER_DAY,
	CISD_DATA_UNSAFE_VOLTAGE_PER_DAY,

	CISD_DATA_UNSAFE_TEMPERATURE_PER_DAY,
	CISD_DATA_SAFETY_TIMER_PER_DAY, /* 32 */
	CISD_DATA_VSYS_OVP_PER_DAY,
	CISD_DATA_VBAT_OVP_PER_DAY,
	CISD_DATA_USB_OVERHEAT_RAPID_CHANGE_PER_DAY,
	CISD_DATA_BUCK_OFF_PER_DAY,
	CISD_DATA_USB_OVERHEAT_ALONE_PER_DAY,
	CISD_DATA_DROP_VALUE_PER_DAY,

	CISD_DATA_MAX_PER_DAY,
};

enum {
	CISD_CABLE_INDEX = 0,
	CISD_CABLE_TA,
	CISD_CABLE_AFC,
	CISD_CABLE_AFC_FAIL,
	CISD_CABLE_QC,
	CISD_CABLE_QC_FAIL,
	CISD_CABLE_PD,
	CISD_CABLE_PD_HIGH,
	CISD_CABLE_HV_WC_20,

	CISD_CABLE_TYPE_MAX,
};

extern const char *cisd_data_str[];
extern const char *cisd_data_str_d[];
extern const char *cisd_cable_data_str[];
extern const char *cisd_tx_data_str[];

struct cisd {
	unsigned int cisd_alg_index;
	unsigned int state;

	unsigned int ab_vbat_max_count;
	unsigned int ab_vbat_check_count;
	unsigned int max_voltage_thr;

	/* Big Data Field */
	int data[CISD_DATA_MAX_PER_DAY];
	int cable_data[CISD_CABLE_TYPE_MAX];
};

#endif /* __SEC_CISD_H */