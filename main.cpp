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
 ���� String ---- ���� � C++

 mutable --- ���� ���� ���� �onst � ��� ������ ���� ���, �� ����������� � ��� � mutable int arr..... ��� ���� ���� ���� ����������� ���� ����� arr

 _getch() - this is  getchar();
 cin.get() - �� ���� �� getchar;
 cin.getline() - ��������� gets;
 cin.clear(); -  ��������������� �����, ���� ������ ����� ���� �������, �������� ����� (�������� ��������� �����, � ��� �����);
 cin.sync() - ������� �����;

 cout.precision(number);�- ������ ���������� ������ ����� ���������� �����;
 cout.setf() - ��������� ������ �� ����� variables;
 system("cls") - �lean screan;

 template <typename T1,typename T2>   ������� ������� ������� ----- 'C++'
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
  --------  ������������ �������  ------- 1) public: 2)private: 3) protected:  ---------- �� ������������ ����� private
 ������ֲ� - �� ���� ����� �������Ͳ � ����ֲ������ �� � ��� � ��� ������� �����
 �������ֲ� - �� ���� ���� �������� � ����ֲ��Ӫ ����� ����� ����

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

 ������������ ���������� �� ������� ������������ :, ���� ������� ( public) � ��� ���� �����������
class windows : public house;

�������� ������ �����
���� ���� void virtual Shoot()
{
}
������ void Shoot() override
{

}

 ����������� ( ����� ����������) ����   ----- ����� ���������� ����������� ������ ����� �  = 0
class Weapon
{
public:
	virtual void Shoot() = 0;
private:
};



 ����� � ����!!!

 fstream, 
 ifstream -------- READING THE FILE 
 ofstream ------ WRITING THE FILE



 ������� �������� ����

 namespace blabla
 {
 }


 /////////// STL ////////////
 vector				.insert(�������� �������)			.erase(������� ���������� �������)
  .size (����� �������)           push_back.(�������� ��� � �����)    pop_back.(������� ������� �������)     .empty(�� ���� ���, true or false)
  .at.��������� [] ��� � ��������      .clear (������� �� ���)    .capacity ( ���������)       .reserve ��� resize(������������ capacity)    .shrink_to_fit( ���������� capacity �� ���������� ������)

vector<int> myVector(size or nothing); //��������� ����� ������;
vector<int>::iterator it = myVector.begin();
list<int> List;   //����������� ������ ������;
array<int,5(size)> Arr;  //������� ����� (��������� ����� �����)
set<int> Set;    //������ ������ ( �� ���� ��������� �����, ��� ����������� �������������)
multiset<int>    // ���� set � ������������
deque<int> dq;        //���� �� �������� � �������
map<int,string> st;           //���������� set, ��� �� ����� �������� ������ //��� ���� ( ���� + �����) ///pair<int,string> name(1,"iphone")///  �������� ����� emplace. () or insert(make_pair(1,"iphone"));
queue<int>    ������ ����� ������ ������, ������� ������	

///// THREAD ///////////// 

thread th;

recursive_mutex rm                  ��� ����� mutex ��� ��� ����������� �������
mutex mtx;								�� �� ������ ������ ������ �� ����� ����, ���� �� �������� ����� �������
mtx.lock() / mtx.unlock();


th.detach()  - ������� ����,����� �� ����� ��������
th.join() - �������� �����, ���� ��� ������� ���� �������� ������ � ��� ������

�������� �� ������ ��������� ������� ===== thread th(print,std::ref(int a);

��� ��������� ��������� � ������, ����� ������ ����� ������ �������(�������)
int result;
thread th([&result](){result = Sum(5,1)});

//////////////// ������� ����� �������� ����� ��������� ��� ����� std::function///////////////////

void (*ref)(int c, int e)   or      std::function<void(int,int)> funk = Sum

find_if(begin(),end(),��������)

sort(begin(),end(),��������)

copy_if(begin(),end(),back_inserter(����),��������)

remove_if(begin,end,predicat)

max_element / min_element (begin,end)

accumulate (#include <numeric>) (begin(),end(), 0) ------- ���� ����,��������� �� ��������

equal (begin(1),end(1),begin(2),end(2),(precidacat)) ------- ������� 
mismatch (begin(1),end(1),begin(2),end(2)) ------- ������� � ����� �� �, �� �� ����������

for_each

unique(begin,end)                �� ������� ������� ������� � ����� ������, � ������� �������� �� ��� �����
unique_copy(begin,end,back_inserter()           ����� ��� ���������.    ( 1,2,2,3) -> (1,2,3)

random_shuffle(begin,end)



.......SMART POINTERS.........���������,���� � ����������� ������� ���, �� ��� ��������� delete.

auto_ptr<type> name();				auto ptr<int> name(new int(5));        ���� 1 ����� ��������� ���� ��������� �� ����, ��� ���������� ������ ���������, ������ ����������

shared_ptr<type> name();                                                   �� ���� �� � ������� ���������, ��� � ������� ����������� ������� �������� ���.


*/