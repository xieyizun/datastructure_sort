#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main() {
    string file_name;
    cout << "��������Ҫ�������ݵ��ļ���: ";
    cin >> file_name;
    ofstream file(file_name.c_str());
    int group;
    int TestData_Number;
    cout << "��������Ҫ���Ե����ݵ�������";
    cin >> group;
    for (int i = 1; i <= group; i++) {
        cout << "�������" << i << "�����ݵĸ���: ";
        cin >> TestData_Number;
        file << TestData_Number << " ";
        cout << "��������" << TestData_Number << "��������ݲ�д�뵽�ļ���......." << endl;
        cout << "��" << i << "������д��ɹ�!" << endl; 
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
            
            
         
