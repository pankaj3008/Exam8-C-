#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Dynamic_Memory_Allocation{
    public:
    Node* head;

    Dynamic_Memory_Allocation(){
        head = nullptr;
    }

    void Insert_At_Beginning(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void Search(int key){
        Node* temp = head;
        int ind = 0;
        while(temp != nullptr){
            if(temp -> data == key){
                cout << "Element found at index " << ind << endl;
                return;
            }
            temp = temp -> next;
            ind++;
        }
        cout << "Element not found" << endl;
    }
    
    void Delete_node(int key){
        Node* temp = head;
        Node* prev = nullptr;
        if(head == nullptr){
            cout << "List is empty" << endl;
            return;
        }

        if(head -> data == key){
            head = head -> next;
            delete temp;
            cout<<"Node with value "<<key<<" deleted from the list."<<endl;
            return;
        }
        
        while(temp != nullptr && temp -> data != key){
            prev = temp;
            temp = temp -> next;
        }
        if(temp == nullptr){
            cout << "Element not found." << endl ;
            return;
        }
        prev -> next = temp -> next;
        delete temp;
        cout<<"Node with value "<<key<<" deleted from the list."<<endl;
    }
    void Reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while(current != nullptr){
            next = current -> next;
            current -> next = prev;
            prev = current ;
            current = next;
        }
        head = prev;
        cout<<"Linked list is reversed."<<endl;


    }
    void Show_list(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp -> data <<" -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl ;
    }
};
int main(){
    Dynamic_Memory_Allocation list;
    int choice , val;
    do{
        cout<<"====================================="<<endl;
        cout<<"|     DYNAMIC MEMORY ALLOCATION     |"<<endl;
        cout<<"====================================="<<endl;
        cout<<"|   1. Insert at the beginning      |"<<endl;
        cout<<"|   2. Search Element               |"<<endl;
        cout<<"|   3. Delete Node                  |"<<endl;
        cout<<"|   4. Reverse Linked List          |"<<endl;
        cout<<"|   5. Display Linked List          |"<<endl;
        cout<<"|   6. Exit                         |"<<endl;
        cout<<"====================================="<<endl;

        cout <<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter the value to be inserted: ";
            cin>>val;
            list.Insert_At_Beginning(val);
            break;
    
            case 2:
            cout<<"Enter the value to be searched: ";
            cin>>val;
            list.Search(val);
            break;
    
            case 3:
            cout<<"Enter the value to be deleted: ";
            cin>>val;
            list.Delete_node(val);
            break;
    
            case 4:
            list.Reverse();
            break;
    
            case 5:
            list.Show_list();
            break;
    
            case 6:
            cout<<"Exiting program..."<<endl;
            break;
    
            default:
            cout<<"Invalid choice. Please choose a valid option."<<endl;
    
            }
            }
    while(choice != 6);
    return 0;
}