//Program ini adalah program constructor
#include <iostream>//header program
using namespace std;

class contoh {//pendeklarasian atau pembentukan class
    private:
        int nilai;//pendeklarasian bahwa variable nilai mempunyai tingkat akses OOP private
    public://pendeklasrasian function dan method yang mempunyai tingkat akses OOP public
        contoh (int n) { //pendeklarasian constructor
          nilai = n;
        }

      int getNum() {//function untuk pengembalian atau mendapatkan variable nilai
          return nilai;
      }
};
int main() {//function utama
  contoh obj(10);//pendeklarasian object pada class contoh
  cout << "nilai yang diinput: " << obj.getNum() << endl;//menampilkan nilai yang diinput yaitu 10
  return 0;//pengembalian nilai menjadi 0
}
