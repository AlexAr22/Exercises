#include <iostream>
#include <fstream>




using namespace std;

int definesing(int px, int py, int Ax, int Ay, int Bx, int By)
{
  return (px - Ax) * (By - Ay) - (py - Ay) * (Bx - Ax);
}

int main()
{


    char path[50];
    cout << "Enter rhe path: ";
    cin >> path; cout << "\n";
    ifstream fin;
    int x1, x2, x3, x4, y1, y2, y3, y4; // Вершины четырехугольника
    int x, y; // Координаты точки которую будем проверять
    fin.open(path);
    if(!fin.is_open())

        cout << "File is not open";
    else
  {

        fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        int point1 = definesing(x, y, x1, y1, x2, y2);
        int point2 = definesing(x, y, x2, y2, x3, y3);
        int point3 = definesing(x, y, x3, y3, x4, y4);
        int point4 = definesing(x, y, x4, y4, x1, y1);

        if((x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3) || (x == x4 && y == y4))
            cout << "The point is top of a quadrilateral";
        else
          if(point1 < 0 && point2 < 0 && point3 < 0 && point4 < 0) // Так как у нас обход по часовой стрелке, то при отрицательном значении точка будет лежать в четырехугольнике
            cout << "The point belongs to the quadrilateral" << endl;
          else
              if(point1 == 0 || point2 == 0 || point3 == 0 && point4 == 0) // Если значение равно нулю в результате произвидения в функции definesing, то точка будет лежать на одной из прямых
                  cout << "The point belong to the side of quadrilateral";
              else
                  cout << "The point is outside the quadrilateral";



   }

fin.close();

    return 0;
}
