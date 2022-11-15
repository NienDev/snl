#include "header.h"

LinkedList::LinkedList()
{
  Node *newNode = CreateNode(0);
  pHead = pTail = newNode;
  curN = 1;
}

LinkedList::~LinkedList()
{
  // delete[] pHead;
  // cout << "nien" << endl;
  Node *cur = pHead;
  while (cur)
  {
    // cout << cur->info << endl;
    // cur = cur->pNext;
    Node *tmp = cur;
    cur = cur->pNext;
    delete tmp;
  }
  pHead = pTail = nullptr;
  curN = 0;
  cout << "XOA" << endl;
}

Node *LinkedList::CreateNode(const int &n)
{
  Node *p = new Node{n, nullptr};
  return p;
}

Node *LinkedList::AddHead(const int &n)
{
  Node *newNode = CreateNode(n);
  if (pHead == nullptr)
  {
    pHead = pTail = newNode;
    curN = 1;
    return pHead;
  }
  curN++;
  newNode->pNext = pHead;
  pHead = newNode;

  return pHead;
}

Node *LinkedList::AddTail(const int &n)
{
  Node *newNode = CreateNode(n);
  if (pHead == nullptr)
  {
    pHead = pTail = newNode;
    curN = 1;
    return pHead;
  }
  curN++;
  pTail->pNext = newNode;
  pTail = pTail->pNext;
  return pTail;
}

ostream &operator<<(ostream &os, const LinkedList &ll)
{
  Node *pCur = ll.pHead;
  while (pCur)
  {
    os << pCur->info << ',';
    pCur = pCur->pNext;
  }
  return os;
}

int &LinkedList::operator[](const int &i)
{
  int j = i;
  if (j < 0)
    j = 0;
  if (j >= curN)
  {
    j = curN - 1;
  }
  Node *cur = pHead;
  int count = 0;
  while (count < j)
  {
    count++;
    cur = cur->pNext;
  }
  return cur->info; // why do we need to return int & ? in my opinion, int itself will return a value, int & will return a pointer to that value but that value is the current element with specific index in an array so we can easily modify it when we found it.
  // ? what if i exceed the number of nodes we have???
}

Node *LinkedList::RemoveHead()
{
  if (curN == 0)
    return nullptr;
  curN--;
  if (pHead == pTail)
  {
    delete pHead;
    pHead = pTail = nullptr;
    return nullptr;
  }
  Node *tmp = pHead;
  Node *newNode = CreateNode(tmp->info);
  pHead = pHead->pNext;
  delete tmp;
  return newNode;
}

Node *LinkedList::RemoveTail()
{
  if (curN == 0)
    return nullptr;
  curN--;
  if (pHead == pTail)
  {
    delete pHead;
    pHead = pTail = nullptr;
    return nullptr;
  }
  Node *cur = pHead;
  while (cur->pNext != pTail)
  {
    cur = cur->pNext;
  }
  Node *newNode = CreateNode(cur->info);
  delete cur->pNext;
  pTail = cur;
  pTail->pNext = nullptr;
  return newNode;
}

void LinkedList::setpHeadValue(int n)
{
  pHead->info = n;
}

void LinkedList::setCurN(int n)
{
  curN = n;
}

Node *LinkedList::getpHead()
{
  return pHead;
}

Node *LinkedList::getpTail()
{
  return pTail;
}

SoNguyenLon::SoNguyenLon() : LinkedList() {}
// {
// Node *newNode = CreateNode(1);
// setpHead(newNode);
// setpTail(newNode);
// setCurN(1);
// }
SoNguyenLon::~SoNguyenLon() {}
// {
// Node *cur = getpHead();
// while (cur)

// {
//   Node *tmp = cur;
//   cur = cur->pNext;
//   delete tmp;
// }
// }

SoNguyenLon::SoNguyenLon(int n)
{
  setpHead(nullptr);
  setpTail(nullptr);
  setCurN(0);
  bool ok = (n > 0) ? false : true;
  if (ok)
    n *= -1;
  while (n > 0)
  {
    AddHead(n % 10);
    n /= 10;
  }
  if (ok)
  {
    Node *p = getpHead();
    setpHeadValue(p->info * (-1));
  }
}
ostream &operator<<(ostream &os, SoNguyenLon snl)
{
  Node *pHead = snl.getpHead();
  while (pHead)
  {
    os << pHead->info;
    pHead = pHead->pNext;
  }

  return os;
}

SoNguyenLon::SoNguyenLon(int m, int n)
{
  setpHead(nullptr);
  setpTail(nullptr);
  setCurN(0);
  while (n > 0)
  {
    AddHead(m);
    n--;
  }
}

int LinkedList::getCurN()
{
  return curN;
}

bool operator>(SoNguyenLon a, SoNguyenLon b)
{
  int n = a.getCurN();
  int m = b.getCurN();
  if (n > m)
    return true;
  else if (n < m)
    return false;

  Node *p1 = a.getpHead();
  Node *p2 = b.getpHead();
  while (p1 && p2)
  {
    int digit1 = p1->info;
    int digit2 = p2->info;
    if (digit1 > digit2)
      return true;
    else if (digit2 > digit1)
      return false;
    p1 = p1->pNext;
    p2 = p2->pNext;
  }
  return true;
}

