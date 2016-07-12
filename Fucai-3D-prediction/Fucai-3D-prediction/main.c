/*主程序文件*/
#include <stdio.h>
#include <stdlib.h>
#include "kill_num.h"

#define INPUT_FILEPATH "G:\\WORK_PROJECTS\\福彩3D彩票选号程序\\Debug\\history.txt"
/*************
数据结构定义
*************/
/*保存数据的结构*/
typedef int **PPDATAS;
/*保存所有可能号码的数组*/
int numbers[1000][4];

/*****************/
/*主流程函数定义 */
/*****************/

/*1、初始化需要的数据结构*/
void init(int nums[1000][4])
{
	/*生成号码，操作numbers*/
	/*规则：第一列是标记位，默认置0，后三位为生成的号码，从000～999*/

	int num = 0;
	for (int i = 0; i < 1000; i++)
	{
		nums[i][0] = 0;
		nums[i][1] = i / 100;
		nums[i][2] = (i % 100) / 10;
		nums[i][3] = i % 100 % 10;
	}

}
/*2、读取往期开奖数据
输入：数据文件的路径，保存数据的数组指针
返回值：读取成功还是失败，成功1，失败0
*/
int read_data(char path[],int **input[4], int *length)
{
	FILE* fp_input = NULL;
	if ( (fp_input = fopen(path, "r")) == NULL )
	{
		printf("打开文件失败！\n");
		return 0;
	}
	*length = 0;
	int arr_length = 100;
	
	int** pp_datas = *input;
	pp_datas = (int **)malloc(sizeof(int *)*arr_length);
	char buf[20];
	while (!feof(fp_input))
	{
		if (arr_length <= *length)
		{
			arr_length += 10;
			pp_datas = (int **)realloc(pp_datas, sizeof(int *) * arr_length);
		}
		pp_datas[*length] = (int*)malloc(sizeof(int) * 4);
		fscanf(fp_input, "%s\t%d\t%d\t%d\t%d\n", 
			buf,
			&(pp_datas[*length][0]),
			&(pp_datas[*length][1]),
			&(pp_datas[*length][2]),
			&(pp_datas[*length][3]));
		(*length)++;
	}

	fclose(fp_input);
	*input = pp_datas;
	return 1;
}
/*3、筛选号码
输入：往期数据、备选数据
输出：选好的数据
返回值：处理成功还是失败,成功1，失败0
*/
int filt_data( int* input[4], int datas[][4], int **out[4], int* length )
{
	*length = 0;
	
	//int** pp_datas = *out;

	km_h_m3a3(input,datas);
	km_h_m7a7(input, datas);
	km_t_taila4(input, datas);
	km_t_t(input, datas);
	km_u_sumtaila4(input, datas);
	km_u_t(input, datas);

	/*生成输出数据*/
	int arr_length = 10;
	//pp_datas = (int **)malloc(sizeof(int *) * arr_length );
	*out = (int **)malloc(sizeof(int *)* arr_length);
	int** pp_datas = *out;
	for (int i = 0; i < 1000; i++)
	{
		if (arr_length <= *length)
		{
			arr_length += 10;
			pp_datas = (int **)realloc(pp_datas, sizeof(int *) * arr_length);
		}
		if (datas[i][0] == 0)
		{
			pp_datas[*length] = (int*)malloc(sizeof(int)* 4);
			pp_datas[*length][0] = *length;
			pp_datas[*length][1] = datas[i][1];
			pp_datas[*length][2] = datas[i][2];
			pp_datas[*length][3] = datas[i][3];
			(*length)++;
		}
	}
	*out = pp_datas;
	return 0;
}
/*4、输出号码
输入：选好的数据
输出：控制台输出即可
*/
void output_data(int *numbers[4], int length)
{
	int** pp_tmp = numbers;
	for (int i = 0; i < length; i++)
	{
		printf("编号：%d\t号码：[%d][%d][%d]\n", (*pp_tmp)[0], (*pp_tmp)[1], (*pp_tmp)[2], (*pp_tmp)[3]);
		pp_tmp++;
	}
}

void free_array(int **arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		free((arr)[i]);
	}
	free(arr);
}

int main(int argc, char** argv)
{
	PPDATAS pp_input = NULL;
	PPDATAS pp_output = NULL;
	int input_num = 0;/*输入数据的条数*/
	int output_num = 0;
	/*1、初始化需要的数据结构*/
	init(numbers);

	/*2、读取往期开奖数据*/
	if ( !read_data(INPUT_FILEPATH, &pp_input, &input_num))
	{
		system("pause");
		return -1;
	}
	/*3、筛选号码*/
	filt_data(pp_input, numbers, &pp_output, &output_num);

	/*4、输出号码*/
	output_data(pp_output, output_num);

	/*5、释放内存*/
	//free_array(pp_input, input_num);
	//free_array(pp_output, output_num);


	system("pause");
	return 0;
}

