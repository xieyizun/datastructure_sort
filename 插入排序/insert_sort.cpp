#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
#include<iomanip>
using namespace std;
void insert_sort(int begin, int length, int arr[], double& run_time) {
     clock_t begin_time;
     begin_time = clock();
     
     for (int inserted_element_index = begin + 1; inserted_element_index < length; inserted_element_index++) {
        int former_sorted_element_index = inserted_element_index - 1;
        int inserted = inserted_element_index;
        int temp = arr[inserted_element_index];
        while (former_sorted_element_index >= begin && arr[former_sorted_element_index] > temp) {
              arr[inserted] = arr[former_sorted_element_index];
              former_sorted_element_index--;
              inserted--;
        }
        arr[inserted] = temp;
     }
     
     clock_t end_time;
     end_time = clock();
     run_time = ((double)(end_time - begin_time))/((double)CLK_TCK);
}
//read test datas from file
vector<int> read_TestDatas_from_file(string file_name) {    
    ifstream data(file_name.c_str());
    string read_data;
    vector<int> datas;
    while (data >> read_data) {
          int value;
          if (read_data != ";") {
              istringstream convert_to_int(read_data);
              convert_to_int >> value;
              datas.push_back(value);
          } else if (read_data == ";") {
              datas.push_back(-1);
          }
    }
    data.close();
    return datas;
}      
int main() {
    string file_name;
    cout << "Please enter the file you would like to open: ";
    cin >> file_name;
    cout << endl;
    vector<int> datas = read_TestDatas_from_file(file_name.c_str());
    for (int i = 0; i < datas.size();) {
        cout << datas[i] << " elements to be sorted" << endl;
        int *arr;
        int j = 0;
        arr = new int[datas[i]];
        int k = 0;
        for (j = i + 1, k = 0; j <= datas[i] + i; j++, k++) {
            arr[k] = datas[j];
        }
        cout << left << setw(18) <<  "not sorted: ";
        for (int x = 0; x < datas[i]; x++) {
            cout << arr[x] << " ";
        }
        cout << endl;
        double run_time = 0.0;
        insert_sort(0, datas[i], arr, run_time);
        cout << left << setw(18) << "selection_sort: ";
        for (int x = 0; x < datas[i]; x++) {
            cout << arr[x] << " ";
        }
        cout << endl;
        cout << "Run time is: " << run_time << endl << endl;
        delete []arr;
        if (j + 1 == datas.size())
            break;
        else {
             i = j + 1;
        }
    }
    system("pause");
    return 0;
}
            
     
        
