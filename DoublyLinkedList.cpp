#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    // 1. Check if Node exists Using Key value
    Node *checkIfNodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. Append a Node to the List
    void appendNode(Node *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node Already exists with Key value : " << n->key << ".\nAppend another Node with different key Value: " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended as Head Node. " << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Appended." << endl;
            }
        }
    }

    // 3. Prepend Node
    void prependNode(Node *n)
    {
        if (checkIfNodeExists(n->key) != NULL)
        {
            cout << "Node Already exists with Key value : " << n->key << ". " << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Preppended as Head Node. " << endl;
            }
            else
            {
                head->previous = n;
                n->next = head;

                head = n;
                cout << "Node Prepended." << endl;
            }
        }
    }

    //  4. Insert a Node after a Particular Node in the List
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exist with key : " << k << endl;
        }
        else
        {
            if (checkIfNodeExists(n->key) != NULL)
            {
                cout << "Node already exist with key : " << n->key << ".\nInsert Node with different key value." << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                // inserting Node at the End.
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node Inserted at the End." << endl;
                }
                // inserting Node in the Between
                else
                {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between." << endl;
                }
            }
        }
    }

    // 5. Delete Node by Unique key. or Un-Link Node
    void deleteNodeByKey(int k)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exist with key : " << k << endl;
        }
        else
        {
            if (head == NULL)
            {
                cout << "Doubly Linked List Already Empty. can't delete." << endl;
            }
            else if (head != NULL)
            {
                if (head->key == k)
                {
                    head = head->next;
                    cout << "Node Unlinked with key value : " << k << endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *previos = ptr->previous;
                    // deleting at the end
                    if (nextNode == NULL)
                    {
                        previos->next = NULL;
                        cout << "Node Deleted at the End." << endl;
                    }
                    // Deleting in Between
                    else
                    {
                        previos->next = nextNode;
                        nextNode->previous = previos;
                        cout << "Node deleted in Between." << endl;
                    }
                }
            }
        }
    }

    // 6. Update node
    void updateNodeNyKey(int k, int d)
    {
        Node *ptr = checkIfNodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Updated Successfully." << endl;
        }
        else
        {
            cout << "Node doesn't exists wiht key value : " << k << endl;
        }
    }

    // 7. Printing DoublyLinkedList items
    void printList()
    {
        if (head == NULL)
        {
            cout << "No any Node in Doubly Linked List." << endl;
        }
        else
        {
            cout << endl
                 << "Doubly Linked List values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " , " << temp->data << " ) <--> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList dl;
    int option;
    int key1, k1, data1;
    do
    {
        cout << endl
             << "What Operation do you want to perform?\nSelect Option number.Enter 0 to exist" << endl;
        cout << "1. Append Node() ." << endl;
        cout << "2. PrePend Node() ." << endl;
        cout << "3. InsertNodeAfter() ." << endl;
        cout << "4. DeleteNodeBykey() ." << endl;
        cout << "5. UpdateNodeByKey() ." << endl;
        cout << "6. Print() ." << endl;
        // cout << "7. Clear Screen ." << endl;
        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
            cout << "Append Node Operation \nEnter key value & Data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            dl.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the node to be Prepended." << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            dl.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node After Operation \nEnter key of existing node after which you want to insert this Node: " << endl;
            cin >> k1;
            cout << "Enter Key and Data of new Node that You are Inserting : " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            dl.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete Node Operation \nEnter key of node that you want to Delete: " << endl;
            cin >> k1;
            dl.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update Node Operation \nEnter key and new Data to be updated:" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            dl.updateNodeNyKey(key1, data1);
            break;
        case 6:
            dl.printList();
            break;
        //  case 7:
        //      system("cls");
        //      break;
        default:
            cout << "Enter proper Option Number." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}