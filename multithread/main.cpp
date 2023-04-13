#include <iostream>
#include <pthread.h>

void *thr_fn1(void *arg){
    printf("thread 1 returning\n");
    return ((void *)1); //thread ����
}

void *thr_fn2(void *arg){
    printf("thread 2 exiting\n");
    pthread_exit((void *)2); // �߳��˳�
}

struct foo{
    int a,b,c,d;
};

void printfoo(const char *s , const struct foo *fp){
    printf("%s",s);
    printf("strcut at 0x%lx\n",(unsigned long)fp ); //0x���Դ��ĵ�ַǰ׺��%lx��ʾunsigned long ��16���������
                                                    //%ld long �з�������16���������
                                                    //�����ȫ https://en.cppreference.com/w/c/io/fprintf
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
    pthread_join(tid3,(void **)&fp); //��ʱfpָ���� thread��һƬ�ڴ棬�������Ѿ����ͷ���
    //sleep(1);
    pthread_create(&tid4,NULL,new_thr_fn2,NULL);
    printfoo("Main thread: \n" ,fp); // ����������ʵ���һ�����ͷ��˵��ڴ档��

    return 0;
}
