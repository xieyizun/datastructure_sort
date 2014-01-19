#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main() {
    string file_name;
    cout << "请输入你要保存数据的文件名: ";
    cin >> file_name;
    ofstream file(file_name.c_str());
    int group;
    int TestData_Number;
    cout << "请输入你要测试的数据的组数：";
    cin >> group;
    for (int i = 1; i <= group; i++) {
        cout << "请输入第" << i << "组数据的个数: ";
        cin >> TestData_Number;
        file << TestData_Number << " ";
        cout << "正在生成" << TestData_Number << "个随机数据并写入到文件中......." << endl;
        cout << "第" << i << "组数据写入成功!" << endl; 
        int value;
        for (int j = 0; j < TestData_Number; j++) {
            value = (rand() % TestData_Number) + 1;
            file << value << " ";
        }
        file << ";" << endl;
    }
    file.close();
    system("pause");
    return 0;
} 
            
            
         
