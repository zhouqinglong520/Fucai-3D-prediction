#include "kill_num.h"


/*根据历史数据和规则，在可能的数据集中打上删除标记*/
/*开奖号的百位乘以3加3后取个位杀下期百位*/
void km_h_m3a3(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = (history[0][hundreds] * 3 + 3) % 10;
	/*开始杀号*/
	tool_kill( num, hundreds, numbers, 1000);
	printf("hundreds %d", num);
}

/*开奖号的百位乘以7加7后取个位杀下期百位*/
void km_h_m7a7(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = (history[0][hundreds] * 7 + 7) % 10;
	/*开始杀号*/
	tool_kill(num, hundreds, numbers,1000);
	printf("hundreds %d", num);
}

/*当期期数尾+4，杀十位*/
void km_t_taila4(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = ( history[0][0] + 1 + 4) % 10;
	/*开始杀号*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("ten_digit %d", num);
}
/*上期十位杀本期十位*/
void km_t_t(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = history[0][ten_digit];
	/*开始杀号*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("ten_digit %d", num);
}
/*
杀个位
*/

/*和值尾 + 4, 杀个位*/
void km_u_sumtaila4(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = ( (history[0][hundreds] + history[0][ten_digit] + history[0][units_digit]) + 4 ) % 10;
	/*开始杀号*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("units_digit %d", num);
}
/*上期十位杀本期个位*/
void km_u_t(int *history[4], int numbers[][4])
{
	/*计算规则*/
	int num = 0;
	num = history[0][ten_digit];
	/*开始杀号*/
	tool_kill(num, units_digit, numbers, 1000);
	printf("units_digit %d", num);
}
