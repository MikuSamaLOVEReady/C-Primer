#include <iostream>
#include <pthread.h>

void *thr_fn1(void *arg){
    printf("thread 1 returning\n");
    return ((void *)1); //thread 返回
}

void *thr_fn2(void *arg){
    printf("thread 2 exiting\n");
    pthread_exit((void *)2); // 线程退出
}

struct foo{
    int a,b,c,d;
};

void printfoo(const char *s , const struct foo *fp){
    printf("%s",s);
    printf("strcut at 0x%lx\n",(unsigned long)fp ); //0x是自带的地址前缀，%lx表示unsigned long （16进制输出）
                                                    //%ld long 有符号数（16进制输出）
                                                    //输出大全 https://en.cppreference.com/w/c/io/fprintf
    printf(" foo.a = %d\n" , fp->a);
    printf(" foo.b = %d\n" , fp->b);
    printf(" foo.c = %d\n" , fp->c);
    printf(" foo.d = %d\n" , fp->d);
}

void *new_thr_fn1(void *arg){
    struct foo foo = {1,2,3,4}; //thread1
    printfoo("thread 1: \n", &foo);
    pthread_exit((void *)&foo);
}

void *new_thr_fn2(void *arg){
    printf("thread 2: ID is %lu\n ", (unsigned long)pthread_self() );
    pthread_exit((void*)0);
}

int main() {

    pthread_t tid1, tid2, tid3, tid4;
    void *tret;
    struct foo *fp;

    pthread_create(&tid1,NULL,thr_fn1,NULL);
    pthread_create(&tid2,NULL,thr_fn2,NULL);
    pthread_join(tid1,&tret);
    printf("thread 1 exit %ld\n", (long)tret);
    pthread_join(tid2,&tret);
    printf("thread 2 exit %ld\n", (long)tret);

    pthread_create(&tid3,NULL,new_thr_fn1,NULL);
    pthread_join(tid3,(void **)&fp); //此时fp指向了 thread的一片内存，但是他已经被释放了
    //sleep(1);
    pthread_create(&tid4,NULL,new_thr_fn2,NULL);
    printfoo("Main thread: \n" ,fp); // 我现在像访问的是一个被释放了的内存。！

    return 0;
}
