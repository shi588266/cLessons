/*
5.假定有一个名叫buffer的数组，它的长度为BSIZE字节，用下面这条语句把一个字符串复制到这个数组：
         strncpy( buffer, some_other_string, BSIZE – 1 );
它能不能保证buffer中的内容是一个有效的字符串？
*/
不能保证, 如果被复制的字符串的内容小于 BSIZE – 1 字节, 那么buffer中的内容是一个有效的字符串,
如果被复制的字符串的内容超过 BSIZE – 1 字节, 并且buffer中最后一个元素没有被设置为 '\0' 时就不是一个有效的字符串
