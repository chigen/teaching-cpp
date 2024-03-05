#include <iostream>
#include <vector>
#include <string>

int main()
{
    // 创建一个msg的数组
    std::vector<std::string> msg{"hello ", "C++ ", "World ", "from ", "VS Code ", "and the C++ extention"};
    
    // 遍历该数组里所有的变量，并输出
    int msgLength = msg.size();
    for(int i=0; i<msgLength; ++i){
        std::cout << msg[i];
    }
    // for (const std::string& s : msg){
    //     std::cout << s;
    // }
    std::cout << std::endl;

    return 0;
}