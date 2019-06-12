#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

int main()
{    
    const int filesquanity = 5; // Количество файлов
    const int singsquanityInfile = 16; // Количество замерений в течение дня
    float arraverageorder[singsquanityInfile]; // массив сумм длинн очередей за каждые полчаса

       for (int i = 0; i < singsquanityInfile; ++i)
        {
            arraverageorder[i] = 0.0;
        }

        for (int i = 0; i < filesquanity; ++i)
        {
            char path[50]; cout << "Enter the path file " << i + 1 << ": ";
            cin >> path;
            float countfile[singsquanityInfile]; // в этот массив будут считываться данные из каждого файла
            ifstream fin; // объект для считывания каждого входного файла
            fin.open(path);
            if(!fin.is_open())
            cout << "File is not open";
            else
            {

            for (int k = 0; k < singsquanityInfile; ++k)
            {
                fin >> countfile[k];
                arraverageorder[k] += countfile[k]; //увеличиваем значение в массиве на соответствующее значение из файла
            }

            }

            fin.close();
            cout << endl;
          }

        // Находим максимальный элемент
        float max = arraverageorder[0];
        for(int i = 1; i < singsquanityInfile; ++i)
        {
            if(max < arraverageorder[i])
            max = arraverageorder[i];
        }

        int halfhour = 30;
        vector <int> indexmaxsings; // Ветор, который хранит индексы с наибольшей загруженностью
        for(int i = 0; i < singsquanityInfile; i++)
        {
            if(max == arraverageorder[i])
                indexmaxsings.push_back(i);
        }


        float firstinterval = ((indexmaxsings[0] + 1) * halfhour)/60; // переводим в часы из минут
        firstinterval = firstinterval + 9; // Если магазин открывается в 9 часов
        float lastinterval = ((indexmaxsings[indexmaxsings.size() - 1] + 1) * halfhour)/60;
        lastinterval = lastinterval + 9;

        if(firstinterval*2 == int(firstinterval) * 2)
            cout << firstinterval << ":" << "00" << '-';
        else
            cout << firstinterval << ":" << halfhour << '-';
        if(lastinterval * 2 == int(lastinterval) * 2)
            cout << lastinterval << ":" << "00";
        else
            cout << lastinterval << ":" << halfhour;


    return 0;
}
