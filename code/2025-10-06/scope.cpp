#include <iostream>  
  
int globalVar = 10; //全局作用域
  
namespace MyNamespace {  
    int namespaceVar = 20; //命名空间作用域
}  
  
void myFunction(int paramVar) { // 函数参数  
    int localVar = 30; // 局部变量  
    std::cout << globalVar << ", " << MyNamespace::namespaceVar << ", " << paramVar << ", " << localVar << std::endl;  
}  
  
int main() {  
    int mainLocalVar = 40; // 另一个局部变量  
    myFunction(50);  
    std::cout << mainLocalVar << std::endl;  
    return 0;  
}