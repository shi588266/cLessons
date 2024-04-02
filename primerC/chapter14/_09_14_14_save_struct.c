/**
 * 把书名保存在bookdat文件中。如果该文件已存在，程序将显示它当前的内容，然后允许在文件中添加内容
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 61    //用于存储标题,长度比标题最大长度多1
#define AUTHOR_LEN 31    //用于存储作者,长度比作者名最大长度多1
#define MAXBKS 10       //最大书籍数量

struct book {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    float value;
};

char *s_gets(char *str, int len);

int main(void)
{
    struct book library[MAXBKS];    /*结构数组*/
    
    int count,fscount = 0;
    int index;
    FILE *fp;
    
    if ( NULL == (fp = fopen("_09_book.dat", "a+b"))) {
        puts("Open file failed.");
        exit(-1);
    }
    /**
     * 从文件指针里读取一个结构的内容,并写入到结构数组的元素中,如果成功就继续读取
     */
    rewind(fp);
    while ( 1 == fread(&(library[count]), sizeof(struct book), 1, fp) && count < MAXBKS ) {
        // 如果读取成功说明文件内容不为空
        if (0 == count) {
            puts("Current Content is:");
        }
        printf("<<%s>>--%s:$%.2f.\n", library[count].title, library[count].author, library[count].value );
        count++;
        
        if(MAXBKS == count) {
            puts("File is full");
            exit(-2);
        }
    }
    fscount = count;    //文件元素计数+1
    //向结构数组追加元素
    puts("Please add new book title.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, TITLE_LEN) && library[count].title[0] != '\0' ) {
        puts("Please enter the book author.");
        s_gets(library[count].author, AUTHOR_LEN);    //不做空白验证
        puts("Please enter the book value.");
        scanf("%f", &(library[count++].value));
        while (getchar() != '\n') {
            continue;
        }
        // 数组元素未填满则继续
        if ( count < MAXBKS ) {
            puts("Please enter the next book title.");
            puts("Press [enter] at the start of a line to stop.");
        }
    }
    
    if (count > 0) {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++ ) {
            printf("<<%s>>--%s:$%.2f.\n", library[index].title, library[index].author, library[index].value);
        }
        // 这里也可以一次性把新的元素结构写入
        fwrite(&(library[fscount]), sizeof(struct book), count - fscount, fp);
    } else {
        puts("No book? That's too bad.");
    }
    puts("Bye!");
    fclose(fp);
    return 0;
}

char * s_gets(char *str, int len) {
    char *res = fgets(str, len, stdin);
    char *find;
    if (res) {
        if (find = strchr(res, '\n')) 
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return res;
}