#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct _threeDigits {
	unsigned int first;
	unsigned int second;
	unsigned int third;
}threeDigits;
typedef struct _ballCount {
	unsigned int strike;
	unsigned int ball;
}ballCount;

threeDigits generate_rand_num(void);
threeDigits user_input(void);
ballCount result(threeDigits* user, threeDigits* com);
