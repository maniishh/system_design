/*LSP means a derived class should be substitutable for its base class without changing the correctness of the program. 
For example, if Bird has a fly() method, Penguin shouldn't 
inherit from it because Penguin cannot fly. Instead, flying
 behavior should be separated into another abstraction.*/
 #include<bits/stdc++.h>
 using namespace std;
 //BAD DESIGN
 class Bird {
public:
    virtual void fly() = 0;
};
class Sparrow : public Bird {
public:
    void fly() {
        cout << "Flying";
    }
};
class Penguin : public Bird {
public:
    void fly()  {
        throw runtime_error("Penguin can't fly");
    }
};
//So Penguin shouldn't inherit from a Bird abstraction that requires flying.
  // BETTER design

class Bird {
public:
    virtual void eat() = 0;
};
class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};
class Sparrow : public FlyingBird {
public:
    void eat() override {}
    void fly() override {}
};
class Penguin : public Bird {
public:
    void eat() override {}
};