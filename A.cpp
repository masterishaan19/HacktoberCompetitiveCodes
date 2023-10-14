#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtBeggining(int value)
    {
        Node *temp = new Node(value);
        temp->next = head;
        head = temp;
    }
    void display()
    {
        Node *current = head;
        cout << endl
             << "List is :" << endl;
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
    void addAtEnd(int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void addAfterSpecificValue(int existingValue, int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *current = head;
        while (current != NULL && current->data != existingValue)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << endl
                 << "Node not found" << endl;
        }
        else
        {
            temp->next = current->next;
            current->next = temp;
        }
    }

    void addBefore(int nextValue, int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *current = head;
        while (current->next != NULL && current->next->data != nextValue)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Node not found" << endl;
        }
        else
        {
            temp->next = current->next;
            current->next = temp;
        }
    }

    void deleteStart()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << endl
                 << "there is nothing to delete" << endl;
        }
        else
        {
            head = head->next;
            delete temp;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << endl
                 << "there is nothing to delete" << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *current = head;
            while (current->next->next != NULL)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void deleteSpecific(int value)
    {
        if (head == NULL)
        {
            cout << endl
                 << "there is nothing to delete" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            Node *pre = head;

            while (temp != NULL && temp->data != value)
            {
                pre = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                return;
            }
            if (temp == head)
            {
                head = head->next;
            }
            else if (temp->next == NULL)
            {
                pre->next = NULL;
            }
            else
            {
                pre->next = temp->next;
            }
            delete temp;
        }
    }

    void deleteSpecificPosition(int position){
        if(head == NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        if(position < 0){
            cout<<endl<<"deletion cant be done"<<endl;
            return;
        }else if(position == 0){
            deleteStart();
        }else{
            Node * current = head;
            int currentPosition = 0;

            while(current != NULL && currentPosition<position-1){
                current = current->next;
                currentPosition++;
            }
            if(current == NULL || current->next == NULL){
                cout<<endl<<"deletion isnt possible"<<endl;
                return;
            }else{
                Node * temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    };

    int main()
    {
        LinkedList L;
        int choice;
        while (1)
        {
            cout << endl
                 << "\nEnter the choice\n1.add at beggining\n2.print\n3.add at end\n4.add after\n5.add before\n6.delete start\n7.delete end\n8.delete specific\n9.delete specific posi\n" << endl;
            cin >> choice;
            int value;
            switch (choice)
            {
            case 1:
                cout << endl
                     << "Enter the valur your want to add" << endl;
                cin >> value;
                L.insertAtBeggining(value);
                break;

            case 2:
                L.display();
                break;

            case 3:
                cout << endl
                     << "Enter the value your want to add" << endl;
                cin >> value;
                L.addAtEnd(value);
                break;

            case 4:
                int existingValue;
                cout << "Enter the existing value and the new value" << endl;
                cin >> existingValue >> value;
                L.addAfterSpecificValue(existingValue, value);
                break;

            case 5:
                int nextValue;
                cout << "Enter the existing value and the new value" << endl;
                cin >> nextValue >> value;
                L.addBefore(nextValue, value);
                break;

            case 6:
                L.deleteStart();
                break;

            case 7:
                L.deleteEnd();
                break;

            case 8:
                cout << endl
                     << "Enter the value your want to delete" << endl;
                cin >> value;
                L.deleteSpecific(value);
                break;

            case 9:
                cout << endl
                     << "Enter the position your want to delete" << endl;
                cin >> value;
                L.deleteSpecificPosition(value);
                break;
            default:
                exit(0);
                break;
            }
        }
        return 0;
    }