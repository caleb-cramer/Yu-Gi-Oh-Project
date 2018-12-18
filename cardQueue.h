#ifndef CARDQUEUE_H
#define CARDQUEUE_H

class DynCardQueue
{
private:
 struct QueueNode
 {
  Card value;
  QueueNode *next;
 }

 QueueNode *front;
 QueueNode *rear;
 int numItems;

public:
 DynCardQueue()
 {
  front = nullptr;
  rear = nullptr;
  numItems = 0;
 }

 ~DynCardQueue()
 {
  clear();
 }

 void enqueue(Card ADcard)
 {
  newNode = new QueueNode;
  newNode->value.name = ADcard.name;
  newNode->value.ATK = ADcard.ATK;
  newNode->value.DEF = ADcard.DEF;
  newNode->next = nullptr;

  if(isEmpty())
  {
   front = newNode;
   rear = newNode;
  }

  else
  {
   rear->next = newNode;
   rear = newNode;
  }

  numItems++;
 }

 void dequeue(Card &ADcard)
 {
  QueueNode *temp = nullptr;

  if(isEmpty())
   cout << "The queue is empty.\n";

  else
  {
   ADcard.name = value.name;
   ADcard.ATK = value.ATK;
   ADcard.DEF = value.DEF;

   temp = front;
   front = front->next;
   delete temp;

   numItems--;
  }
 }

 bool isEmpty() const
 {
  bool status;

  if(numItems > 0)
   status = false;
  else
   status = true;
  return status;
 }

 void clear()
 {
  Card value;

  while(!isEmpty())
   dequeue(value);
 }
};

#endif
