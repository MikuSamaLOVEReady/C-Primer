//
// Created by ����� on 2024/8/28.
//

#ifndef OFFER_RECUR_QUEUE_H
#define OFFER_RECUR_QUEUE_H

#include <vector>
#include <queue>

using namespace std;
template<class T>
class MyCircularQueue {
public:
    explicit MyCircularQueue(int k): container(vector<T>(k)) , head(0) , rear(0)
    {

    }

    bool enQueue(int value) {
        /// �ж��Ƿ�
        if( !isFull() ){
            container[rear] = value;
            rear = (++rear)%container.size();   /// rear����
            return true;
        }else{
            return false;
        }
    }

    ///
    bool deQueue() {
        if( !isEmpty() ){
            int va  = container[head];
            head = (++head)%container.size();
            return true;
        }else{
            return false;
        }

    }

    T Front() {

        if(isEmpty()){
            return -1;
        }else{
            return container[head];
        }

    }

    T Rear() {

        if( isEmpty() ){
            return -1;
        }else{
            if(rear == 0) return container[container.size()-1];
            else{
                return container[rear-1];
            }
        }
    }

    bool isEmpty() {

        /// ��һ����queu������һ������λ����ͬ��
        if( head ==  rear  ) {
            return true;
        }else{
            return false;
        }

    }

    bool isFull() {

        if( (rear+1)%container.size() == head ){
            return true;
        }
        else{
            return false;
        }

    }

private:
    vector<int> container;
    int head;   ///  �������ӵ�Ԫ�ص� index �� ��Ϊemptyʱ�������Ϊ-1
    int rear;   ///  ָ����һ�������λ��

};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

#endif //OFFER_RECUR_QUEUE_H
