#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


/**
 * @brief заполняет статический массив значениями
 * @param a массив из 10 элементов
 */
void fillArray(int(&a)[10])
{
    for(int i{}; i < 10; i++) 
    {
        cin >> a[i];
    }
}


/**
 * @brief выводит статический массив на экран
 * @param a массив из 10 элементов
 */
void printArray(int (&a)[10])
{
    cout << "Massiv = ";

    for (auto x : a)
    {
        cout << x << " ";
    }

    cout << endl;
}


/**
 * @brief меняет местами два элемента массива по индексам
 * @param a массив из 10 элементов
 */
void swapElements(int(&a)[10]) 
{
    int index1{};

    cout << "Vedite index 1 elem = ";
    cin >> index1;

    int index2{};

    cout << "Vedite index 2 elem = ";
    cin >> index2;

    int karman{};

    karman = a[index1];
    a[index1] = a[index2];
    a[index2] = karman;

    cout << endl;
}


/**
 * @brief умножает каждый элемент массива на 2
 * @param a массив из 10 элементов
 */
void multiplyByTwo(int(&a)[10])
{
    cout << "Massiv =";

    for (int& x : a)
    {
        x = x * 2;
        cout << x << " ";
    }
}


/**
 * @brief основная функция первого задания
 * @return код завершения программы
 */
int main()
{
    int masiv[10];

    fillArray(masiv);
    printArray(masiv);
    swapElements(masiv);
    printArray(masiv);
    multiplyByTwo(masiv);

    return 0;
}



/**
 * @brief обрабатывает динамический массив до первого отрицательного элемента
 * @param arr указатель на динамический массив
 * @param size размер массива
 */
void process(int*& arr, int& size)
{
    for (int i{}; i < size; i++)
    {
        if (arr[i] < 0)
        {
            int* arr1 = new int[i]{};

            for (int d{}; d < i; d++)
            {
                arr1[d] = arr[d];
            }

            delete[] arr;
            arr = arr1;

            size = i;

            break;
        }
    }
}


/**
 * @brief выводит динамический массив на экран
 * @param arr указатель на массив
 * @param size размер массива
 */
void printArray(int* arr, int size)
{
    cout << "Massiv = ";

    for (int i{}; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


/**
 * @brief основная функция второго задания
 * @return код завершения программы
 */
int main()
{
    int n;

    cout << "Vedite razmer masiva = ";
    cin >> n;

    int* arr = new int[n]{};

    cout << "Vedite elementi masiva: ";

    for (int i{}; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Do process: ";
    printArray(arr, n);

    process(arr, n);

    cout << "Posle process: ";
    printArray(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;
}


/**
 * @brief структура безопасного динамического массива
 */
struct SafeArray
{
    int* data;  ///< указатель на данные массива
    int size;   ///< размер массива
};


/**
 * @brief создает безопасный динамический массив
 * @param size размер массива
 * @return созданная структура SafeArray
 */
SafeArray createArray(int size)
{
    SafeArray arr;

    arr.size = size;
    arr.data = new int[size]{};

    return arr;
}


/**
 * @brief возвращает элемент массива по индексу
 * @param arr безопасный массив
 * @param index индекс элемента
 * @return ссылка на элемент массива или заглушку
 */
int& getElement(SafeArray& arr, int index)
{
    static int zaglushka = 0;

    if (index < 0 || index >= arr.size)
    {
        cout << "out of range";
        return zaglushka;
    }
    else
    {
        return arr.data[index];
    }
}


/**
 * @brief выводит безопасный массив на экран
 * @param arr массив для вывода
 */
void printSafe(const SafeArray& arr)
{
    for (int i{}; i < arr.size; i++)
    {
        cout << arr.data[i] << " ";
    }

    cout << endl;
}


/**
 * @brief изменяет размер динамического массива
 * @param arr безопасный массив
 * @param M новый размер массива
 */
void reSizeArray(SafeArray& arr, int M)
{
    int N = arr.size;

    cout << "Vvedite noviy razmer: ";
    cin >> M;

    if (M < N)
    {
        for (int i = M; i < N; i++)
        {
            cout << arr.data[i] << " ";
        }

        int* data1 = new int[M]{};

        for (int j{}; j < M; j++)
        {
            data1[j] = arr.data[j];
        }

        delete[] arr.data;
        arr.data = data1;
        arr.size = M;
    }
    else if (M > N)
    {
        int* data1 = new int[M]{};

        for (int j{}; j < N; j++)
        {
            data1[j] = arr.data[j];
        }

        delete[] arr.data;
        arr.data = data1;
        arr.size = M;
    }
    else
    {
        cout << "Razmer ne izmenilsya" << endl;
    }
}


/**
 * @brief основная функция третьего задания
 * @return код завершения программы
 */
int main()
{
    SafeArray myArr = createArray(5);

    getElement(myArr, 2) = 77;

    printSafe(myArr);

    reSizeArray(myArr, 0);

    cout << endl;

    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}


/**
 * @brief выделяет память под двумерный массив
 * @param rows количество строк
 * @param cols количество столбцов
 * @return указатель на созданную матрицу
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i{}; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}


/**
 * @brief заполняет двумерный массив оценками
 * @param matrix двумерный массив
 * @param rows количество строк
 * @param cols количество столбцов
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    cout << "Vvedite ocenki:" << endl;

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}


/**
 * @brief выводит двумерный массив на экран
 * @param matrix двумерный массив
 * @param rows количество строк
 * @param cols количество столбцов
 * @param showBorders вывод рамки
 * @param title заголовок матрицы
 */
void printMatrix(int** matrix, int rows, int cols,
                 bool showBorders = true,
                 string title = "Matrix")
{
    cout << title << endl;

    if (showBorders)
    {
        cout << "************" << endl;
    }

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    if (showBorders)
    {
        cout << "************" << endl;
    }

    cout << endl;
}


/**
 * @brief освобождает память двумерного массива
 * @param matrix двумерный массив
 * @param rows количество строк
 */
void freeMatrix(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}


/**
 * @brief основная функция четвертого задания
 * @return код завершения программы
 */
int main()
{
    int rows;
    int cols;

    cout << "Vvedite kolichestvo studentov: ";
    cin >> rows;

    cout << "Vvedite kolichestvo predmetov: ";
    cin >> cols;

    int** matrix = allocateMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols, true, "Ocenki studentov");

    printMatrix(matrix, rows, cols, false, "Bez ramki");

    freeMatrix(matrix, rows);

    return 0;
}