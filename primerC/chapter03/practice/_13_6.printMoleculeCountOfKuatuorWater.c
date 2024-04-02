#include <stdio.h>
// 1 个水分子的质量约为3.0×10−23克
#define MOLE_WATER_QUAT 3.0e-23
// 1 夸脱水的质量
#define QUART_WATER_QUAT 950

/**
 * 1个水分子的质量约为3.0×10−23克。
 * 1夸脱水大约是950克。编写一个程序，
 * 提示用户输入水的夸脱数，并显示水分子的数量。
 */
int main(void)
{
    int int_quatuor;
    long double lf_quatour_molecule_count;
    printf("Enter kuatuor number of water: ");
    scanf("%d", &int_quatuor);
    
    lf_quatour_molecule_count = (int_quatuor * QUART_WATER_QUAT) / MOLE_WATER_QUAT;
    printf("%d quart of water contains: %lle molecules of water\n", int_quatuor, lf_quatour_molecule_count);
	return 0;
}