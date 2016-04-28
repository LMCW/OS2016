#define OP_NUM 200; //操作队列上限 
int op_num = 0; //队列当前等待数目
int op_list[OP_NUM]; //等待队列，奇数为读，偶数为写
int start=0;//队首位置
int end=-1;//队尾位置
semaphore_t op_sem;//队首和队尾位置,等待数目锁
semaphore_t list_read_sem;//队列读互斥锁
semaphore_t list_write_sem;//队列写互斥锁

int read_op(int id){ 
    down(&list_write_sem);//只锁写操作
    cprintf(""No.%d Reader is reading\n"",i); do_sleep(50);
    cprintf(""No.%d Reader finished reading\n"",i);
    up(&list_write_sem);
    cprintf(""No.%d Reader Sem Proc Quit\n"",i);
    return 0;
}

int write_op(int id){ 
    down(&list_write_sem);
    down(&list_read_sem);//同时锁定读写操作
    cprintf(""No.%d Writer is writing\n"",i); do_sleep(50);
    cprintf(""No.%d Writer finished writing\n"",i);
    up(&list_write_sem);
    up(&list_read_sem);//同时解锁
    cprintf(""No.%d Writer Sem Proc Quit\n"",i);
    return 0;
}

int add_op(int id){ 
    down(&op_sem);//锁定队列信息   
    if(op_num>OP_NUM)
    return -1;//队列已满
    end=(end+1)%OP_NUM;
    op_list[end]=id;
    op_num_sem++;
    up(&op_sem);
    return 0;
}

int run_op(){ 
    if(op_num==0)
    return -1;//队列为空
    if(op_list[start]%2==1){//读操作
    read_op(op_list[start]);
    }
    else{
    write_op(op_list[start]);
    }
    down(&op_sem);//锁住队列信息
    start=(start+1)%OP_NUM;
    op_num--;
    up(&op_sem);
    return 0;
}