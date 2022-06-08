#include "baseball.h"

threeDigits generate_rand_num()
{
	threeDigits rand_num;
	srand(time(NULL));
	while (1)
	{
		rand_num.first = rand() % 9 + 1;
		rand_num.second = rand() % 9 + 1;
		rand_num.third = rand() % 9 + 1;
		if (rand_num.first != rand_num.second && rand_num.first != rand_num.third && rand_num.second != rand_num.third)
			break;
	}
	return rand_num;
}
threeDigits user_input()
{
	threeDigits input;
	while (1)
	{
		printf("숫자 3개를 입력하세요:");
		scanf("%d %d %d", &input.first, &input.second, &input.third);
		if (input.first == 0 || input.second == 0 || input.third == 0)
		{
			printf("숫자는 0을 허용하지 않습니다.다시 입력하세요.\n");
			continue;
		}
		else if (input.first == input.second || input.first == input.third || input.second == input.third)
		{
			printf("숫자는 중복을 허용하지 않습니다.다시 입력하세요.\n");
			continue;
		}
		else break;
	}
	return input;
}
ballCount result(threeDigits* user, threeDigits* com)
{
	ballCount re;
	re.ball = 0;
	re.strike = 0;
	if (user->first == com->first)
		re.strike++;
	if (user->second == com->second)
		re.strike++;
	if (user->third == com->third)
		re.strike++;
	if (user->first == com->second || user->first == com->third)
		re.ball++;
	if (user->second == com->first || user->second == com->third)
		re.ball++;
	if (user->third == com->first || user->third == com->second)
		re.ball++;
	return re;
}
int main()
{
	int i = 0;
	threeDigits rand_num;
	threeDigits u_input;
	ballCount re_rand;
	rand_num = generate_rand_num();
	while (1)
	{
		if (i == 10)
		{
			printf("탈락\n");
			printf("숫자는 %d 였습니다.\n", rand_num);
			break;
		}
		u_input = user_input();
		re_rand = result(&u_input, &rand_num);
		if (re_rand.strike == 3)
		{
			printf("정답을 맞추셨습니다.\n");
			break;
		}
		else {
			printf("%d 스트라이크 %d 볼 입니다.\n", re_rand.strike, re_rand.ball);
		}
		i++;
	}
}
