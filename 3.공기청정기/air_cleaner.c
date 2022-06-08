#define _CRT_SECURE_NO_WARNINGS
#include "air_cleaner.h"
#include <stdlib.h>

struct air_cleaner samsong_air_cleaner;
uint8_t get_abc123_co2_level() {
	int co2 = rand() % 100 + 1; //난수생성 
	printf("abc123 CO2 Sensor is initialized\n");
	printf("--> measuring CO2 level..\n");
	return co2;
}
uint8_t get_abc123_lpg_gas_level()
{
	int lpg = rand() % 100 + 1;//난수생성 
	printf("abc123 Gas Sensor is initialized\n");
	printf("--> measuring LPG Gas level..\n");
	return lpg;
}
uint8_t get_abc123_dust_level() {
	int dust = rand() % 100 + 1;//난수생성 
	printf("abc123 Dust Sensor is initialized\n");
	printf("--> measuring Dust level..\n");
	return dust;
}
uint8_t get_abc123_air_quality_level(uint8_t co2, uint8_t lpg_gas, uint8_t dust) {
	uint8_t re;
	re = (co2 + lpg_gas + dust) / 3;//co2와 lpg,dust의 평균 
	printf("Calculate Air Quality\n");
	return re;
}
uint8_t abc123_start(uint8_t air_quality) {
	printf("abc123 Started: current level - %d\n", air_quality);
	return 0;
}
uint8_t abc123_stop() {
	printf("abc123 Stopped\n");
	return 0;
}

uint8_t abc123_timer(time_t start_time, time_t stop_time) {
	//tm구조체 포인터 선언  
	struct tm* fmt_start_time;
	struct tm* fmt_stop_time;
	fmt_start_time = localtime(&start_time);//time_t형을 tm구조체로 변환 
	printf("abc123 Set Timer.\n");
	printf("--> abc123 start time: %d/%02d/%02d %02d:%02d\n", fmt_start_time->tm_year + 1900, fmt_start_time->tm_mon + 1, fmt_start_time->tm_mday, fmt_start_time->tm_hour, fmt_start_time->tm_min);
	fmt_stop_time = localtime(&stop_time);//time_t형을 tm구조체로 변환
	printf("--> abc123 stop time:%d/%02d/%02d %02d:%02d\n", fmt_stop_time->tm_year + 1900, fmt_stop_time->tm_mon + 1, fmt_stop_time->tm_mday, fmt_stop_time->tm_hour, fmt_stop_time->tm_min);
}

uint8_t abc123__display_led() {
	struct air_cleaner samsong_air_cleaner;//구조체 선언 
	samsong_air_cleaner.get_co2_level = get_abc123_co2_level;
	samsong_air_cleaner.co2 = samsong_air_cleaner.get_co2_level();
	printf("--> CO2 : %d\n", samsong_air_cleaner.co2);
	samsong_air_cleaner.get_lpg_gas_level = get_abc123_lpg_gas_level;
	samsong_air_cleaner.lpg_gas = samsong_air_cleaner.get_lpg_gas_level();
	printf("--> LPG : %d\n", samsong_air_cleaner.lpg_gas);
	samsong_air_cleaner.get_dust_level = get_abc123_dust_level;
	samsong_air_cleaner.dust = samsong_air_cleaner.get_dust_level();
	printf("--> Dust: %d\n", samsong_air_cleaner.dust);
	samsong_air_cleaner.get_air_quality = get_abc123_air_quality_level;
	samsong_air_cleaner.air_quality = samsong_air_cleaner.get_air_quality(samsong_air_cleaner.co2, samsong_air_cleaner.lpg_gas, samsong_air_cleaner.dust);
	printf("--> Air Quality: %d\n", samsong_air_cleaner.air_quality);
	return 0;
}
uint8_t abc123__display_lcd() {
	struct air_cleaner samsong_air_cleaner;//구조체 선언 
	samsong_air_cleaner.get_co2_level = get_abc123_co2_level;
	samsong_air_cleaner.co2 = samsong_air_cleaner.get_co2_level();
	printf("--> CO2 : %d\n", samsong_air_cleaner.co2);
	samsong_air_cleaner.get_lpg_gas_level = get_abc123_lpg_gas_level;
	samsong_air_cleaner.lpg_gas = samsong_air_cleaner.get_lpg_gas_level();
	printf("--> LPG : %d\n", samsong_air_cleaner.lpg_gas);
	samsong_air_cleaner.get_dust_level = get_abc123_dust_level;
	samsong_air_cleaner.dust = samsong_air_cleaner.get_dust_level();
	printf("--> Dust: %d\n", samsong_air_cleaner.dust);
	samsong_air_cleaner.get_air_quality = get_abc123_air_quality_level;
	samsong_air_cleaner.air_quality = samsong_air_cleaner.get_air_quality(samsong_air_cleaner.co2, samsong_air_cleaner.lpg_gas, samsong_air_cleaner.dust);
	printf("--> Air Quality: %d\n", samsong_air_cleaner.air_quality);
	return 0;
}

