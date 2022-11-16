#include <iostream>
using namespace std;
struct Node
{
  long long int info;
  Node *pNext;
};
class LinkedList
{
private:
  Node *pHead, *pTail;
  long long int curN;

public:
  LinkedList(void);
  ~LinkedList(void);
  void setCurN(long long int n);
  void setpTail(Node *pTail);
  void setpHead(Node *pHead);
  long long int getCurN() const;
  Node *getpHead()const;
  Node *getpTail()const;
  void setpHeadValue(long long int n);
  static Node *CreateNode(const long long int &n); // use static here because all of the Linked List objects have the same createNode methods so it is not reasonable if we create each class has its own createNode method
  Node *AddHead(const long long int &n);
  Node *AddTail(const long long int &n);
  Node *RemoveHead();
  Node *RemoveTail();
  friend ostream &operator<<(ostream &os, const LinkedList &ll);
  long long int &operator[](const long long int &i);
};

class SoNguyenLon : public LinkedList
{
private:
public:
  SoNguyenLon();
  ~SoNguyenLon();
  SoNguyenLon(long long int n);
  SoNguyenLon(long long int m, long long int n);
  SoNguyenLon(const SoNguyenLon&a);
  friend ostream &operator<<(ostream &os, SoNguyenLon& snl);
  friend SoNguyenLon operator-(const SoNguyenLon& a, const SoNguyenLon& b) ;
  friend SoNguyenLon operator+(const SoNguyenLon& a, const SoNguyenLon& b) ;
  SoNguyenLon operator=(const SoNguyenLon& a);
  
  friend SoNguyenLon operator-(const SoNguyenLon& a, const long long int &n);
  friend SoNguyenLon operator+(const SoNguyenLon& a, const long long int &n);
  friend SoNguyenLon operator*(SoNguyenLon a, SoNguyenLon b);
  friend bool operator>(SoNguyenLon a, SoNguyenLon b);
};
