#include <bits/stdc++.h>
using namespace std;

const float INF = 1e9;

int main(){
	int Haidang;
	while(true){
		    cout<< endl <<"Nhap loai do thi(Do thi co huong: 1/Do thi vo huong: 2): ";
	        cin >> Haidang;
		if(Haidang == 1 || Haidang == 2){
	        break;
	    }
	    else{ 
		    continue;
		}
	}
    
	//Số điểm
    int numOfPoint;
    cout<< "Nhap so luong diem: "; cin>> numOfPoint;
    
	//Độ dài các cạnh giữa 2 điểm
    vector<vector<float>> distance(numOfPoint, vector<float>(numOfPoint, INF));
   
   //Chương trình 
    while (true) {
        cout << "\nChon chuc nang:\n";
        cout << "1. Nhap trong so canh\n";
        cout << "2. Xem ma tran trong so\n";
        cout << "3. Tim duong di ngan nhat\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";

        int kienngu; cin>> kienngu;

        if (kienngu == 1) {  //Nhập số lượng cạnh
            int m; 
            cout<< "Nhap so luong canh: "; cin>> m;
            for (int i = 0; i < m; i++) {
               int x, y; float w; 
			   cout<< "Nhap diem thu nhat va diem thu hai: "; cin>> x>> y;
			    if (x < 0 || x >= numOfPoint || y < 0 || y >= numOfPoint || x == y) {
                   cout << "Diem khong hop le! Nhap lai.\n";
                   i--;  // Nhập lại cạnh này
                   continue;
                }
			    cout << "Nhap trong so canh (" << x << "," << y << "): ";
			    cin>> w;
			    if (w < 0) {
              cout << "Trong so khong hop le! Nhap lai.\n";
              i--;  // Nhập lại trọng số của cạnh này 
              continue;
          }

          if (w == 0) {
            w = INF;
          }
			    
			    distance[x][y] = w; 
			
			    if (Haidang == 2) {
                   distance[y][x] = w;
                }
	        }
            cout << "Da cap nhat trong so canh!\n";
        } 
        else if (kienngu == 2) {
            //Hiển thị ma trận trọng số
            cout << endl << "Ma tran trong so vua nhap:\n";
            for (int i = 0; i < numOfPoint; i++) {
                for (int j = 0; j < numOfPoint; j++) {
                    if (i == j) cout <<"0.00 "; // Trọng số từ một đỉnh tới chính nó là 0
                    else if (distance[i][j] == INF) cout << "INF  "; // Không có cạnh nối
                    else cout << fixed << setprecision(2) << distance[i][j] << " ";
                }
                cout << endl;
            }
        } 
        else if (kienngu == 3) {
            cout << "Tim duong di ngan nhat: \n";
            
			int start, end;
            cout << "Nhap diem bat dau: ";
            cin >> start;
            cout << "Nhap diem ket thuc: ";
            cin >> end;
        
        // Thuật toán Dijkstra
        
        
        
        
        
        } 
        else if (kienngu == 4) {
            cout << "Thoat chuong trinh.\n";
            break;
        } 
        else {
            cout << "Lua chon khong hop le! Nhap lai.\n";
        }
    }
    
    return 0;
}

