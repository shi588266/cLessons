/**
 * 7.1英寸相当于2.54厘米。编写一个程序，提示用户输入身高（/英
寸），然后以厘米为单位显示身高。
*/
#include <stdio.h>

int main(void){
    float fl_height;
    float fl_common_height;
    printf("Enter the feet of your height: ");
    scanf("%f", &fl_height);
    
    fl_common_height = 2.54 * fl_height;
    printf("your height %f feet convert to common height is %f cm \n", fl_height, fl_common_height);
	return 0;
}