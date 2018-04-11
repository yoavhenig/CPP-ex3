//
// Created by ori on 4/11/18.
//
#include <iostream>
#include<map>
#include "Member.h"
using namespace std;
int numofMembers=0;
int idnumber=1;



Member::Member(){
        id=idnumber;
        idnumber++;
        numofMembers++;

    }
Member::~Member(){
        numofMembers--;
        map <int,Member*>::iterator temp;
        temp=follows.begin();
        while(temp!=follows.end()){
            temp->second->followby.erase(id);
            temp++;
        }
        temp=followby.begin();
        while(temp!=followby.end()){
            temp->second->follows.erase(id);
            temp++;
        }
    }

    void Member::follow(Member& name) {
        if (&name != this) {
            this->follows.insert(pair<int, Member *>(name.id, &name));
            name.followby.insert(pair<int, Member *>(this->id, this));
        }
    }

    void Member::unfollow(Member& name) {
        if (&name != this) {
            this->follows.erase(name.id);
            name.followby.erase(this->id);
        }
    }

    int Member::numFollowers(){
        return followby.size();
    }

    int Member::numFollowing(){
        return follows.size();
    }

    int Member::count(){
        return numofMembers;
    }


