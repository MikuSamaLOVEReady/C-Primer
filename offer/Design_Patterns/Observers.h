//
// Created by 罗瑞笛 on 2024/4/11.
//

#ifndef OFFER_OBSERVERS_H
#define OFFER_OBSERVERS_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>

class observer{
public:
    virtual void update(int time ) = 0;
};

class student : public observer{
public:
    student( std::string s) : name(s) {};
    void update(int time) override{
        std::cout << name << " " << time << std::endl;
    }

private:
    std::string name;
};

class subject{
public:
    virtual void registerObserver( std::shared_ptr<observer>)   = 0;
    virtual void removeObserver( std::shared_ptr<observer>) = 0;
    virtual void notifyObservers() = 0;
};

class Clock : public subject{
public:
    explicit Clock(int t):time(t){};
    void registerObserver(std::shared_ptr<observer> ob) override{
        obs.push_back(ob);
        return ;
    }

    void removeObserver(std::shared_ptr<observer> ob) override{
        /// std::remove 返回不含ob的vecotr的 end_iterator();
        obs.erase(std::remove(obs.begin() , obs.end() , ob) , obs.end());
        return;
    }

    void notifyObservers() override {

        for(auto it : obs){
            it->update(time);
        }
    }

    void tick() {
        time++;
        notifyObservers();
    }

private:
    int time;
    std::vector<std::shared_ptr<observer>> obs;
};


/*
/// 观察者

class AbstractObservers {

public:
    AbstractObservers() = default;
    virtual void update()
    {
        std::cout << " default update " << std::endl;
        return;
    }

private:
};

class LRDObserver : public AbstractObservers{
public:
    void update() override{
        std::cout << " LRD LOVE MIKE update " << std::endl;
        return;
    }
};

class LSAMAObserver : public AbstractObservers{
public:
    void update() override{
        std::cout << " LSAMA LOVE SAMA update " << std::endl;
        return;
    }
};



/// event发生端
class AbstractSubject{

public:
    AbstractSubject() = default;

    void RegisterObserver( AbstractObservers* ob){
        observers.push_back(ob);
        return;
    }

    void RemoveObserver( AbstractObservers* ob){
        for( auto it=observers.begin()  ; it != observers.end() ; it++)
        {
            if(*it == ob) observers.erase(it);
        }
    }

    inline virtual void notifyObservers(){
        for( auto ob : observers){
            ob->update();
        }
        return;
    }

private:
    std::vector<AbstractObservers*> observers;
};

/// concret subclass
class MIKUSubject : public  AbstractSubject{
public:
    void notifyObservers() override{
        AbstractSubject::notifyObservers();
        std::cout << " MIKU SUBJECT! " << std::endl;
    }

};

class SAMASubject : public  AbstractSubject{
public:
    void notifyObservers() override{
        AbstractSubject::notifyObservers();
        std::cout << " SAMA SUBJECT! " << std::endl;
    }

};
*/



#endif //OFFER_OBSERVERS_H
