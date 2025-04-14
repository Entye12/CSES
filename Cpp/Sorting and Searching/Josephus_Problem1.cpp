#include <bits/stdc++.h>
using namespace std;

int n,a;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
    
    Node(int data=0){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoubleLinkedList {
    private:
        Node* head;
        Node* tail;
        int size;
        vector<int> ans;
    
    public:
        DoubleLinkedList(int n){
            head = nullptr;
            tail = nullptr;
            size = n;
            ans.reserve(n);
        }
        
        void append(int data){
            Node* new_node = new Node(data);
            if (!head){
                head = tail = new_node;
            }
            else {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }

        void loop(){
            if (head && tail){
                tail->next = head;
                head->prev = tail;
            }
        }

        void run_josephus1(){
            Node* cur = head;
            while (size>0){
                Node* to_remove = cur->next;
                Node* fut_cur = to_remove->next;
                ans.push_back(to_remove->data);
                cur->next = fut_cur;
                fut_cur->prev = cur;
                cur = fut_cur;
                size--;
                delete to_remove;
            }
        }

        void print_answer(){
            for (int x: ans){
                printf("%d ",x);
            }
        }
};

int main(){
    scanf("%d",&n);
    DoubleLinkedList dll(n);
    for (int i=1;i<=n;i++){
        dll.append(i);
    }
    dll.loop();
    dll.run_josephus1();
    dll.print_answer();
    return 0;
}