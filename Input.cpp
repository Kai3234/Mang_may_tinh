#include <bits/stdc++.h>
#include <windows.h> // Hỗ trợ UTF-8 trên Windows

using namespace std;

//Hàm chọn loại đồ thị
char chooseType() {
    char type;
    while (true) {
        cout << endl << "+--------------------------------------+";
        cout << endl << "|           Chon loai do thi           |";
        cout << endl << "+--------------------------------------+";
        cout << endl << "| 1 - Do thi co huong                  |";
        cout << endl << "| 2 - Do thi vo huong                  |";
        cout << endl << "+--------------------------------------+";
        cout << endl << endl << "=> Nhap loai do thi (1-2): ";
        cin >> type;

        if (type == '1' || type == '2') {
            cout << endl << "+------------------------------------------------------------------------------+";
            if (type == '1') {
                cout << endl << "|                              DO THI CO HUONG                                 |";
            } else {
                cout << endl << "|                              DO THI VO HUONG                                 |";
            }
            cout << endl << "+------------------------------------------------------------------------------+"; 
            return type;
        } else {
            cout << endl << "+--------------------------------------+";
            cout << endl << "|         Lua chon khong hop le!       |";
            cout << endl << "+--------------------------------------+";
        }
    }  
}

// Hàm kiểm tra nhập số nguyên hợp lệ
int checkInt(string prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << endl << "+--------------------------------------+";
            cout << endl << "|    Dau vao khong hop le! Nhap lai!   |";
            cout << endl << "+--------------------------------------+" << endl;
        } 
        else {
            return value;
        }
    }
}

// Hàm kiểm tra nhập số thực hợp lệ
float checkFloat(string prompt, float minVal) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value < minVal) {
            cin.clear();
            cin.ignore(512, '\n');
            cout << endl << "+--------------------------------------+";
            cout << endl << "|    Dau vao khong hop le! Nhap lai!   |";
            cout << endl << "+--------------------------------------+" << endl;
        } else {
            return value;
        }
    }
}

// Nhập trọng số cạnh
void inputDistanceMatrix(int numOfPoint, vector<vector<float>> &distance, char type) {
    int maxNumDis = numOfPoint * (numOfPoint - 1);
    int m = checkInt("\n=> Nhap so luong canh (MAX = " + to_string(maxNumDis) + "): ", 0, maxNumDis);

    for (int i = 0; i < m; i++) {
        int x = checkInt("\n=> Nhap diem dau (0-" + to_string(numOfPoint - 1) + "): ", 0, numOfPoint - 1);
        int y = checkInt("\n=> Nhap diem cuoi (0-" + to_string(numOfPoint - 1) + "): ", 0, numOfPoint - 1);

        if (x == y) {
            cout << "\n+--------------------------------------+";
            cout << "\n| Mot diem khong the chi den chinh no! |";
            cout << "\n+--------------------------------------+" << endl;
            i--; 
            continue;
        }
        
        float w = 0;
        cout << "\n+--------------------------------------+";
        cout << "\n|        Nhap 0 neu ko co canh!        |";
        cout << "\n+--------------------------------------+" << endl;
        if (type == '1') {
            w = checkFloat("\n=> Nhap trong so canh (" + to_string(x) + ") -> (" + to_string(y) + "): ", 0);
        }
        else if (type == '2') {
            w = checkFloat("\n=> Nhap trong so canh (" + to_string(x) + ") <=> (" + to_string(y) + "): ", 0);
        }

        // Nếu nhập 0, coi như không có đường đi
        if (w == 0) w = FLT_MAX;

        distance[x][y] = w;
        //Nếu là đồ thị có hướng
        if (type == '2') {
            distance[y][x] = w;
        }
    }

    cout << endl << "+--------------------------------------+";
    cout << endl << "|     Da cap nhat trong so canh        |";
    cout << endl << "+--------------------------------------+" << endl;  
}

