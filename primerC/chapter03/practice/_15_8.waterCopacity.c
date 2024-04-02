/**
8.在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，1盎司等于2大汤勺，1大汤勺等于3茶勺。
编写一个程序，提示用户输入杯数，并以品脱、盎司、汤勺、茶勺为单位显示等价容量。
思考对于该程序，为何使用浮点类型比整数类型更合适?
 */
#include <stdio.h>

int main(void)
{
    int cups,ozs,soups,teas;
    float pinto;
    printf("How many cups of water?\n");
    
    while (scanf("%d", &cups) == 1) {
        pinto = cups / 2.0;
        ozs = cups * 8;
        soups = ozs * 2;
        teas = soups * 3;
        printf("%d cups of water equals %d oz,%d soup, %d tea, %.2f pinto.\n\n", cups, ozs, soups, teas, pinto);
        printf("How many cups of water?\n");
    }
    printf("bye!\n");
    
    return 0;
}