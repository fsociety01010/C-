#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <thread>
#include <numeric>
#include <fstream>
#include <mutex>
#include <random>
#include <ctime>
#include <time.h>
#include <exception>

using namespace std;





/*
 type of data
char, short, int, long, float, double, bool ------- in 'C'
 + string									  ------- in 'C++'
 NULL == 0                      ------- 'C', 'C++'
 nullptr == 0 (zero for adress) ---- 'C++'
 клас String ---- лише в C++

 mutable --- коли весь клас сonst а тре змінити якісь дані, то оголошується ті дані з mutable int arr..... тоді весь клас буде константним окрім цього arr

 _getch() - this is  getchar();
 cin.get() - то саме шо getchar;
 cin.getline() - рівноцінно gets;
 cin.clear(); -  восстанавливает поток, если вместо числа были введены, например буквы (пытались прочитать число, а там буквы);
 cin.sync() - очищает буфер;

 cout.precision(number); - задает количество знаков после десятичной точки;
 cout.setf() - параметри виводу на екран variables;
 system("cls") - сlean screan;

 template <typename T1,typename T2>   задання шаблону функції ----- 'C++'
 T1 function(T1 a, T2)

 POINTER -- int *P = &a; ------ 'C' + 'C++'
 REFERENCE -- int &p = a; ----- 'C++'

------MEMORY------
 int *pa = (int) malloc (n * sizeof(int)); --- in  'C'
 int *pa = new int;
 free(pa) ----- in 'C'
 delete pa --- in 'C++'


----RREPROCESSOR----
 #if DEBUG == 2
 cout << "TRUE STORY" << endl;
 #elif DEBUG
 cout << "FALSE" << endl;
 #else
 # cout << "fuck off" << endl;
 #endif
 #ifdef or #ifndef DEBUG


 ----------- CLASS -----------
  class Human{
  --------  модифікатори доступу  ------- 1) public: 2)private: 3) protected:  ---------- по замовчуванню стоїть private
 АГРЕГАЦІЯ - ЦЕ КОЛИ КЛАСИ НЕЗАЛЕЖНІ І ФУНКЦІОНУЮТЬ ЯК З ТАК І БЕЗ ПЕВНОГО КЛАСУ
 КОМПОЗИЦІЯ - ЦЕ КОЛИ КЛАС ЗАЛЕЖНИЙ І ФУНКЦІОНУЄ ЧЕРЕЗ ІНШИЙ КЛАС

    string name;                 
	  string lastname;
	  int age;
 	  int heigt;
	  int weight;
	
	  void show()
	  {
		  cout << age << endl << lastname << " " << name << endl << heigt << endl << weight << endl;
	  }
};

 унаслідування відбувається за рахунок прописування :, типу доступу ( public) і сам клас наслідування
class windows : public house;

віртуальні методи класу
один клас void virtual Shoot()
{
}
підклас void Shoot() override
{

}

 абстрактний ( чисто віртуальний) клас   ----- чисто оголошення ексземпляру методу класу і  = 0
class Weapon
{
public:
	virtual void Shoot() = 0;
private:
};



 ЗАПИС В ФАЙЛ!!!

 fstream, 
 ifstream -------- READING THE FILE 
 ofstream ------ WRITING THE FILE



 Область видимості імен

 namespace blabla
 {
 }


 /////////// STL ////////////
 vector				.insert(добавляє елемент)			.erase(видаляє конкретний елемент)
  .size (розмір вектору)           push_back.(вставляє дані в кінець)    pop_back.(видаляє останній елеметн)     .empty(чи якісь дані, true or false)
  .at.рівноцінно [] але з провіркою      .clear (видаляє всі дані)    .capacity ( вмістимість)       .reserve або resize(встановлення capacity)    .shrink_to_fit( скорочення capacity до актуальних потреб)

vector<int> myVector(size or nothing); //динамічний масив данних;
vector<int>::iterator it = myVector.begin();
list<int> List;   //однозвязний список данних;
array<int,5(size)> Arr;  //простий масив (статичний масив даних)
set<int> Set;    //бінарне дерево ( не існує однакових обєктів, все автоматично відсортировано)
multiset<int>    // копія set з повтореннями
deque<int> dq;        //шось між вектором і списком
map<int,string> st;           //дороблений set, теж на основі бінарного дерева //йде пара ( ключ + слово) ///pair<int,string> name(1,"iphone")///  основний метод emplace. () or insert(make_pair(1,"iphone"));
queue<int>    проста черга перший зайшов, останній вийшов	

///// THREAD ///////////// 

thread th;

recursive_mutex rm                  той самий mutex але для рекурсивних функцій
mutex mtx;								не дає іншому потоку доступ до цього коду, коли він зайнятий іншим потоком
mtx.lock() / mtx.unlock();


th.detach()  - окремий потік,якого не очікує програма
th.join() - програма очікує, поки цей окремий потік закінчить роботу і іде дальше

передачі по ссилці аргумента функції ===== thread th(print,std::ref(int a);

Щоб повернути результат в потоці, треба писати через лямбда функцію(анонімну)
int result;
thread th([&result](){result = Sum(5,1)});

//////////////// Функції можна передати через указатель або через std::function///////////////////

void (*ref)(int c, int e)   or      std::function<void(int,int)> funk = Sum

find_if(begin(),end(),предикат)

sort(begin(),end(),предикат)

copy_if(begin(),end(),back_inserter(куди),предикат)

remove_if(begin,end,predicat)

max_element / min_element (begin,end)

accumulate (#include <numeric>) (begin(),end(), 0) ------- рахує суму,перемножує всі елементи

equal (begin(1),end(1),begin(2),end(2),(precidacat)) ------- порівнює 
mismatch (begin(1),end(1),begin(2),end(2)) ------- порівнює і вказує на ті, які не співпадають

for_each

unique(begin,end)                не унікальні значеня переміщає в кінець масиву, а повертає ітератор на той кінець
unique_copy(begin,end,back_inserter()           копірує без повторень.    ( 1,2,2,3) -> (1,2,3)

random_shuffle(begin,end)



.......SMART POINTERS.........указатель,який і автоматично видаляє дані, не тре викликати delete.

auto_ptr<type> name();				auto ptr<int> name(new int(5));        лише 1 такий указатель може вказувати на обєкт, при передаванні нового указателя, старий затирається

shared_ptr<type> name();                                                   то саме шо і простий указатель, але і видаляє автоматично створені динамічно дані.


*/