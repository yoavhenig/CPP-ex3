//
// Created by ori on 4/9/18.
//

#ifndef EX3_MEMBER_H
#define EX3_MEMBER_H

#endif //EX3_MEMBER_H

#include <iostream>
#include<map>
using namespace std;

class Member {

private:
    int id;
    map <int,Member*> follows;
    map <int,Member*> followby;

public:
    Member();
    ~Member();

    void follow(Member& name);

    void unfollow(Member& name);

    int numFollowers();

    int numFollowing();

    static int count();

};


