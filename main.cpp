// #include <bits/stdc++.h>
// using namespace std;
// template<typename t>
// class Linked_list {
// private:
//     int length = 0 ;
//
//     struct node {
//         t  value;
//         node * next ;
//         int index ;
//     };
//     node * first;
// public:
//     Linked_list() {
//
//         first =  nullptr;
//     }
//     void insert(t val) {
//         node * newnode = new node();
//         newnode -> value = val ;
//         if(length == 0) {
//             first = newnode ;
//         }
//         else {
//             node * temp  = first;
//             while (temp->next !=nullptr&& temp->value < val) {
//                 temp =temp->next;
//             }
//             newnode-> next =temp ->next;
//             temp->next = newnode;
//         }
//         newnode ->index = length++;
//     }
//     void display() {
//         node * temp = first;
//         cout <<"[ ";
//         while (temp!=nullptr) {
//             cout << temp->value <<(temp->index<length)?" , ":" ";
//             temp = temp->next;
//         }
//         cout <<" ]"
//     }
//     t & operator [] (int index ) {
//         node * temp = first;
//         while (temp!= nullptr) {
//             if(temp->index==index) {
//                 return temp->value;
//             }
//             temp=temp->next;
//         }
//         throw out_of_range("Index out of range");
//     }
// };
// int main() {
//     Linked_list<int> list;
//     list.insert(10);
//     list.insert(-1);
//     list.insert(30);
//
//     list.display();
//
// }
#include <iostream>
using namespace std;

template <typename T>
class Linked_list {
private:
    struct node {
        T value;
        node* next;
        int index;
    };

    node* head;
    node* last;
    int length;

public:
    Linked_list() {
        head = nullptr;
        last = nullptr;
        length = 0;
    }

    void insert_sorted(T val) {
        node* newnode = new node();
        newnode->value = val;
        newnode->next = nullptr;

        // 1️⃣ حالة القائمة الفارغة
        if (head == nullptr) {
            head = newnode;
            last = newnode;
        }
        // 2️⃣ إدراج في بداية القائمة (القيمة أصغر من `head`)
        else if (head->value >= val) {
            newnode->next = head;
            head = newnode;
        }
        // 3️⃣ إدراج في مكانه الصحيح داخل القائمة
        else {
            node* temp = head;
            while (temp->next != nullptr && temp->next->value < val) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;

            // تحديث `last` إذا كان الإدراج في النهاية
            if (newnode->next == nullptr) {
                last = newnode;
            }
        }

        newnode->index = length++;
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Linked_list<int> list;
    list.insert_sorted(30);
    list.insert_sorted(10);
    list.insert_sorted(20);
    list.insert_sorted(50);
    list.insert_sorted(40);

    list.display();

    return 0;
}