// In ma trận trọng số cạnh
void printDistanceMatrix(int numOfPoint, vector<vector<float>> distance) {
    cout << endl << "+------------------------------------------------------------------------------+"; 
    cout << endl << "|                            MA TRAN TRONG SO CANH                             |";
    cout << endl << "+------------------------------------------------------------------------------+" << endl;

    //In tiêu đề bảng
    cout<<"+---+--------+";
    for (int i = 0; i < numOfPoint; i++) {
        cout << "--------+";
    }
    cout<<endl<<"|Diem\\K/C den|";
    for (int i = 0; i < numOfPoint; i++) {
        cout << setw(8) <<i<<"|";
    }
    cout<<endl;
    cout<<"+-----+------+";
    for (int i = 0; i < numOfPoint; i++) {
        cout << "--------+";
    }
    cout<<endl;

    // In các dòng bảng
    for (int i = 0; i < numOfPoint; i++) {
        cout << "|" << setw(5) << i << "|----->|";
        for (int j = 0; j < numOfPoint; j++) {
        if (distance[i][j] == FLT_MAX) cout << setw(10)<<"∞"<< "|"; 
        else cout << setw(8) << fixed << setprecision(2) << distance[i][j] << "|";
        }
        cout << endl;
    }

    // In viền cuối bảng
    cout<<"+-----+------+";
    for (int i = 0; i < numOfPoint; i++) {
        cout << "--------+";
    }

    cout << endl;
}

// In tiêu đề bảng trạng thái
void computeTableHeader(int numOfPoint) {
    cout << "+------+";
    for (int i = 0; i < numOfPoint; i++) cout << "----------+";
    cout << "----------+\n";
    cout << "| Bước |";
    for (int i = 0; i < numOfPoint; i++) cout << setw(9) << i << " |";
    cout << setw(11) << "Chọn" << " |\n";
    cout << "+------+";
    for (int i = 0; i < numOfPoint; i++) cout << "----------+";
    cout << "----------+\n";
}

// In dòng bảng trạng thái
void computeTableRow(int step, const vector<float>& minDistance, const vector<bool>& visited, int chosen) {
    cout << "| " << setw(4) << step << " |";
    for (float dist : minDistance) {
        if (dist == FLT_MAX)
            cout << setw(11) << "∞" << " |";
        else
            cout << setw(9) << fixed << setprecision(2) << dist << " |";
    }
    cout << setw(9) << chosen << " |\n";
}

// In viền cuối bảng trạng thái
void computeTableFooter(int numOfPoint) {
    cout << "+------+";
    for (int i = 0; i < numOfPoint; i++) cout << "----------+";
    cout << "----------+\n";
}

// Menu hiển thị kết quả
void menuResult(int numOfPoint, const vector<float>& minDistance, const vector<bool>& visited, const vector<int>& previous, int start) {
    cout << endl << "+-------------------------------------------------+";
    cout << endl << "|           Chon ket qua hien thi:                |";
    cout << endl << "+-------------------------------------------------+";
    cout << endl << "| 1 - Tu diem bat dau den mot diem chi dinh       |";
    cout << endl << "| 2 - Tu diem bat dau den tat ca cac diem         |";
    cout << endl << "+-------------------------------------------------+";
    cout << endl << endl << "=> Nhap lua chon (1-2): ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        // Đi từ điểm bắt đầu đến một điểm chỉ định
        int end;
        end = checkInt("\n=> Nhap diem ket thuc (0-" + to_string(numOfPoint - 1) + "): ", 0, numOfPoint - 1);

        if (minDistance[end] == FLT_MAX) {
            cout << "+) Khong co duong di tu (" << start << ") den (" << end << ").\n";
        } 
        else {
            cout << "+) Tu (" << start << ") den (" << end << "):\n";
            cout << "- Khoang cach ngan nhat: " << minDistance[end] << "\n";
            cout << "- Duong di: ";
            vector<int> path;
            for (int at = end; at != -1; at = previous[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << path[i];
            }
            cout << "\n";
        }
    } 
    else if (choice == '2') {
        cout<< endl;
        // Đi từ điểm bắt đầu đến tất cả các điểm
        for (int target = 0; target < numOfPoint; target++) {
            if (minDistance[target] == FLT_MAX) {
                cout << "+) Khong co duong di tu (" << start << ") den (" << target << ").\n";
            } else {
                cout << "+) Tu (" << start << ") den (" << target << "):\n";
                cout << "- Khoang cach ngan nhat: " << minDistance[target] << "\n";
                cout << "- Duong di: ";
                vector<int> path;
                for (int at = target; at != -1; at = previous[at]) {
                    path.push_back(at);
                }
                reverse(path.begin(), path.end());
                for (size_t i = 0; i < path.size(); i++) {
                    if (i > 0) cout << " -> ";
                    cout << path[i];
                }
                cout << "\n\n";
            }
        }
    }
    
    else {
        cout << endl << "+--------------------------------------+";
        cout << endl << "|         Lua chon khong hop le!       |";
        cout << endl << "+--------------------------------------+" << endl;
    }
}

