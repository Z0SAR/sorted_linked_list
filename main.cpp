#include <bits/stdc++.h>
using namespace std;

class node {
public :
    int data ;
    node * next ;
     explicit node (const int val) {
        data = val;
        next = nullptr ;
    }
};
class sorted_linked_list {
private:
    int length =0;
    node *  first ;
public:
    sorted_linked_list() {
        first = nullptr;
    }
     void insert( int val) {
        node * newnode = new node (val);
        if(first==nullptr ) {
           first = newnode ;
        }
        else if (first->data>val) {
            newnode ->next =first ;
            first = newnode ;
        }else {
            node * temp = first ;
            while (temp->next!= nullptr && temp->next->data<val) {
                temp =temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        length ++;
    }
    void remove(int index ) {
        if (index >=length||index <0 ) {
            return ;
        }
        if(index == 0) {
            node * temp = first ;
            first =first ->next;
            delete temp;
            length--;
            return ;
        }
        else{
            node * prev = nullptr;
            node * curr = first;
            int count =0;
            while (curr != nullptr && count <index) {
                prev = curr;
                curr =curr ->next;
                count++;
            }
            if(curr != nullptr) {
                prev ->next = curr->next;
            delete curr;
            }
            length--;
            return ;
        }

    }
    int size() const {
        return length;
    }
   friend ostream & operator<< (ostream & out ,const sorted_linked_list & list){
        if (   list.length == 0) {
            out <<"[]";
            return out ;
        }
        else {
            node* temp = list.first;
            out <<" [ ";
            while (temp != nullptr) {
                out<< temp ->data;
                if(temp->next!=nullptr)
                    out <<", ";
                else out<<" ]"<<endl;
                temp = temp->next;
            }
            return out ;
        }
        }
    int operator[](int index) {
        if(index >= length||index<0) {
            throw out_of_range("Index out of range ");
        }
            node * temp =first;
            for(int i=0;i<index ;i++) {
                temp = temp->next;
            }
            return temp-> data;
        }
    ~sorted_linked_list() {
        node * current =first;
        while (current!= nullptr) {
            node * next = current ->next;
            delete current;
            current =next;
        }
    }
};
int main() {
        cout << "===== Test Case 1: Insert in Random Order =====" << endl;
    sorted_linked_list list1;
    list1.insert(5);
    list1.insert(3);
    list1.insert(7);
    list1.insert(1);
    list1.insert(9);
    cout << "Actual: " << list1;
    cout << "Expected: [ 1, 3, 5, 7, 9 ]" << endl << endl;
    cout << "===== Test Case 2: Insert Duplicates =====" << endl;
    sorted_linked_list list2;
    list2.insert(4);
    list2.insert(4);
    list2.insert(4);
    cout << "Actual: " << list2;
    cout << "Expected: [ 4, 4, 4 ]" << endl << endl;

    cout << "===== Test Case 3: Remove from Beginning =====" << endl;
    list2.remove(0);
    cout << "Actual: " << list2;
    cout << "Expected: [ 4, 4 ]" << endl << endl;

    cout << "===== Test Case 4: Remove from End =====" << endl;
    list2.remove(list2.size() - 1);
    cout << "Actual: " << list2;
    cout << "Expected: [ 4 ]" << endl << endl;

    cout << "===== Test Case 5: Remove Out-of-Bounds Index =====" << endl;
    list2.remove(10);
    cout << "Actual: " << list2;
    cout << "Expected: [ 4 ] (unchanged)" << endl << endl;

    cout << "===== Test Case 6: Access Valid Index =====" << endl;
    cout << "Actual: " << list2[0] << endl;
    cout << "Expected: 4" << endl << endl;

    cout << "===== Test Case 7: Access Invalid Index =====" << endl;
    try {
        cout << list2[5] << endl;
    } catch (exception& e) {
        cout << "Actual Exception: " << e.what() << endl;
    }
    cout << "Expected: Exception -> Index out of range" << endl << endl;

    cout << "===== Test Case 8: Remove All Elements =====" << endl;
    sorted_linked_list list3;
    list3.insert(2);
    list3.insert(1);
    list3.insert(3);
    while (list3.size() > 0) {
        list3.remove(0);
        cout << list3;
    }
    cout << "Expected: [] after each removal until list is empty" << endl;
    cout << "\n===== Test Case 9: Insert Negative Numbers =====" << endl;
    sorted_linked_list list4;
    list4.insert(-10);
    list4.insert(5);
    list4.insert(-20);
    list4.insert(0);
    cout << "Actual: " << list4;
    cout << "Expected: [ -20, -10, 0, 5 ]" << endl << endl;

    cout << "===== Test Case 10: Insert One Element and Remove It =====" << endl;
    sorted_linked_list list5;
    list5.insert(99);
    cout << "After insert: " << list5;
    list5.remove(0);
    cout << "After remove: " << list5;
    cout << "Expected: []" << endl << endl;

    cout << "===== Test Case 11: Remove Middle Element =====" << endl;
    sorted_linked_list list6;
    list6.insert(10);
    list6.insert(20);
    list6.insert(30);
    list6.insert(40);
    list6.remove(2);  // Remove 30
    cout << "Actual: " << list6;
    cout << "Expected: [ 10, 20, 40 ]" << endl << endl;

    cout << "===== Test Case 12: Insert Large Numbers =====" << endl;
    sorted_linked_list list7;
    list7.insert(1000000);
    list7.insert(500000);
    list7.insert(999999);
    cout << "Actual: " << list7;
    cout << "Expected: [ 500000, 999999, 1000000 ]" << endl << endl;

    cout << "===== Test Case 13: Access Last Element =====" << endl;
    cout << "Actual: " << list7[list7.size() - 1] << endl;
    cout << "Expected: 1000000" << endl << endl;

    cout << "===== Test Case 14: Insert Then Remove in Reverse =====" << endl;
    sorted_linked_list list8;
    list8.insert(1);
    list8.insert(2);
    list8.insert(3);
    list8.insert(4);
    list8.insert(5);
    list8.remove(4); // remove 5
    list8.remove(3); // remove 4
    list8.remove(2); // remove 3
    list8.remove(1); // remove 2
    list8.remove(0); // remove 1
    cout << "Actual: " << list8;
    cout << "Expected: []" << endl << endl;
    cout << "===== Test Case 15: Insert Same Value in Different Orders =====" << endl;
    sorted_linked_list list9;
    list9.insert(10);
    list9.insert(30);
    list9.insert(20);
    sorted_linked_list list10;
    list10.insert(30);
    list10.insert(10);
    list10.insert(20);
    cout << "List9: " << list9;
    cout << "List10: " << list10;
    cout << "Expected: Both lists = [ 10, 20, 30 ]" << endl;
    sorted_linked_list list;

}

