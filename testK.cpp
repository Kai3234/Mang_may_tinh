#include <bits/stdc++.h>
using namespace std;

// Phần thử của Khải. Ko làm vào đây

const float INF = 1e9;



int main(){
  int numOfPoint = 10;
  vector<vector<float>> distance(numOfPoint, vector<float>(numOfPoint, INF));

  cout<< endl <<"+------------------------------------------------------------------------------+"; 
  cout<< endl <<"|                            MA TRAN TRONG SO CANH                             |";
  cout<< endl <<"+------------------------------------------------------------------------------+"<< endl << endl;

  cout<<"+---+--------+";
  for (int i = 0; i < numOfPoint; i++) {
    cout << "--------+";
  }
  cout<<endl;
  cout<<"|Diem\\K/C den|";
  for (int i = 0; i < numOfPoint; i++) {
    cout << setw(8) <<i<<"|";
  }
  cout<<endl;
  cout<<"+-----+------+";
  for (int i = 0; i < numOfPoint; i++) {
    cout << "--------+";
  }
  cout<<endl;
  for (int i = 0; i < numOfPoint; i++) {
    cout << "|" << setw(5) << i << "|----->|";
    for (int j = 0; j < numOfPoint; j++) {
      if (i == j) cout << setw(8) <<"0"<<"|"; // Trọng số từ một đỉnh tới chính nó là 0
      else if (distance[i][j] == INF) cout << setw(8)<<"INF"<< "|"; // Không có cạnh nối
      else cout << setw(8) << fixed << setprecision(2) << distance[i][j] << "|";
    }
    cout << endl;
  }
  cout<<"+------------+";
  for (int i = 0; i < numOfPoint; i++) {
    cout << "--------+";
  }

  cout << endl;
};