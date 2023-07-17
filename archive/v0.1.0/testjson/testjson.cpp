#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <map>
#include <string>
#include <vector>

// json 序列化示例一
void test_json_1() {
    json js; // 理解为底层由链式哈希表实现，无序的

    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    std::string sendBuf = js.dump(); // json 数据对象序列化为 json 字符串
    std::cout << sendBuf.c_str() << std::endl;
    std::cout << js << std::endl;
}

// json 序列化示例二
void test_json_2() {
    json js;

    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};

    // 添加key-value
    js["name"] = "zhang san";

    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";

    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {
        {"zhang san", "hello world"},
        { "liu shuo", "hello china"}
    };

    std::cout << js << std::endl;
}

// json 序列化示例三
void test_json_3() {

    json js;

    // 直接序列化一个vector容器
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;

    // 直接序列化一个map容器
    std::map<int, std::string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    std::cout << js << std::endl;
}

// 序列化
std::string sequence1() {
    json js; // 理解为底层由链式哈希表实现，无序的

    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    // json 数据对象序列化为 json 字符串
    std::string sendBuf = js.dump();
    return sendBuf;
}

std::string sequence2() {
    json js;

    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};

    // 添加key-value
    js["name"] = "zhang san";

    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";

    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {
        {"zhang san", "hello world"},
        { "liu shuo", "hello china"}
    };

    // json 数据对象序列化为 json 字符串
    std::string sendBuf = js.dump();
    return sendBuf;
}

std::string sequence3() {
    json js;

    // 直接序列化一个vector容器
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;

    // 直接序列化一个map容器
    std::map<int, std::string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    // json 数据对象序列化为 json 字符串
    std::string sendBuf = js.dump();
    return sendBuf;
}

int main() {
    // test_json_1();

    std::string recvBuf = sequence1();
    // 数据的反序列化, json 字符串反序列化为 json数据对象(看做容器，方便访问)
    json jsbuf = json::parse(recvBuf);

    std::cout << jsbuf["msg_type"] << std::endl;
    std::cout << jsbuf["from"] << std::endl;
    std::cout << jsbuf["to"] << std::endl;
    std::cout << jsbuf["msg"] << std::endl;

    // std::string recvBuf = sequence2();
    // json jsbuf = json::parse(recvBuf);
    // auto msgjs = jsbuf["msg"];
    // std::cout << msgjs["zhang san"] << std::endl;
    // std::cout << msgjs["liu suo"] << std::endl;

    // std::string recvBuf = sequence3();
    // json        jsbuf = json::parse(recvBuf);
    // std::vector<int> vec = jsbuf["list"]; // js 对象里面的数组类型，直接放入 vector 容器当中
    // for (int& v : vec) {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;
    // std::map<int, std::string> mymap = jsbuf["path"];
    // for (auto& p : mymap) {
    //     std::cout << p.first << " " << p.second << std::endl;
    // }
    // std::cout << std::endl;

    return 0;
}