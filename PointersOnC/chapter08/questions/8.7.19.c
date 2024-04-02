/*
19.在程序8.2的关键字查找例子中，字符指针数组的末尾增加了一个NULL指针，这样就不需要知道表的长度。
那么，矩阵方案应如何进行修改才能达到同样的效果呢？写出用于访问修改后的矩阵的for语句。
*/



/*
** 判断参数是否与一个关键字列表中的任何单词匹配，并返回匹配的索引值。如果未找到匹配，函数返回-1。
*/
#include <string.h>
#include <stdio.h>
char   const  *keyword_table[] = {
         "do",
         "for",
         "if",
         "register",
         "return",
         "switch",
         "while",
         NULL
};

// 使用指针数组
int lookup_keyword( char const * const desired_word, char const *keyword_table[])
{
        char const **kwp;
        /*
        ** 对于表中的每个单词 ...
        */
        for( kwp = keyword_table; *kwp != NULL; kwp++ ) {
            /*
            ** 如果这个单词与我们所查找的单词匹配，返回它在表中的位置。
            */
            if( strcmp( desired_word, *kwp ) == 0 )
                 return kwp - keyword_table;
        }
        /*
        ** 没有找到。
        */
        return -1;
}

char   const  keyword[][9] = {
         "do",
         "for",
         "if",
         "register",
         "return",
         "switch",
         "while"
};
int size = sizeof(keyword) / sizeof(keyword[0]);
//使用矩阵
int lookup_keyword_2( char const * const desired_word, char const keyword_table[][9], int const size )
{
        char const *kwp;
        /*
        ** 对于表中的每个单词 ...
        */
        int i;
        for( i=0; i < size; i++ ) {
            kwp = keyword_table[i];
            /*
            ** 如果这个单词与我们所查找的单词匹配，返回它在表中的位置。
            */
            if( strcmp( desired_word, kwp ) == 0 )
                 return i;
        }
        /*
        ** 没有找到。
        */
        return -1;
}

int lookup_keyword_3( char const * const desired_word, char const keyword_table[][9])
{
        char const **kwp;
        /*
        ** 对于表中的每个单词 ...
        */
        for( kwp = keyword_table; **kwp != '\0'; kwp++ ) {
            /*
            ** 如果这个单词与我们所查找的单词匹配，返回它在表中的位置。
            */
            if( strcmp( desired_word, *kwp ) == 0 )
                return kwp - keyword_table;
        }
        /*
        ** 没有找到。
        */
        return -1;
}

int main(void)
{
    char *test_str = "while";
    int index;
    if ( (index = lookup_keyword(test_str, keyword_table)) < 1) {
        printf("well done! Nothing matched.\n");
    } else {
        printf("find %s at %d\n\n", test_str, index);
    }
    
    if ( (index = lookup_keyword_2(test_str, keyword, size)) < 1 ) {
        printf("well done! Nothing matched.\n");
    } else {
        printf("find %s at %d\n\n", test_str, index);
    }
    
    if ( (index = lookup_keyword_3(test_str, keyword)) < 1 ) {
        printf("well done! Nothing matched.\n");
    } else {
        printf("find %s at %d\n\n", test_str, index);
    }
}