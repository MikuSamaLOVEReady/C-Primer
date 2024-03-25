//
// Created by 罗瑞笛 on 2024/2/29.
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

/// ********************** 再实现了一部分接口 ********************** ///
class MessagerLite : Messager_bridge  { /// : public MobileMessagerBase 继承转 Composite

    /// MobileMessagerBase* messager;           /// MobileMessagerBase

    /// Messager_bridge_imp* messagerimp;                  /// 在动态状态下 new 出来一个   MobileMessagerBase 或 PCMessagerBase
                                                /// Messager_bridge 此时是一个纯虚、 MobileMessagerBase 、 PCMessagerBase
                                                ///  仅仅只实现了Messager_bridge 中的一部分、无法直接new出来、因此需要再次拆分
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

    // Messager_bridge_imp* messagerimp;  /// 在动态状态下 new 出来一个   MobileMessagerBase 或者 PCMessagerBase
                                /// Messager_bridge 此时是一个纯虚、 MobileMessagerBase 、 PCMessagerBase 仅仅只实现了Messager_bridge 中的一部分、无法直接new出来
                                /// 修改完 Messager_bridge 后 、MessagerLite 与 MessagePerfect 在子类中都有、则提上去
public:
    void login()  {
        messagerimp->PlaySound();
        messagerimp->DrawShape();
        /// std::cout << perfect opration << std::endl;
    }

    void sendMessage() {
        //// 同上会有很多重复
    }

    void sendPicture() {

    }

};

/*
class PCMessagerLite { ///: 1. public PCMessagerBase  继承转 Composite

    /// PCMessagerBase* messager;
    Messager_bridge* messager;               /// 2. 动态 new 出 PCMessagerBase      此时 MobileLite 和 PCLite 已经完全一样可以删去

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

    Messager_bridge* messager;  ////// 在动态状态下 new 出来一个   PCMessagerBase
public:
    void login() override {
        PCMessagerBase::PlaySound();
        PCMessagerBase::DrawShape();
    }

    void sendMessage() override{
        //// 同上会有很多重复
    }

    void sendPicture() override{

    }

};*/

#endif //OFFER_BRIDGE_MODIFY_H
