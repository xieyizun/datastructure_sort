#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
using namespace std;
void selection_sort(int begin, int len, int arr[], double& run_time) {
     clock_t start_time;
     start_time = clock();
         
     for (int i = begin; i < len; i++) {
         int smallest_index = i;
         for (int j = i + 1; j < len; j++) {
             if (arr[j] < arr[smallest_index]) {
                 smallest_index = j;
             }
         }
         if (smallest_index != i) {
             int temp = arr[i];
             arr[i] = arr[smallest_index];
             arr[smallest_index] = temp;
         }
     }
     
     clock_t end_time;
     end_time = clock();
     run_time = ((double)(end_time-start_time))/((double)CLK_TCK);
}
vector<int> read_TestDatas_from_file(string file_name) {
      //read test datas from data.txt
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
        cout << "not sorted: ";
        for (int x = 0; x < datas[i]; x++) {
            cout << arr[x] << " ";
        }
        cout << endl;
        double run_time = 0.0;
        selection_sort(0, datas[i], arr, run_time);
        cout << "selection_sort: ";
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
            
             
         
    
    
    