SoNguyenLon operator-(SoNguyenLon a, SoNguyenLon b)
{
  SoNguyenLon reverseA(0, 0);
  SoNguyenLon reverseB(0, 0);
  Node *cur = a.getpHead();
  while (cur)
  {

    reverseA.AddHead(cur->info);
    cur = cur->pNext;
  }
  cur = b.getpHead();
  while (cur)
  {
    reverseB.AddHead(cur->info);
    cur = cur->pNext;
  }
  while (reverseA.getCurN() < reverseB.getCurN())
  {
    reverseA.AddTail(0);
  }
  while (reverseB.getCurN() < reverseA.getCurN())
  {
    reverseB.AddTail(0);
  }
  Node *first = reverseA.getpHead();
  Node *second = reverseB.getpHead();
  SoNguyenLon res(0, 0);
  int borrow = 0;
  for (int i = 0; i < reverseA.getCurN(); i++)
  {
    int digit1 = first->info;
    int digit2 = second->info;
    int n = digit1 - digit2 - borrow;
    if (n >= 0)
    {
      res.AddHead(n);
      borrow = 0;
    }
    else
    {
      res.AddHead(n + 10);
      borrow = 1;
    }
    first = first->pNext;
    second = second->pNext;
  }
  while (res.getpHead()->info == 0)
  {
    res.RemoveHead();
  }
  if (!(a > b))
  {
    SoNguyenLon res1(0, 0);
    res1 = res1 + 1;
    int tmp = 1;
    for (int i = 0; i < b.getCurN(); i++)
    {
      tmp *= 10;
    }
    res1 = res1 * tmp;
    res1 = res1 - res;
    res1.setpHeadValue(res1.getpHead()->info * (-1));
    return res1;
  }
  return res;
}

SoNguyenLon operator+(SoNguyenLon a, SoNguyenLon b)
{
  SoNguyenLon reverseA(0, 0);
  SoNguyenLon reverseB(0, 0);

  Node *cur = a.getpHead();
  while (cur)
  {
    reverseA.AddHead(cur->info);
    cur = cur->pNext;
  }
  cur = b.getpHead();
  while (cur)
  {
    reverseB.AddHead(cur->info);
    cur = cur->pNext;
  }
  while (reverseA.getCurN() < reverseB.getCurN())
  {
    reverseA.AddTail(0);
  }
  while (reverseB.getCurN() < reverseA.getCurN())
  {
    reverseB.AddTail(0);
  }
  Node *first = reverseA.getpHead();
  Node *second = reverseB.getpHead();
  SoNguyenLon res(0, 0);
  int borrow = 0;

  for (int i = 0; i < reverseA.getCurN(); i++)
  {
    int digit1 = first->info;
    int digit2 = second->info;
    int n = digit1 + digit2 + borrow;
    if (n >= 10)
    {
      res.AddHead(n % 10);
      borrow = n / 10;
    }
    else
    {
      res.AddHead(n);
      borrow = 0;
    }

    first = first->pNext;
    second = second->pNext;
  }
  if (borrow > 0)
  {
    res.AddHead(borrow);
  }

  return res;
}
void LinkedList::setpTail(Node *pTail)
{
  this->pTail = pTail;
}
void LinkedList::setpHead(Node *pHead)
{
  this->pHead = pHead;
}
const SoNguyenLon &SoNguyenLon::operator=(SoNguyenLon a)
{
  if (this == &a)
    return *this;
  this->setpHead(a.getpHead());
  this->setpTail(a.getpTail());
  this->setCurN(a.getCurN());
  return *this;
}
SoNguyenLon operator-(SoNguyenLon a, const int &n)
{
  SoNguyenLon b(n);
  return a - b;
}
SoNguyenLon operator+(SoNguyenLon a, const int &n)
{
  SoNguyenLon b(n);
  return a + b;
}

SoNguyenLon operator*(SoNguyenLon a, SoNguyenLon b)
{
  SoNguyenLon reverseA(0, 0);
  SoNguyenLon reverseB(0, 0);
  Node *cur = a.getpHead();
  while (cur)
  {
    reverseA.AddHead(cur->info);
    cur = cur->pNext;
  }
  cur = b.getpHead();
  while (cur)
  {
    reverseB.AddHead(cur->info);
    cur = cur->pNext;
  }
  while (reverseA.getCurN() < reverseB.getCurN())
  {
    reverseA.AddTail(0);
  }
  while (reverseB.getCurN() < reverseA.getCurN())
  {
    reverseB.AddTail(0);
  }

  Node *first = reverseA.getpHead();
  Node *second = reverseB.getpHead();
  SoNguyenLon res(0, 0);

  int unit = 0;
  while (first)
  {

    int carry = 0;
    int digit1 = first->info;
    Node *second_p = second;
    SoNguyenLon tmp(0, 0);
    while (second_p)
    {
      int digit2 = second_p->info;
      int n = digit1 * digit2 + carry;

      if (n >= 10)
      {
        tmp.AddHead(n % 10);
        carry = n / 10;
      }
      else
      {
        tmp.AddHead(n);
        carry = 0;
      }
      second_p = second_p->pNext;
    }
    if (carry != 0)
    {
      tmp.AddHead(carry);
    }
    for (int i = 0; i < unit; i++)
    {
      tmp.AddTail(0);
    }
    unit++;
    res = res + tmp;
    // cout << res << endl;
    first = first->pNext;
  }

  while (res.getpHead()->info == 0)
  {
    res.RemoveHead();
  }
  return res;
}
int main()
{
  SoNguyenLon snl1;
  // SoNguyenLon snl2(44667733);
  // SoNguyenLon snl3(5, 9);
  // SoNguyenLon snl4(7, 30);
  // SoNguyenLon snl5 = snl3 - snl2;
  // SoNguyenLon snl6 = 1098765432 - snl2;
  // SoNguyenLon snl7 = snl4 - snl3 + 123456789;
  // SoNguyenLon snl8 = snl2 * snl3;
  cout << snl1 << endl;
  //      << snl2 << endl
  //      << snl3 << endl;
  // cout << snl4 << endl;
  // cout << snl5 << endl
  //      << snl6 << endl;
  // cout << snl7 << endl
  //      << snl8 << endl;
}
