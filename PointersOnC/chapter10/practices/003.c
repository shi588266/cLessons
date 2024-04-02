/*
计算机的任务之一就是对程序的指令进行解码，确定采取何种操作。在许多机器中，由于不同的指令具有不同的格式，因此解码过程被复杂化了。在某台特定的机器上，每个指令的长度都是16位，并实现了下列各种不同的指令格式。位是从右向左进行标记的。
*/

typedef union {
    unsigned short addr;    //使用无符号整数
    //struct MISC_INST misc;
    struct {
        unsigned opcode:16;
    } misc;
    //struct BRANCH_INST branch;
    struct {
        unsigned  offset:8;
        unsigned  opcode:8;
    } branch;
    //struct SGL_OP_INST sgl_op;
    struct {
        unsigned  opcode:10;
        unsigned  dst_mode:3;
        unsigned  dst_reg:3;
    } sgl_op;
    //struct DBL_OP_INST dbl_op;
    struct DBL_OP_INST {
        unsigned  opcode:4;
        unsigned  src_mode:3;
        unsigned  src_reg:3;
        unsigned  dst_mode:3;
        unsigned  dst_reg:3;
    } dbl_op;
    //struct REG_SRC_INST reg_src;
    struct REG_SRC_INST {
        unsigned  opcode:7;
        unsigned  src_reg:3;
        unsigned  dst_mode:3;
        unsigned  dst_reg:3;
    } reg_src;
} machine_inst;

machine_inst  x;