//
// Created by ����� on 2024/2/29.
//

#ifndef OFFER_BRIDGE_ORIGINAL_H
#define OFFER_BRIDGE_ORIGINAL_H

class Messager{

public:
    virtual void login() = 0;
    virtual void sendMessage() = 0;
    virtual void sendPicture() = 0;

    ///
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;

    virtual ~Messager(){}
};

class MobileMessagerBase : public Messager{
public:
    virtual void PlaySound() override {

    }

    virtual void DrawShape() override{

    }

    virtual void WriteText() override{

    }
};

class PCMessagerBase : public Messager{
public:
    virtual void PlaySound() override {

    }

    virtual void DrawShape() override{

    }

    virtual void WriteText() override{

    }

};

/// ********************** ��ʵ����һ���ֽӿ� ********************** ///
class MobileMessagerLite : public MobileMessagerBase{

    void login() override {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::DrawShape();
    }

    void sendMessage() override{

    }

    void sendPicture() override{

    }


};

class MobileMessagerPerfect : public MobileMessagerBase{

    void login() override {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::DrawShape();
    }

    void sendMessage() override{
        //// ͬ�ϻ��кܶ��ظ�
    }

    void sendPicture() override{

    }

};



#endif //OFFER_BRIDGE_ORIGINAL_H
