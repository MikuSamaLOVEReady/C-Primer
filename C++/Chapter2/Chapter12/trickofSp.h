//
// Created by 罗瑞笛 on 2023/8/11.
//

#ifndef CHAPTER7_TRICKOFSP_H
#define CHAPTER7_TRICKOFSP_H

void delete_ete(){

    shared_ptr<int> p (new int(55));
    shared_ptr<int> p2 (p);

    //auto p2 = make_shared<int>(16)
    delete p.get(); //数据应该被清空了，但是sp对该内存上的OBJ没有认识
    if(!p.unique()){ //但p 和 p2 都还指向原址
        std:: cout << *p << std::endl;
    }

}



#endif //CHAPTER7_TRICKOFSP_H
