#include<bits/stdc++.h>
using namespace std;

//bad design 
class Machine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};
class SimplePrinter : public Machine {
public:
    void print() override {
        // print
    }

    void scan() override {
        // I don't need this
    }

    void fax() override {
        // I don't need this
    }
};
//The printer is forced to implement methods it doesn't need.

// better design 
class Printer {
public:
    virtual void print() = 0;
};

class Scanner {
public:
    virtual void scan() = 0;
};

class Fax {
public:
    virtual void fax() = 0;
};
class SimplePrinter : public Printer {
public:
    void print() override {
        // print
    }
};
//split into interfaces

/*ISP says a class should not be forced to implement methods 
it doesn't need. Instead of one large Machine interface 
containing print, scan, and fax, I would split them into 
smaller interfaces so a simple printer only implements
 printing.*/