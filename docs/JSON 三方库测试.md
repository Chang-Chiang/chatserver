# JSON 三方库测试

## JSON 简介

JSON（JavaScript Object Notation）是一个用于数据交换的文本格式，只是一种**数据格式**，可用于任何编程语言。

JSON 只包含 6 种数据类型：

- null: 表示为 null
- boolean: 表示为 true 或 false
- number: 一般的浮点数表示方式
- string: 表示为 "..."
- array: 表示为 [ ... ]
- object: 表示为 { ... }

## 三方库使用

### 包含头文件

```c++
#include "json.hpp"
using json = nlohmann::json;  // 命名空间
```

### 序列化：将对象转换为 json 格式字符串

```c++
json js;

js["msg_type"] = 2;
js["from"]     = "zhang san";
js["to"]       = "li si";
js["msg"]      = "hello, what are you doing now?";

// 通过网络发送则需将 json 对象转成字符串类型，调用 json 对象的 .dump() 方法
std::string sendBuf = js.dump(); // json 数据对象序列化为 json 字符串

// .c_str() 方法将 C++ 的 string 转化为 C 的字符串数组
// .c_str() 方法生成一个 const char * 指针，指向字符串的首地址
std::cout << sendBuf.c_str() << std::endl;
// 输出> {"from":"zhang san","msg":"hello, what are you doing now?","msg_type":2,"to":"li si"}

// 因为 json 对象提供了输出运算符重载函数故可以直接输出
std::cout << js << std::endl;  
// 输出> {"from":"zhang san","msg":"hello, what are you doing now?","msg_type":2,"to":"li si"}
```

### 反序列化：从 json 格式字符串提取对象

```c++
json js;
js["msg_type"] = 2;
std::string sendBuf = js.dump();

std::string recvBuf = sendBuf;

// 数据的反序列化, json 字符串反序列化为 json数据对象(看做容器，方便访问)
json jsbuf = json::parse(recvBuf);

std::cout << jsbuf["msg_type"] << std::endl;
// 输出> 2
```

## 参考

+ [nlohmann/json: JSON for Modern C++ (github.com)](https://github.com/nlohmann/json)

+ [从零开始的 JSON 库教程（一）：启程 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/22460835)

  