int main() {
	char input[20];
	char start_time[50], stop_time[50];
	struct air_cleaner samsong_air_cleaner;
	struct tm st;
	struct tm et;
	char* token, a[50] = { 0 };
	char delim[] = "-: \n";
	int i = 0;
	time_t s_t, e_t;

	while (1)
	{
		printf("실행하고자 하는 공기청정기 기능을 입력하세요-->");
		scanf("%s", input);
		if (strcmp(input, "?") == 0)
		{
			printf("Usage: 1~9 (1: CO2 측정, 2: 가스 측정, 3: 먼지 측정, 4: 공기질 측정, 5: 공기청정기 가동, 6:  공기청정기 동작 중지, 7: 타이머 설정, 8: LED 출력, 9: LCD 출력)\n");
		}
		else if (strcmp(input, "1") == 0)
		{
			samsong_air_cleaner.get_co2_level = get_abc123_co2_level;
			samsong_air_cleaner.co2 = samsong_air_cleaner.get_co2_level();
		}
		else if (strcmp(input, "2") == 0)
		{
			samsong_air_cleaner.get_lpg_gas_level = get_abc123_lpg_gas_level;
			samsong_air_cleaner.lpg_gas = samsong_air_cleaner.get_lpg_gas_level();
		}
		else if (strcmp(input, "3") == 0)
		{
			samsong_air_cleaner.get_dust_level = get_abc123_dust_level;
			samsong_air_cleaner.dust = samsong_air_cleaner.get_dust_level();
		}
		else if (strcmp(input, "4") == 0)
		{
			samsong_air_cleaner.get_air_quality = get_abc123_air_quality_level;
			samsong_air_cleaner.air_quality = samsong_air_cleaner.get_air_quality(samsong_air_cleaner.co2, samsong_air_cleaner.lpg_gas, samsong_air_cleaner.dust);
			printf("--> Air Quality level is %d\n", samsong_air_cleaner.air_quality);
		}
		else if (strcmp(input, "5") == 0)
		{
			samsong_air_cleaner.start = abc123_start;
			samsong_air_cleaner.start(samsong_air_cleaner.air_quality);
		}
		else if (strcmp(input, "6") == 0)
		{
			samsong_air_cleaner.stop = abc123_stop;
			samsong_air_cleaner.stop();
		}
		else if (strcmp(input, "7") == 0)
		{
			printf("시작 시간을 입력하세요. (형식: 2018-03-20 11:30)\n ->");
			fflush(stdin);
			gets(start_time);
			printf("종료 시간을 입력하세요. (형식: 2018-03-20 11:30)\n ->");
			gets(stop_time);

			//입력받은 시간을 token을 이용해 분리한다 
			token = strtok(start_time, delim);
			strcpy(a, token);
			st.tm_year = atoi(a) - 1900;
			while ((token = strtok(NULL, delim)) != NULL) {
				if (i == 0)
				{
					strcpy(a, token);
					st.tm_mon = atoi(a) - 1;
					i++;
				}
				else if (i == 1)
				{
					strcpy(a, token);
					st.tm_mday = atoi(a);
					i++;
				}
				else if (i == 2)
				{
					strcpy(a, token);
					st.tm_hour = atoi(a);
					i++;
				}
				else if (i == 3)
				{
					strcpy(a, token);
					st.tm_min = atoi(a);
					i++;
				}
			}
			st.tm_sec = 0;
			st.tm_isdst = 0;

			s_t = mktime(&st); //st를 time_t형으로 변환 
			//입력받은 시간을 token을 이용해 분리한다 
			token = strtok(stop_time, delim);
			et.tm_year = atoi(token) - 1900;
			i = 0;
			while ((token = strtok(NULL, delim)) != NULL) {
				if (i == 0)
				{
					et.tm_mon = atoi(token) - 1;
					i++;
				}
				else if (i == 1)
				{
					et.tm_mday = atoi(token);
					i++;
				}
				else if (i == 2)
				{
					et.tm_hour = atoi(token);
					i++;
				}
				else if (i == 3)
				{
					et.tm_min = atoi(token);
					i++;
				}
			}

			et.tm_sec = 0;
			et.tm_isdst = 0;

			e_t = mktime(&et);//et를 time_t형으로 변환
			samsong_air_cleaner.timer = abc123_timer(s_t, e_t);
		}
		else if (strcmp(input, "8") == 0)
		{
			printf("abc123 Display information to LED.\n");
			samsong_air_cleaner.display_led = abc123__display_led;
			samsong_air_cleaner.display_led();
		}
		else if (strcmp(input, "9") == 0)
		{
			printf("abc123 Display information to LCD.\n");
			samsong_air_cleaner.display_lcd = abc123__display_lcd;
			samsong_air_cleaner.display_lcd();
		}
		else if (strcmp(input, "quit") == 0)
		{
			break;
		}
		else {
			printf("다시 입력하세요");
		}
	}
	return 0;
}