// Thực hiện thuật toán dijkstra
void dijkstraAlgorithm(int numOfPoint, const vector<vector<float>>& distance) {
    int start;
    start = checkInt("\n=> Nhap diem dau (0-" + to_string(numOfPoint - 1) + "): ", 0, numOfPoint - 1);

    // Mảng lưu khoảng cách ngắn nhất từ điểm bắt đầu đến các đỉnh khác
    vector<float> minDistance(numOfPoint, FLT_MAX);
    minDistance[start] = 0;

    // Mảng đánh dấu các đỉnh đã được xử lý
    vector<bool> visited(numOfPoint, false);

    // Mảng lưu đường đi
    vector<int> previous(numOfPoint, -1);

    computeTableHeader(numOfPoint);

    for (int step = 1; step <= numOfPoint; step++) {
        // Tìm đỉnh chưa được xử lý có khoảng cách nhỏ nhất
        int u = -1;
        for (int j = 0; j < numOfPoint; j++) {
            if (!visited[j] && (u == -1 || minDistance[j] < minDistance[u])) {
                u = j;
            }
        }

        if (minDistance[u] == FLT_MAX) break; // Không còn đỉnh nào có thể xử lý
        computeTableRow(step, minDistance, visited, u);
        visited[u] = true;
        


        // Cập nhật khoảng cách đến các đỉnh kề
        for (int v = 0; v < numOfPoint; v++) {
            if (distance[u][v] != 0 && !visited[v]) {
                float newDist = minDistance[u] + distance[u][v];
                if (newDist < minDistance[v]) {
                    minDistance[v] = newDist;
                    previous[v] = u;
                }
            }
        }
    }
    computeTableFooter(numOfPoint);

    // Hiển thị menu cho người dùng
    menuResult(numOfPoint, minDistance, visited, previous, start);
}

int main() {
    system("cls");
    SetConsoleOutputCP(65001);

    cout << endl << "+------------------------------------------------------------------------------+"; 
    cout << endl << "|         CHUONG TRINH TIM DUONG DI NGAN NHAT BANG THUAT TOAN DIJKSTRA         |";
    cout << endl << "+------------------------------------------------------------------------------+"; 
    cout << endl;

    // Loại đồ thị
    char type = chooseType();
    
    // số đỉnh
    int numOfPoint = checkInt("\n\n=> Nhap so luong diem (MIN = 2): ", 2, INT_MAX);

    // Ma trận trọng số
    vector<vector<float>> distance(numOfPoint, vector<float>(numOfPoint, FLT_MAX));
    for (int i = 0; i < numOfPoint; i++) {
        distance[i][i] = 0;
    }

    // Menu chính
    while (true) {
        cout << endl << "+--------------------------------------+";
        cout << endl << "|           Chon chuc nang             |";
        cout << endl << "+--------------------------------------+";
        cout << endl << "| 1 - Nhap trong so canh               |";
        cout << endl << "| 2 - Hien thi ma tran trong so canh   |";
        cout << endl << "| 3 - Tim duong di ngan nhat           |";
        cout << endl << "| 4 - Thoat                            |";
        cout << endl << "+--------------------------------------+";
        cout << endl << endl << "=> Nhap lua chon (1-4): ";
        
        char choice;
        cin >> choice;

        if (choice == '1') { 
            // Nhập trọng số cạnh
            inputDistanceMatrix(numOfPoint, distance, type);
        } 
        else if (choice == '2') { 
            // Hiển thị ma trận trọng số
            printDistanceMatrix(numOfPoint, distance);
        } 
        else if (choice == '3') { 
            // Tìm đường đi ngắn nhất
            cout<< endl <<"+------------------------------------------------------------------------------+"; 
            cout<< endl <<"|                           TIM DUONG DI NGAN NHAT                             |";
            cout<< endl <<"+------------------------------------------------------------------------------+"<< endl ;
        
            while (true) {
                dijkstraAlgorithm(numOfPoint, distance);
                
                // Tiếp tục tính toán hoặc kết thúc
                char calcChoice;
                cout << endl <<"=> Tinh tu diem khac? (Y/y): ";
                cin >> calcChoice;
                if (calcChoice != 'Y' && calcChoice != 'y') {
                    break;
                }
            }
        

        } 
        else if (choice == '4') {
            //Kết thúc chương trình
            cout << endl << "+------------------------------------------------------------------------------+"; 
            cout << endl << "|                           KET THUC CHUONG TRINH                              |";
            cout << endl << "+------------------------------------------------------------------------------+"; 
            cout << endl;
            return 0;

        } 
        else {
            //Lựa chọn khóng hợp lệ
            cout << endl << "+--------------------------------------+";
            cout << endl << "|         Lua chon khong hop le!       |";
            cout << endl << "+--------------------------------------+" << endl;
        }
    }

    return 0;
}