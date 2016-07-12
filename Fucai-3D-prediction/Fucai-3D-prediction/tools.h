#ifndef __TOOLS_H__
#define __TOOLS_H__

/*数位标记*/
typedef enum
{
	hundreds = 1,	/*百位数*/
	ten_digit = 2,		/*十位数*/
	units_digit = 3		/*个位数*/
}digit;

/*统一杀号函数*/
void tool_kill(int num, digit type, int numbers[][4], int num_lenth);


#endif // !__TOOLS_H__TOOL
