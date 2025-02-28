#include <iostream>

// Функция для разделения массива на две части относительно опорного элемента
int partition(int* arr, int low, int high) 
{
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; j++) 
    {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot)
        {
            i++; // Увеличиваем индекс меньшего элемента
            std::swap(arr[i], arr[j]); // Меняем местами
        }
    }
    std::swap(arr[i + 1], arr[high]); // Ставим опорный элемент на правильное место
    return i + 1; // Возвращаем индекс опорного элемента
}

// Рекурсивная функция для быстрой сортировки
void quick_sort(int* arr, int low, int high) 
{
    if (low < high) 
    {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после опорного
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Основная функция для быстрой сортировки
void quick_sort(int* arr, int size) 
{
    quick_sort(arr, 0, size - 1);
}

// Функция для вывода массива на экран
void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    // Тестовые массивы
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    // Размеры массивов
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    // Сортировка и вывод результатов
    std::cout << "Исходный массив 1: ";
    print_array(arr1, size1);
    quick_sort(arr1, size1);
    std::cout << "Отсортированный массив 1: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    std::cout << "Исходный массив 2: ";
    print_array(arr2, size2);
    quick_sort(arr2, size2);
    std::cout << "Отсортированный массив 2: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    std::cout << "Исходный массив 3: ";
    print_array(arr3, size3);
    quick_sort(arr3, size3);
    std::cout << "Отсортированный массив 3: ";
    print_array(arr3, size3);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
