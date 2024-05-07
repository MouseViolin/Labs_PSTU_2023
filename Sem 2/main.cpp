#include <iostream>
#include <queue> // очередь
#include <stack> // стек
using namespace std;

int nodes[7]{}; // вершины графа
int d[7]; // минимальное расстояние
int v[7]; // посещенные вершины
int ver[7];

int arr[7][7] = {{ 0, 1, 1, 0, 0, 0, 1 },
                 { 1, 0, 1, 1, 0, 0, 0 },
                 { 1, 1, 0, 0, 0, 0, 0 },
                 { 0, 1, 0, 0, 1, 0, 0 },
                 { 0, 0, 0, 1, 0, 1, 0 },
                 { 0, 0, 0, 0, 1, 0, 1 },
                 { 1, 0, 0, 0, 0, 1, 0 }};




struct Edge {
    int begin;
    int end;
};

queue<int> Queue;
stack<int> Stack;

stack<Edge> Edges;


  

void nullArr(){
    for (int i = 0; i < 7; i++) // исходно все вершины равны 0
        nodes[i] = 0;
}

void setArr(int SIZE){
    int temp;
    for (int i = 0; i<SIZE; i++)
      {
        arr[i][i] = 0;
        for (int j = i + 1; j<SIZE; j++) {
          printf("Введите расстояние %d - %d: ", i + 1, j + 1);
          scanf("%d", &temp);
          arr[i][j] = temp;
          arr[j][i] = temp;
        }
      }
}

void initVandD(int SIZE){
    for (int i = 0; i<SIZE; i++)
      {
        d[i] = 10000;
        v[i] = 1;
      }
}


void deist(int SIZE){
    int temp,minindex, min;
    int beginIndex = 0;
    d[beginIndex] = 0;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        { // Если вершину ещё не обошли и вес меньше min
          if ((v[i] == 1) && (d[i]<min))
          { // Переприсваиваем значения
            min = d[i];
            minindex = i;
          }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
          for (int i = 0; i<SIZE; i++)
          {
            if (arr[minindex][i] > 0)
            {
              temp = min + arr[minindex][i];
              if (temp < d[i])
              {
                d[i] = temp;
              }
            }
          }
          v[minindex] = 0;
        }
      } while (minindex < 10000);
    
    int end = 6; // индекс конечной вершины = 7 - 1
      ver[0] = end + 1; // начальный элемент - конечная вершина
      int k = 1; // индекс предыдущей вершины
      int weight = d[end]; // вес конечной вершины

    while (end != beginIndex) // пока не дошли до начальной вершины
      {
        for (int i = 0; i<SIZE; i++) // просматриваем все вершины
          if (arr[i][end] != 0)   // если связь есть
          {
            int temp = weight - arr[i][end]; // определяем вес пути из предыдущей вершины
            if (temp == d[i]) // если вес совпал с рассчитанным
            {                 // значит из этой вершины и был переход
              weight = temp; // сохраняем новый вес
              end = i;       // сохраняем предыдущую вершину
              ver[k] = i + 1; // и записываем ее в массив
              k++;
            }
          }
      }
}


void searchInWidth(int req){
    Edge e;
    Queue.push(0); // помещаем в очередь первую вершину
    while (!Queue.empty())
    {
        int node = Queue.front(); // извлекаем вершину
        Queue.pop();
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 0; j < 7; j++)
        {
            if (arr[node][j] != 0 && nodes[j] == 0)
            { // если вершина смежная и не обнаружена
                Queue.push(j); // добавляем ее в очередь
                nodes[j] = 1; // отмечаем вершину как обнаруженную
                e.begin = node; e.end = j;
                Edges.push(e);
                if (node == req) break;
            }
        }
        cout << node + 1 << endl; // выводим номер вершины
    }
    nullArr();
}

void searchInDepth(int req){
    Edge e;
    Stack.push(0); // помещаем в очередь первую вершину
    while (!Stack.empty())
    { // пока стек не пуст
        int node = Stack.top(); // извлекаем вершину
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 6; j >= 0; j--)
        { // проверяем для нее все смежные вершины
            if (arr[node][j] != 0 && nodes[j] != 2)
            { // если вершина смежная и не обнаружена
                Stack.push(j); // добавляем ее в cтек
                nodes[j] = 1; // отмечаем вершину как обнаруженную
                e.begin = node; e.end = j;
                Edges.push(e);
                if (node == req) break;
            }
        }
        cout << node + 1 << endl; // выводим номер вершины
    }
    nullArr();
}
void showArr(int SIZE){
    for (int i = 0; i<SIZE; i++)
    {
      for (int j = 0; j<SIZE; j++)
        printf("%i ", arr[i][j]);
      printf("\n");
    }
}

void show(int req){
    Edge e;
    cout << "Путь до вершины " << req + 1 << endl;
    cout << req + 1;
    while (!Edges.empty()) {
        e = Edges.top();
        Edges.pop();
        if (e.end == req) {
            req = e.begin;
            cout << " <- " << req + 1;
        }
    }
}

int main()
{
    
    
    int SIZE = 7;
    
    
    int req;
    cout << "N = "; cin >> req; req--;
    
    setArr(SIZE);
    showArr(SIZE);
    
    initVandD(SIZE);
    
    
    
    nullArr();
    
    searchInWidth(req);

    show(req);
    
    searchInDepth(req);
    show(req);
    
    return 0;
}
