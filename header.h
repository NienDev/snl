#include <iostream>
using namespace std;

struct Node
{
  int info;
  Node *pNext;
};
class LinkedList
{
private:
  Node *pHead, *pTail;
  int curN;

public:
  LinkedList(void);
  ~LinkedList(void);
  void setCurN(int n);
  void setpTail(Node *pTail);
  void setpHead(Node *pHead);
  int getCurN() const;
  Node *getpHead()const;
  Node *getpTail()const;
  void setpHeadValue(int n);
  static Node *CreateNode(const int &n); // use static here because all of the Linked List objects have the same createNode methods so it is not reasonable if we create each class has its own createNode method
  Node *AddHead(const int &n);
  Node *AddTail(const int &n);
  Node *RemoveHead();
  Node *RemoveTail();
  friend ostream &operator<<(ostream &os, const LinkedList &ll);
  int &operator[](const int &i);
};

class SoNguyenLon : public LinkedList
{
private:
public:
  SoNguyenLon();
  ~SoNguyenLon();
  SoNguyenLon(int n);
  SoNguyenLon(int m, int n);
  SoNguyenLon(const SoNguyenLon&a);
  friend ostream &operator<<(ostream &os, SoNguyenLon& snl);
  friend SoNguyenLon operator-(const SoNguyenLon& a, const SoNguyenLon& b) ;
  friend SoNguyenLon operator+(SoNguyenLon a, SoNguyenLon b) ;
  SoNguyenLon operator=(const SoNguyenLon& a);
  friend SoNguyenLon operator-(SoNguyenLon a, const int &n);
  friend SoNguyenLon operator+(SoNguyenLon a, const int &n);
  friend SoNguyenLon operator*(SoNguyenLon a, SoNguyenLon b);
  friend bool operator>(SoNguyenLon a, SoNguyenLon b);
};
