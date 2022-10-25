
/*
* Задача 2. Сортируем адреса
В этом задании вы будете читать из файла адреса и выводить их в другой файл в другом формате, 
отсортированными по названию города.
Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. 
После числа N располагаются N блоков по 4 строки в каждом. Каждый блок состоит из следующих строк:
название города, название улицы, номер дома, номер квартиры.
Задача программы заключается в том, чтобы считать адреса из файла in.txt, 
отсортировать их по названию города и вывести отсортированный список адресов 
в файл out.txt в другом формате. Не забудьте вывести количество адресов в начале.
Города должны быть отсортированы в алфавитном порядке.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.
*/

#include <iostream>
#include <fstream>
#include <string>

class addres
{
public:
    std::string city;
    std::string street;
    int house_num;
    int apart_num;
    std::string get_output_address();

private:
};

std::string addres::get_output_address()
{
    std::string data_addres = city + ", " + street + ", " +
        std::to_string(house_num) + ", " + std::to_string(apart_num);
    return data_addres;
}

void sort(addres* addresses, int size)
{
    for (int startIndex = 0; startIndex < size - 1; ++startIndex)
    {
        int smallIndex = startIndex;
        for (int curInd = startIndex + 1; curInd < size; ++curInd)
        {
            if (addresses[curInd].city < addresses[smallIndex].city)
            {
                smallIndex = curInd;
            }
        }
        std::swap(addresses[startIndex], addresses[smallIndex]);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream fin("in.txt");
    if (fin.is_open())
    {
        int size;
        fin >> size;
        addres* arr = new addres[size];

        for (int i = 0; i < size; i++)
        {
            fin >> arr[i].city;
            fin >> arr[i].street;
            fin >> arr[i].house_num;
            fin >> arr[i].apart_num;
        }
        fin.close();

        std::ofstream fout("out.txt");
        fout << size << std::endl;

          sort(arr, size);

        for (int k = 0; k < size; k++)
        {
            fout << arr[k].get_output_address() << std::endl;
        }
        fout.close();
        delete[] arr;
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }

    return 0;
}