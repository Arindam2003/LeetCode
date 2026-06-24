struct Node{
    int val;
    Node *next;
    Node(int x){
        val=x;
        next=nullptr;
    }
};

class MyLinkedList {
public:
Node *head;
    MyLinkedList() {
        head=nullptr;
    }
    
    int get(int index) {
        if(index<0)
        {
            return -1;
        }
        Node *temp=head;
        int i=0;
        while(i<index)
        {
            if(temp==nullptr)
            {
                return -1;
            }
            i++;
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            return -1;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newnode=new Node(val);
        newnode->next=head;
        head=newnode;
    }
    
    void addAtTail(int val) {
        Node *temp=head;
        Node *newnode=new Node(val);
        if(head==nullptr)
        {
            head=newnode;
            return;
        }
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0)
        {
            return;
        }
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        int i=0;
        Node *temp=head;
        while(i<index-1)
        {
            temp=temp->next;
            i++;
        }

        Node *newnode=new Node(val);
        Node *remain=temp->next;
        temp->next=newnode;
        newnode->next=remain;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || head==nullptr)
        {
            return;
        }
        if(index==0)
        {
            Node *del=head;
            head=head->next;
            delete del;
            return;
        }

        int i=0;
        Node *temp=head;
        while(i<index-1)
        {
            if(temp==nullptr || temp->next==nullptr)
            {
                return;
            }
            i++;
            temp=temp->next;
        }
        if(temp->next==nullptr)
        {
            return;
        }
        Node *del=temp->next;
        temp->next=del->next;
        delete del;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */