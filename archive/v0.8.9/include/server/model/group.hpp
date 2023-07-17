#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "groupuser.hpp"

class Group {
public:
    Group(int id = -1, std::string name = "", std::string desc = "") {
        this->id = id;
        this->name = name;
        this->desc = desc;
    }

    void setId(int id) { this->id = id; }
    void setName(std::string name) { this->name = name; }
    void setDesc(std::string desc) { this->desc = desc; }

    int                     getId() { return this->id; }
    std::string             getName() { return this->name; }
    std::string             getDesc() { return this->desc; }
    std::vector<GroupUser>& getUsers() { return this->users; }

private:
    int                    id;    // 群组 id
    std::string            name;  // 群组名
    std::string            desc;  // 群组描述
    std::vector<GroupUser> users; // 群组内用户列表
};

#endif