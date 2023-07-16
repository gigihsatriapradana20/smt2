#include <iostream>
using namespace std;

const int N = 100;

int main(){
  int x;
  int cost[N][N];
  int tambahcost[N];
  int temp;
  int value;
  int y = 0;

  cout << "Masukkan jumlah kota : ";
  cin  >> x;

  cout << "-----Nilai cost matrix-----" << endl;

  for(int i = 0; i < x; i++){
    cout << "Cost element matriks ke - " << i+1 <<endl;
    for(int j = 0; j < x; j++){
      cin>> cost[i][j];
    }
  }

  cout << "Cost List : " << endl;

  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      cout << cost[i][j]<<" ";
    }
    cout << endl;
  }
  cout << "Jalur terpendek adalah : ";

  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      tambahcost[i] = tambahcost[i] + cost[i][j];
    }
  }
  cout << endl;

  for(int i = 0; i < x; i++){
    value = 0;
    for(int j = 0; j < x; j++){
      if(tambahcost[i] > tambahcost[j]){
        value++;
      }
    }
    if(value == y){
      if(y < x){
        cout << i+1 << " ---> ";
      }else{
        cout << i+1 << endl;
      }
      y = y + 1;
      i = -1;
    }
  }

  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      temp = tambahcost[j];
      tambahcost[j] = tambahcost[j+1];
      tambahcost[j+1] = temp;
    }
  }

  cout << "Minimum Cost : " << tambahcost[0] << endl;
  return 0;
}
