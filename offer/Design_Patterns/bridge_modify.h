//
// Created by ����� on 2024/2/29.
//

#ifndef OFFER_BRIDGE_MODIFY_H
#define OFFER_BRIDGE_MODIFY_H

//class Messager_bridge {
//
//public:
//    virtual void login() = 0;
//    virtual void sendMessage() = 0;
//    virtual void sendPicture() = 0;
//
//    virtual void PlaySound() = 0;
//    virtual void DrawShape() = 0;
//    virtual void WriteText() = 0;
//
//    virtual ~Messager_bridge(){}
//};

class Messager_bridge_imp {

public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;

    virtual ~Messager_bridge_imp(){}
};

class Messager_bridge {

protected:
    Messager_bridge_imp* messagerimp;

public:
    virtual void login() = 0;
    virtual void sendMessage() = 0;
    virtual void sendPicture() = 0;

    virtual ~Messager_bridge(){}
};



class MobileMessagerBase : public Messager_bridge_imp{
public:
    virtual void PlaySound() override {

    }

    virtual void DrawShape() override{

    }

    virtual void WriteText() override{

    }
};

class PCMessagerBase : public Messager_bridge_imp{
public:
    virtual void PlaySound() override {

    }

    virtual void DrawShape() override{

    }

    virtual void WriteText() override{

    }

};

/// ********************** ��ʵ����һ���ֽӿ� ********************** ///
class MessagerLite : Messager_bridge  { /// : public MobileMessagerBase �̳�ת Composite

    /// MobileMessagerBase* messager;           /// MobileMessagerBase

    /// Messager_bridge_imp* messagerimp;                  /// �ڶ�̬״̬�� new ����һ��   MobileMessagerBase �� PCMessagerBase
                                                /// Messager_bridge ��ʱ��һ�����顢 MobileMessagerBase �� PCMessagerBase
                                                ///  ����ֻʵ����Messager_bridge �е�һ���֡��޷�ֱ��new�����������Ҫ�ٴβ��
public:
    void login()  {
      /// do notiong
    }

    void sendMessage() {
        // messager->
    }

    void sendPicture() {
        // messager->
    }


};

class MessagerPerfect : Messager_bridge{

    // Messager_bridge_imp* messagerimp;  /// �ڶ�̬״̬�� new ����һ��   MobileMessagerBase ���� PCMessagerBase
                                /// Messager_bridge ��ʱ��һ�����顢 MobileMessagerBase �� PCMessagerBase ����ֻʵ����Messager_bridge �е�һ���֡��޷�ֱ��new����
                                /// �޸��� Messager_bridge �� ��MessagerLite �� MessagePerfect �������ж��С�������ȥ
public:
    void login()  {
        messagerimp->PlaySound();
        messagerimp->DrawShape();
        /// std::cout << perfect opration << std::endl;
    }

    void sendMessage() {
        //// ͬ�ϻ��кܶ��ظ�
    }

    void sendPicture() {

    }

};

/*
class PCMessagerLite { ///: 1. public PCMessagerBase  �̳�ת Composite

    /// PCMessagerBase* messager;
    Messager_bridge* messager;               /// 2. ��̬ new �� PCMessagerBase      ��ʱ MobileLite �� PCLite �Ѿ���ȫһ������ɾȥ

public:
    void login()  {
        messager->PlaySound();
        messager->DrawShape();
    }

    void sendMessage() {
    }

    void sendPicture() {
    }
};*/

/*
class PCMessagerPerfect : public PCMessagerBase{

    Messager_bridge* messager;  ////// �ڶ�̬״̬�� new ����һ��   PCMessagerBase
public:
    void login() override {
        PCMessagerBase::PlaySound();
        PCMessagerBase::DrawShape();
    }

    void sendMessage() override{
        //// ͬ�ϻ��кܶ��ظ�
    }

    void sendPicture() override{

    }

};*/

#endif //OFFER_BRIDGE_MODIFY_H
