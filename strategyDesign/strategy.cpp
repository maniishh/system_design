#include<bits/stdc++.h>
using namespace std;
class Talkable{
    public:
    virtual void talk()=0;
    virtual ~Talkable(){}
};
class normaltalk: public Talkable{
    public:
    void talk() override {
        cout<<"normal talk";
    }
};
class notalk: public Talkable{
    public:
    void talk() override {
        cout<<"no talk";
    }
};
class Walkable{
    public:
    virtual void walk()=0;
     virtual ~Walkable(){}
};
class normalwalk: public Walkable{
    public:
    void walk() override {
        cout<<"normal walk";
    }
};
class nowalk: public Walkable{
    public:
    void walk() override {
        cout<<"no walk";
    }
};
class Flyable{
    public:
    virtual void fly()=0;
     virtual ~Flyable(){}
};
class normalfly: public Flyable{
    public:
    void fly() override {
        cout<<"normal fly";
    }
};
class nofly: public Flyable{
    public:
    void fly() override {
        cout<<"no fly";
    }
};

class Robot{
    protected:
    Talkable *talkbehaviour;
    Walkable *Walkbehaviour;
    Flyable *flybehaviour;
    public:
    Robot(Walkable *w ,Talkable *t ,Flyable *f){
        this->Walkbehaviour=w;
        this->talkbehaviour=t;
        this->flybehaviour=f;
    };
    void walk(){
        Walkbehaviour->walk();
    }
     void talk(){
        talkbehaviour->talk();
    }
     void fly(){
        flybehaviour->fly();
    }
    virtual void projection()=0;

};

class companionR: public Robot{
    public:
    companionR(Walkable* w,Talkable * t, Flyable* f) : Robot(w,t,f){

    }
};