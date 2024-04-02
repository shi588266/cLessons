/**
 * 表3.2中的最后两个转义序列 (\0oo和\xhh)是ASCII码的特殊表示。
 *  (oo 必须是有效的八进制数，即每个o可表示 0~7 中的一个数)
 * (hh 必须是有效的十六进制数，即每个 h 可表示 0~f 中的一个数)
 * 如果要用八进制ASCII码表示一个字符，可以在编码值前面加一个反斜杠(\) 并用单引号括起来。
 * 例如，如果编译器不识别警报字符 (a)，可以使用ASCII码来代替
beep = '\007'.
 */

#include <stdio.h>
int main(void)
{
    printf("\007");   //不改变活跃位值
	printf("\aStartled by the sudden sound,Sally shouted,\"By the Great Pumpkin,what was that!\"\n");
	return 0;
}