#include <bits/stdc++.h>
#include<conio.h>


using namespace std;

const float INF = 1e9;

int main() {
	
  system("cls");
  cout<< endl <<"+------------------------------------------------------------------------------+"; 
  cout<< endl <<"|         CHUONG TRINH TIM DUONG DI NGAN NHAT BANG THUAT TOAN DIJKSTRA         |";
  cout<< endl <<"+------------------------------------------------------------------------------+"; 
  cout<<endl;
	
  //Yêu cầu người dùng nhập loại đồ thị
  char type;
  while(true) {
    cout<< endl <<"+--------------------------------------+";
    cout<< endl <<"|           Chon loai do thi           |";
    cout<< endl <<"+--------------------------------------+";
    cout<< endl <<"| 1 - Do thi co huong                  |";
    cout<< endl <<"| 2 - Do thi vo huong                  |";
    cout<< endl <<"+--------------------------------------+";
    cout<< endl << endl <<"=> Nhap loai do thi (1-2): ";
    cin >> type;
    cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
		if(type == '1') {
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      cout<< endl <<"|                                 DO THI CO HUONG                              |";
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      break;
    }
    else if (type == '2') {
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      cout<< endl <<"|                                 DO THI VO HUONG                              |";
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      break;
    }
    else { 
      cout<< endl <<"+--------------------------------------+";
      cout<< endl <<"|         Lua chon khong hop le!       |";
      cout<< endl <<"+--------------------------------------+";
      cout<< endl;
      continue;
		}
	}
    
	//Số điểm
  int numOfPoint;
  while (true) {
    cout<< endl << endl <<"=> Nhap so luong diem (MIN = 2): "; 
    cin>> numOfPoint;
    cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
    if (cin.fail())
    {
        cin.clear(); cin.ignore(512, '\n');
        cout<< endl <<"+--------------------------------------+";
        cout<< endl <<"|       Dau vao khong phai la so!      |";
        cout<< endl <<"+--------------------------------------+";
        continue; 
    }
    else if (numOfPoint <= 1) {
        cout<< endl <<"+--------------------------------------+";
        cout<< endl <<"|         So diem khong hop le!        |";
        cout<< endl <<"+--------------------------------------+";
        continue;
    }
    else {
        break;
    }
  }
  
//Độ dài các cạnh giữa 2 điểm
  vector<vector<float>> distance(numOfPoint, vector<float>(numOfPoint, INF));
  
  //Chương trình 
  while (true) {
    cout<< endl <<"+--------------------------------------+";
    cout<< endl <<"|           Chon chuc nang             |";
    cout<< endl <<"+--------------------------------------+";
    cout<< endl <<"| 1 - Nhap trong so canh               |";
    cout<< endl <<"| 2 - Hien thi ma tran trong so canh   |";
    cout<< endl <<"| 3 - Tim duong di ngan nhat           |";
    cout<< endl <<"| 4 - Thoat                            |";
    cout<< endl <<"+--------------------------------------+";
    cout << endl << endl << "=> Nhap lua chon (1-4): ";
    char choice; cin>> choice;
    cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 


    if (choice == '1') {  //Nhập số lượng cạnh
      int m; 
      int maxDis = numOfPoint * numOfPoint - numOfPoint;
      cout<< endl <<"=> Nhap so luong canh (MAX = "<<maxDis<<"): "; cin>> m;
      cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
      if (cin.fail())
      {
          cin.clear(); cin.ignore(512, '\n');
          cout<< endl <<"+--------------------------------------+";
          cout<< endl <<"|       Dau vao khong phai la so!      |";
          cout<< endl <<"+--------------------------------------+";
          continue; 
      }
      if (m > maxDis || m < 0) {
        cout<< endl <<"+--------------------------------------+";
        cout<< endl <<"|         So canh khong hop le!        |";
        cout<< endl <<"+--------------------------------------+";
        continue;
      }
      if (m == 0) {
        continue;
      }
      
      for (int i = 0; i < m; i++) {
        int x, y; float w; 
        cout<< endl <<"+--------------------------------------+";
        cout<< endl <<"|       Nhap thong tin canh            |";
        cout<< endl <<"+--------------------------------------+"<<endl;
        cout << endl << "=> Nhap diem dau va diem cuoi (0-"<<numOfPoint-1<<"): ";
        cin>>x>>y;
        cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
        if (cin.fail())
        {
            cin.clear(); cin.ignore(512, '\n');
            cout<< endl <<"+--------------------------------------+";
            cout<< endl <<"|       Dau vao khong phai la so!      |";
            cout<< endl <<"+--------------------------------------+"<<endl;
            i--; 
            continue; 
        }
        if (x == y) {
          cout<< endl <<"+--------------------------------------+";
          cout<< endl <<"| Mot diem khong the chi den chinh no! |";
          cout<< endl <<"+--------------------------------------+"<<endl;
          i--;  // Nhập lại cạnh này
          continue;
        }
        if (x < 0 || x >= numOfPoint || y < 0 || y >= numOfPoint) {
          cout<< endl <<"+--------------------------------------+";
          cout<< endl <<"|    Diem khong hop le! Nhap lai!      |";
          cout<< endl <<"+--------------------------------------+"<<endl;
          i--;  // Nhập lại cạnh này
          continue;
        }
        cout<< endl <<"+--------------------------------------+";
        cout<< endl <<"|   Nhap '0' neu khong co duong di     |";
        cout<< endl <<"+--------------------------------------+"<<endl;
        if (type == '1') {
          cout << endl <<"=> Nhap trong so canh (" << x << ") -> (" << y << "): ";
        }
        else if (type == '2') {
          cout << endl <<"=> Nhap trong so canh (" << x << ") <=> (" << y << "): ";
        }
        cin>> w;
        cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
        if (cin.fail())
        {
          cin.clear(); cin.ignore(512, '\n');
          cout<< endl <<"+--------------------------------------+";
          cout<< endl <<"| Dau vao khong phai la so! Nhap lai!  |";
          cout<< endl <<"+--------------------------------------+"<<endl;
          i--; 
          continue; 
        }

        if (w < 0) {
          cout<< endl <<"+--------------------------------------+";
          cout<< endl <<"|  Trong so khong hop le! Nhap lai!    |";
          cout<< endl <<"+--------------------------------------+"<<endl;
          i--;  // Nhập lại trọng số của cạnh này 
          continue;
        }

        if (w == 0) {
          w = INF;
        }
        
        distance[x][y] = w; 

        if (type == '2') {
            distance[y][x] = w;
        }
      }
      cout<< endl <<"+------------------------------------------------------------------------------+" << endl; 
      cout<< endl <<"+--------------------------------------+";
      cout<< endl <<"|     Da cap nhat trong so canh        |";
      cout<< endl <<"+--------------------------------------+"<<endl;
    } 
    else if (choice == '2') {
      //Hiển thị ma trận trọng số
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
    } 
    else if (choice == '3') {
      vector<int> notPointed;
      for(int j = 0; j < numOfPoint; j++) {
        bool pointed = false;
        for (int i = 0; i < numOfPoint; i++) {
          if (i == j) continue;
          if (distance[i][j] != INF) pointed = true;
        }
        if (!pointed) {
          notPointed.push_back(j);
        }
        }
      cout<< endl << "=> Cac diem khong co canh: ";
      for (int i = 0; i < notPointed.size(); i++) {
        cout<< notPointed[i] << " ";
      }
      cout<< endl <<"=> Tiep tuc? (Y/N): ";
      char answer;
      cin >> answer;
      if (answer == 'y' || answer == 'Y') {

      }
      else {
        continue;
      }

      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      cout<< endl <<"|                           TIM DUONG DI NGAN NHAT                             |";
      cout<< endl <<"+------------------------------------------------------------------------------+"<< endl ;

        
      int start;
      cout << endl <<"=> Nhap diem bat dau: ";
      cin >> start;
    
    // Thuật toán Dijkstra
    
    
    
    
    
    } 
    else if (choice == '4') {
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      cout<< endl <<"|                           KET THUC CHUONG TRINH                              |";
      cout<< endl <<"+------------------------------------------------------------------------------+"; 
      cout<<endl;
      break;
    } 
    else {
      cout<< endl <<"+--------------------------------------+";
      cout<< endl <<"|         Lua chon khong hop le!       |";
      cout<< endl <<"+--------------------------------------+";
      cout<< endl;
    }
  }
  
  return 0;
}