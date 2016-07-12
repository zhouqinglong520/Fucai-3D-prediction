#ifndef __KILL_NUM_H__
#define __KILL_NUM_H__
#include "tools.h"

/*根据历史数据和规则，在可能的数据集中打上删除标记*/
/*函数命名规范
1、所有的杀号函数均以km_开头
2、函数名的第二段以h、t、u开头，分别表示处理百位、十位、个位三种情况
3、函数第三段为具体杀号函数的命名，命名时要与规则相关
*/

/*
杀百位
*/

/*开奖号的百位乘以3加3后取个位杀下期百位*/
void km_h_m3a3(int *history[4], int numbers[][4]);

/*开奖号的百位乘以7加7后取个位杀下期百位*/
void km_h_m7a7(int *history[4], int numbers[][4]);

/*
杀十位
*/
/*当期期数尾+4，杀十位*/
void km_t_taila4(int *history[4], int numbers[][4]);
/*上期十位杀本期十位*/
void km_t_t(int *history[4], int numbers[][4]);
/*
杀个位
*/

/*和值尾 + 4, 杀个位*/
void km_u_sumtaila4(int *history[4], int numbers[][4]);
/*上期十位杀本期个位*/
void km_u_t(int *history[4], int numbers[][4]);

#endif __KILL_NUM_H__