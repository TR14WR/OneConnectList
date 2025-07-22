#include <iostream>
#include "List.h"


int main() {
  setlocale(0, "");
  srand(time(0));

  ForwardList<int> intlist;
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);

  intlist.printNode();

  intlist.remove(4);
  intlist.printNode();
  /*cout << "--------------------------------------------------------------------" << endl;
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.printNode();
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;

  cout << "--------------------------------------------------------------------" << endl;

  int data, number;
  cout << "Введите число и номер, после которого хотите создать узел: ";
  cin >> data >> number;
  cout << "--------------------------------------------------------------------" << endl;

  if (!intlist.insert(data, number - 1))
    cout << "Вставка не удалась\n";
  intlist.printNode();
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;
  cout << "--------------------------------------------------------------------" << endl;
  intlist.pushBack(100);
  intlist.printNode();
  cout << "--------------------------------------------------------------------" << endl;

  int deletenum;
  cout << "Введите номер, который хотите удалить: ";
  cin >> deletenum;
  cout << "--------------------------------------------------------------------" << endl;

  if (!intlist.remove(deletenum - 1))
    cout << "Удаление не удалось\n";
  intlist.printNode();
  cout << "Последний узел:\t" << intlist.GetEnd() << endl;
  cout << "--------------------------------------------------------------------" << endl;
   intlist.printNode();

  cout << "--------------------------------------------------------------------" << endl;
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);
  intlist.pushBack(rand() % 10);


  intlist.printNode();
  cout << intlist[2];*/

  for (auto var : intlist)
  {
    cout << var << endl;
  }


  intlist.clear();



  return 0;
}
