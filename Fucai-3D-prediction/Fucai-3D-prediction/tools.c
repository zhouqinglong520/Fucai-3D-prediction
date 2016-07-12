#include "tools.h"
/*¹¤¾ßº¯Êý*/

void tool_kill(int num, digit type, int numbers[][4], int num_lenth)
{
	for (int i = 0; i < num_lenth; i++)
	{
		numbers[i][0] = numbers[i][type] == num ? 1 : numbers[i][0];
	}
}