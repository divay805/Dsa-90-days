//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <vector>
// this method is not used because of the space complexity o(n) we have to space complexity o(1)
class Solution{
private:
Node* getMid(Node* head){
   Node* slow = head;
   Node* fast = head->next;
   while(fast != NULL and fast->next != NULL){
       fast = fast->next->next;
       slow = slow->next;
   }
   return slow;
   
}
Node* reverse(Node* head){
    Node* curr = head ;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    
    }
    return prev;
}


  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head==NULL and head->next==NULL){
            return true;
        }
    // Step 1 find the middle (by slow and fast approch)
    Node* middle = getMid(head);
    // cout<<middle->data<<endl;
    Node * temp = middle->next;
  
    
    // Step 2 reverse the LL 
  
    // Step 3 : compare 
    Node*  head1 = head ;
    Node* head2 = reverse(temp);
    
    while(head2 !=NULL){
        if(head1->data!=head2->data){
            return false;
        };
        head1 = head1->next ;
        head2 = head2->next;
    }
    return true;
    
    
    
    
    
    
    
    
    
    }
    
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
