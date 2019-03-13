#include <iostream>
#include <vector>
using namespace std;

struct HourLogData {
   int date;
   int id;
};

struct Node {
   HourLogData data;
   Node *next;
   Node *previous;
};

class LinkedList {
  private:
   Node *front;
   Node *back;
   int size;

  public:
   LinkedList() {
      front = back = nullptr;
      size = 0;
   };

   ~LinkedList() {
      Node *temp;
      while (front != nullptr) {
         temp = front;
         front = front->next;
         delete temp;
      }
   }

   HourLogData pop_back() {
      HourLogData tempData;
      if (back == nullptr) {
         tempData.id = -1;
         return tempData;
      }
      tempData.date = back->data.date;
      tempData.id = back->data.id;

      Node *temp = back;
      back = back->previous;
      back->next = nullptr;
      delete temp;

      return tempData;
   }

   void push_back(int date, int id) {
      Node *temp = new Node;
      temp->data.date = date;
      temp->data.id = id;
      temp->next = nullptr;

      if (front == nullptr) {
         temp->previous = nullptr;
         front = temp;
      } else if (back == nullptr) {
         back = temp;
         front->next = back;
         back->previous = front;

      } else {
         back->next = temp;
         temp->previous = back;
         back = back->next;
      }
   }

   void display() {
      Node *temp = front;
      while (temp != nullptr) {
         cout << "ID: " << temp->data.id << ", DATE: " << temp->data.date << endl;
         temp = temp->next;
      }
   }
};

// class HourLogger {
//   private:
//    struct HourNode {
//       int date;
//       int id;
//    };

//    vector<HourNode> log;

//       // cout << log.at(0) << endl;
//    }
// };

int main() {
   LinkedList chach;
   for (int i = 0; i < 100; i++) {
      chach.push_back(i, i);
   }

   for (int i = 0; i < 100; i++) {
      HourLogData temp = chach.pop_back();
      if (temp.id != -1)
         cout << temp.id << " " << temp.date << endl;
   }
   // chach.display();
   return 0;
};
