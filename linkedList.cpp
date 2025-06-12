 #include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node*next;
  Node(int data){
    this->data = data;
    this->next = nullptr;
  }
  
};
 Node*insertAthead(Node*head,int val){
    Node*temp = new Node(val);
  temp->next = head;
    return temp;
  };
Node*removeHead(Node*head){
if(head==nullptr){
  return head;
}
  Node*temp = head;
  head = head->next;
  delete temp;
  return head;
  }
  Node*removeTail(Node*head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node*temp = head;
    while(temp->next->next !=nullptr){
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
  }
  Node*DeleteAtAnyPosition(Node*head,int p){
    if(head==nullptr )return head;
    if(p==0){
    Node*temp = head;
    head = head->next;
    delete(temp);
    return head;
    }
    int cnt =0;
    Node*temp = head;
    while(temp!=NULL && cnt < p - 1){
      temp = temp->next;
      cnt++;
    }
    if (temp == nullptr || temp->next == nullptr) return head;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;

  }
   Node*Deletebyvalue(Node*head,int p){
    if(head==nullptr )return head;
    if(head->data==p){
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
    }
   
    Node*temp = head;
    while(temp->next != nullptr && temp->next->data != p){
      temp = temp->next;
  
    }
    if (temp == nullptr || temp->next == nullptr) return head;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;

  }
  Node*insertAtposition(Node*head,int el,int k){
  if(head==NULL){
    if(k==1){
      return new Node(el);
    }
    else{
      return head;
    }
  }
  if(k==1){
    return insertAthead(head,el);
  }
  int cnt =0;
  Node*temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt == (k-1)){
      Node*x = new Node(el);
        x->next = temp->next;
        temp->next =x;
      break;
    }
    temp = temp->next;
  }
  return head;
 }
  Node*insertAtBeforeValue(Node*head,int el,int val){
  if(head==NULL){
      return NULL;
  }
  if(head->data==val){
     Node* newNode = new Node(el);
        newNode->next = head;
        return newNode;
  }
  Node*temp = head;
  while(temp->next!=NULL){
    if(temp->next->data==val){
      Node*x = new Node(el);
        x->next = temp->next;
        temp->next =x;
      break;
    }
    temp = temp->next;
  }
  return head;
 }
 Node*insertAtTail(Node*head,int d){
if(head==NULL){
  return new Node(d);
}
Node*temp= head;
while(temp->next != NULL){
  temp= temp->next;
}
Node*newNode = new Node(d);
temp->next = newNode;
return head;
 }
 Node*FindAnElement(Node*head, int k){
  Node*temp = head;
  while(temp!=NULL){
if(temp->data== k){
  return temp;
}
temp = temp->next;
  }
  return  nullptr;
 }
void print(Node*head){
    while(head!=nullptr){
      cout << head->data << " ";
      head = head->next;
    }
    cout<<endl;
  }
  void length(Node*head){
    int cnt = 0;
    while(head!=nullptr){
      cnt++;
      head = head->next;
    }
    cout<<cnt<<endl;
  }
int main(){
int arr[10]= {1,2,3,4,5,6,7,8,9,10};
Node*head = new Node(arr[0]);
Node*current = head;
for(int i = 1;i<10;i++){
  current->next = new Node(arr[i]);
  current = current->next;
}
// print(head);
// head = removeHead(head);
// print(head);
// head = removeTail(head);
// print(head);
// length(head);

Node* result = FindAnElement(head, 5);
if (result != nullptr) {
    cout << "Element found at " << result->data << endl;
}
else {
    cout << "Element not found." << endl;
}
//head = DeleteAtAnyPosition(head, 9);
// head = Deletebyvalue(head, 5);
// head = insertAtBeforeValue(head,21,1);
// print(head);

return 0;
}