#include <iostream>
#include <fstream>





using namespace std;

int main()
{
    char path[50];
    cin >> path; cout << endl;
    ifstream fin; 
    const int n = 13;
    int array[n];
    float med; // медиана
    int max; // максимальное значение
    int min; // минимальное значение
    float average = 0.0; // среднее значение
    float percentile; // Перцентиль
    int e; // индекс перцентиля 90
    fin.open(path);
    if(!fin.is_open())
    {
        cout << "File is not open";
    }
    else
 {
   //Считывание чисел из файла
   for (int i = 0; i < n; ++i)
    {
            fin >> array[i];
    }



   //Сортировка массива
   for(int i = 0; i < n - 1; ++i)
       for(int j = i + 1; j < n; ++j)
           if(array[i] > array[j])
           {
               int temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }

   //Поиск максимального значения
   max = array[0];
   for(int i = 1; i < n; ++i)
       if(max < array[i])
           max = array[i];

   //Персентиль 90
   e = (90*n)/100;
   percentile = array[e];




   //поиск минимального значения
   min = array[0];
   for(int i = 1; i < n; i++)
   {
       if(min > array[i])
       {
           min = array[i];
       }
   }


   
   //Среднее значение
   for(int i = 0; i < n; i++)
   {
       average += array[i];
   }

average = average/n;
   





   //Для поиска медианы
   if(n%2 == 0)
       med = (array[n/2] + array[n/2 - 1])/2;
   else
       med = array[n%2 + n/2];

cout << "average" << " " << '<' << average << '>' << endl;
cout << "perecentil" << ' ' << '<' << percentile << '>' << endl;
cout << "meredian" << " " << '<' << med << '>' << endl;
cout << "maximum" << " " << '<' << max << '>' << endl;
cout << "minimum" << ' ' <<'<' << min << '>' << endl;
    }
    fin.close();
    return 0;
}
