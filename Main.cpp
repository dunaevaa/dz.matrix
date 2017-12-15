#include<iostream>
#include<string>
#include<cstring>
#include<locale>
#include<cstdlib>
#include<fstream>
using namespace std;

void cr(int**& c, int& m, int& n, int argc, char* argv[]){
    int i, j, k, d;
    k = 2;
    string str1, str2, prom;
    for (i=0; (argv[1][i] != 'x') && (argv[1][i] != 'X'); i++)
        str1 += argv[1][i];
    for (i += 1; i < strlen(argv[1]); i++)
        str2 += argv[1][i];
    m = atoi(str1.c_str());
    n = atoi(str2.c_str());
    if (m==0 || n==0)
        cout << "Неверная матрица, повторите ввод" << endl;
    c = new int*[m];
    for (i = 0; i < m; i++)
        c[i] = new int [n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            c[i][j]=0;
    if (argc==3) {
	string prom;
	d=0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			for(; d<strlen(argv[2]); d++) {
				if(argv[2][d]>='0' && argv[2][d]<='9') {
					prom = argv[2][d];
					c[i][j] = c[i][j]*10+atoi( prom.c_str() );
				} else if(argv[2][d] == ','){
				    d++;
				    break;
				}

			}
		}
}
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++, k++){
            if (k < argc )
                c[i][j] = atoi(argv[k]);
        }

}

void menu(){
    cout << "Выберите одну из операций" << endl;
    cout << "1. Вывести матрицу" << endl;
    cout << "2. Сложить матрицу" << endl;
    cout << "3. Умножить матрицу" << endl;
    cout << "4. Транспонировать матрицу" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "7. Сортировать матрицу" << endl;
    cout << "8. завершить работу программы" << endl;
}

void out(int**c, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout<< endl;}
}

void add(int**&c, int m, int n)
{
    int dopmat, i, j;
    cout << "Введите матрицу " << a << "x" << b << endl;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        cin >> dopmat;
        c[i][j] = c[i][j] + dopmat;}
    }
    cout << endl;
    for( i=0; i < m; i++){
        for(j=0; j < n; j++){
        cout << c[i][j] << " ";}
    cout << endl;
    }
}

void mul(int**&c, int &m, int &n)
{
    if (c == nullptr){
    cout << " Пустая матрица ";
    return;
}
    string cs;
    int m1=0;
    int n1=0;
    cout << "Введите размер матрицы" << endl;
    cin >> cs;
    m1 = atoi(cs.c_str());

}

void stf(int**c, int m, int n)
{
    int i, j;
    ofstream file ("matrix.txt");
    file << m << "x" << n << endl;
    for (i=0; i < m; i++){
        for (j=0; j < n; j++)
        file << c[i][j] << " ";
        file << endl;
    }
    file.close();
}

void lff(int**&c, int &m, int &n)
{
    int i, j;
    ifstream filein("matrix.txt");
    if (filein.is_open()) {
        filein >> m >> n;
        c = new int*[m];
        for (i=0; i<m; i++)
        c[i] = new int[n];
        for (i=0; i<m; i++)
            for(j=0; j<n; j++)
            filein >> c[i][j];
        filein.close();
    }
    else cout << " Файл не найден ";
}

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "Russian");
    int** c = nullptr;
    int m, n;
    int choise;
    if (argc<3){
    cout << "Hеверное количество элементов" << endl;
    return 0;}
    cr(c, m, n, argc, argv);
    while(true){
        menu();
        cin >> choise;
        switch (choise){
            case 1:
            out (c, m, n);
            break;
            case 2:
            add (c, m, n);
            break;
            case 5:
            stf(c, m, n);
            break;
            case 6:
            lff(c, m, n);
            break;
            case 8:
              return 0;
        }
    }
}
