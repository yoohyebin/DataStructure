#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct air_cleaner {
	uint8_t co2;
	uint8_t lpg_gas;
	uint8_t dust;
	uint8_t air_quality;

	uint8_t(*get_co2_level)();
	uint8_t(*get_lpg_gas_level)();
	uint8_t(*get_dust_level)();
	uint8_t(*get_air_quality)(uint8_t co2, uint8_t lpg_gas, uint8_t dust);
	uint8_t(*start)(uint8_t air_quality);
	uint8_t(*stop)();
	uint8_t(*timer)(time_t start_time, time_t stop_time);
	uint8_t(*display_led)();
	uint8_t(*display_lcd)();
};
