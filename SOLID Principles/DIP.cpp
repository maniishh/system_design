#include<bits/stdc++.h>
using namespace std;

//bad design
class MySQLDatabase {
public:
    void save() {
        // save to MySQL
    }
};

class UserService {
    MySQLDatabase db;

public:
    void createUser() {
        db.save();
    }
};

//better design
class Database {
public:
    virtual void save() = 0;
    virtual ~Database() = default;
};
//mysql implement
class MySQLDatabase : public Database {
public:
    void save() override {
        // MySQL
    }
};
//mongodb implement
class MongoDB : public Database {
public:
    void save() override {
        // MongoDB
    }
};
//now userService depends on database
class UserService {
    Database& db;

public:
    UserService(Database& database) : db(database) {}

    void createUser() {
        db.save();
    }

};
/*DIP means high-level classes should depend on 
abstractions rather than concrete implementations.
 For example, UserService shouldn't directly depend 
 on MySQLDatabase. It should depend on a Database 
 interface, and MySQL or MongoDB can implement that interface.
  This reduces coupling and makes the system easier to change
   and test*/