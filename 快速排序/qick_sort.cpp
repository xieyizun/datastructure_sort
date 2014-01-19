#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
using namespace std;

void quick_sort(int left, int right, int arr[], double& run_time) {
     clock_t begin_time;
     begin_time = clock();
     int i = left, j = right, x = arr[(i+j)/2];
     do {
        while (x > arr[i])
          i++;
        while (x < arr[j])
          j++;
        if (i <= j) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
     } while (i <= j);
     if (i < right)
         quick_sort(i, right, arr, run_time);
     if (j > left) 
         quick_sort(left, j, arr, run_time);
     clock_t end_time;
     end_time = clock();
     run_time = ((double)(end_time - begin_time))/((double)CLK_TCK);
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
        quick_sort(0, datas[i], arr, run_time);
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
    return 0;
}
            
