//
// Created by ����� on 2023/8/11.
//

#ifndef CHAPTER7_TRICKOFSP_H
#define CHAPTER7_TRICKOFSP_H

void delete_ete(){

    shared_ptr<int> p (new int(55));
    shared_ptr<int> p2 (p);

    //auto p2 = make_shared<int>(16)
    delete p.get(); //����Ӧ�ñ�����ˣ�����sp�Ը��ڴ��ϵ�OBJû����ʶ
    if(!p.unique()){ //��p �� p2 ����ָ��ԭַ
        std:: cout << *p << std::endl;
    }

}



#endif //CHAPTER7_TRICKOFSP_H
