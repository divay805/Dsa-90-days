//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
struct Node* reverse(struct Node* head){
   struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    
// To reverse the LL 
while(curr!=NULL){
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;

}
    return prev;
}

// suntion for the adding of the linkList:
void insertNodeAtTail(struct Node* &head , struct Node* &tail , int val){
   struct Node * temp = new Node(val);
    
    if(head==NULL){
        head = temp;
        tail= temp;
    }
    else{
    tail->next= temp;
    tail = temp;
        
    }
}

struct Node* addLL(struct Node* first , struct Node* second){
    
struct Node * ansHead = NULL;
struct Node* ansTail = NULL;

// LOOP 
int carry =0 ; 
while(first != NULL and second != NULL){
    
    int sum = first->data + second->data + carry ;
    int dighit = sum%10;
    
    insertNodeAtTail(ansHead,ansTail,dighit);
    
    carry = sum/10;
    
    first = first->next;
    second = second->next;

}

        
 
while(first!=NULL){
        
    int sum = first->data + carry ;
    int dighit = sum%10;
    
    insertNodeAtTail(ansHead,ansTail,dighit);
    
    carry = sum/10;
    
    first = first->next;


}



while(second!=NULL){
        
    int sum = second->data + carry ;
    int dighit = sum%10;
    
    insertNodeAtTail(ansHead,ansTail,dighit);
    
    carry = sum/10;
    
    second = second->next;
}
while(carry!=0){
        int sum =  carry ;
    int dighit = sum%10;
    insertNodeAtTail(ansHead, ansTail , dighit);
    carry = sum/10;
}

return ansHead;

}
  
// Public is  started in the classs:
public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        struct Node * ans = addLL(first , second );
        ans = reverse(ans);
        return ans;
        
       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends