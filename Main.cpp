#include<iostream>
#include<string>
#include<cstring>
#include<locale>
#include<cstdlib>
#include<fstream>
using namespace std;

void cr(int**& matrix, int& m, int& n, int argc, char* argv[]) {
    int i, j, k;
    k = 2;
    string str1, str2;
    for (i=0; (argv[1][i] != 'x') && (argv[1][i] != 'X'); i++)
        str1 += argv[1][i];
    for (i += 1; i < strlen(argv[1]); i++)
        str2 += argv[1][i];
    m = atoi(str1.c_str());
    n = atoi(str2.c_str());
    if (m==0 || n==0)
        cout << "Неверный размер матрицы, повторите ввод" << endl;
    matrix = new int *[m];
    for (i = 0; i<m; i++)
        matrix[i] = new int [n];
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            matrix[i][j] = 0;
    if (argc == 3) {
	string str3;
	int z=0;
	for (i=0; i<m; i++)
		for (j=0; j<n; j++) {
			for (z=0; z < strlen(argv[2]); z++) {
				if (argv[2][z]>='0' && argv[2][z]<='9') {
					str3 = argv[2][z];
					matrix[i][j] = matrix[i][j]*10 + atoi(str3.c_str());
				} else if (argv[2][z] == ',') {
				    z++;
				    break;
				  }

			}
		}
   }
    for (i = 0; i<m; i++)
        for (j = 0; j<n; j++, k++) {
            if (k < argc)
                matrix[i][j] = atoi(argv[k]);
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
    cout << "8. Завершить работу программы" << endl;
}

void out(int** matrix, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void add(int**&matrix, int m, int n) {
    int matrix1, i, j;
    cout << "Введите матрицу " << m << "x" << n << endl;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
        cin >> matrix1;
        matrix[i][j] = matrix[i][j] + matrix1; 
	}
    }
    cout << endl;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
        cout << matrix[i][j] << " ";
	}
    cout << endl;
    }
}

void mul(int**&matrix, int m, int n)
{
    int i, j, a, b, c;
    string size, s1, s2;
    cout << "Введите размер матрицы" << endl;
    cin >> size;
    for (i=0; (size[i] != 'x') && (size[i] != 'X'); i++)
        s1 += size[i];
    for (i+=1; i<size.length(); i++) 
        s2 += size[i];
    a = atoi(s1.c_str());
    b = atoi(s2.c_str());
    if (n == a) {
        cout << "Введите элементы матрицы" << endl;
        int **matrix2;
        matrix2 = new int*[n];
        for (i=0; i<a; i++)
            matrix2[i] = new int[b];
        for (i=0; i<a; i++)
            for (j=0; j<b; j++)
                cin >> matrix2[i][j];
        int **matrix3;
        matrix3 = new int*[m];
        for (i=0; i<m; i++)
            matrix3[i] = new int[b];
        for (i=0; i<m; i++)
            for (j=0; j<b; j++)
                matrix3[i][j] = 0;
        for (i=0; i<m; i++) {
            for (j=0; j<b; j++) {
                for (c=0; c<a; c++)
                     matrix3[i][j] += matrix[i][c] * matrix2[c][j];
	    }
	}	
        cout << "Результат:" << endl;
        n = a;
        for (i=0; i<b; i++)
            delete[] matrix2[i];
        delete[] matrix2;
        for (i=0; i<m; i++)
            delete[] matrix[i];
        delete[] mstrix;
        matrix = matrix3;
        out(matrix, m, n);
    }
    else cout << "Неверный размер";
}

void tran(int**&matrix, int &m, int &n) {
    int i, j;
    int **matrix1 = nullptr;
    matrix1 = new int*[n];
    for (i=0; i<n; i++)
    matrix1[i] = new int[m];
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
        matrix1[i][j] = matrix[j][i];
        for (i=0; i<m; i++)
            delete[] matrix[i];
        delete[] matrix;
    matrix = matrix1;
    swap (m, n);
}

void stf(int**matrix, int m, int n)
{
    int i, j;
    ofstream file("matrix.txt");
    file << m << "x" << n << endl;
    for (i=0; i<m; i++){
        for (j=0; j<n; j++)
        file << matrix[i][j] << " ";
        file << endl;
    }
    file.close();
}


void lff(int**&matrix, int &m, int &n)
{
    int i, j;
    ifstream fin("matrix.txt");
    if (fin.is_open()) {
        fin >> m >> n;
        if (mutrix != nullptr) {
        for (int i=0; i<m; i++)
        delete [] matrix[i];
        delete [] matrix;
        }
        matrix = new int*[m];
        for (i=0; i<m; i++)
        matrix[i] = new int[n];
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
            fin >> matrix[i][j];
        fin.close();
    }
    else cout << "Файл не найден";
}

int main (int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    int** matrix = nullptr;
    int m, n;
    int choise;
    if (argc < 3) {
    cout << "Hеверное количество элементов" << endl;
    return 0;
    }
    cr (matrix, m, n, argc, argv);
    while (true) {
        menu();
        cin >> choise;
        switch (choise) {
            		case 1: out(matrix, m, n);
            		break;
            		case 2: add(matrix, m, n);
           		break;
		        case 3: mul(matrix, m, n);
			break;
			case 4: tran(matrix, m, n);
			break;
            		case 5: stf(matrix, m, n);
            		break;
	    		case 6: lff(matrix, m, n);
            		break;
	    		case 8: delete[] matrix;		
            		return 0;
	    		default: cout << "Неверная команда" << endl; 	
        }
    }
}
