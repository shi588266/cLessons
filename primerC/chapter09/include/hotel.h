/**
 * 定义符号常量
 * 声明函数原型
*/
#define QUIT    5
#define HOTLE1    180.00    //hotel1的房间价格
#define HOTLE2    225.00
#define HOTLE3    255.00
#define HOTLE4    355.00
#define STARS  "*****************************"
#define DISCOUNT 0.95
// 显示选择列表
int menu(void);
//返回预定天数
int get_nights(void);
//计算费率并显示结果
void show_price(double rate, int nights);
