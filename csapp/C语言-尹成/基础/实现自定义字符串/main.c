#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include "strheader.h"

void main1 () {
	mystring ms ;
	init_with_string(&ms, "hello world");
	// init(&ms);
	printfcstmstring(&ms);
	

	insert_at_end_with_char(&ms, 'a');
	printfcstmstring(&ms);

	insert_at_end_with_string(&ms, "bcd");
	printfcstmstring(&ms);

	char *pos = find_char_from_string(&ms, 'h');
	*pos = 'H';
	printfcstmstring(&ms);
	char *pos1 = find_char_from_string(&ms, 'z');
	/*printf("%x\n", pos1); //0
	pos1 = 'W';
	printfcstmstring(&ms);*/

	char *strpos = find_string_from_string(&ms, "abcd");
	*strpos = ' ';
	printfcstmstring(&ms);
	printf("ms=%x,pos=%x\n", &ms, strpos);

	int delres = delete_char_from_string(&ms, 'w');
	printfcstmstring(&ms);

	int strdelres = delete_string_from_string(&ms, " bcd");
	printfcstmstring(&ms);

	/*char *istpos = find_char_from_string(&ms, ' ');
	insert_with_char(&ms, 'w', istpos);
	printfcstmstring(&ms);*/

	char *isrtpos = find_char_from_string(&ms, 'd');
	insert_with_string(&ms, " ABCD", isrtpos);
	printfcstmstring(&ms);
}