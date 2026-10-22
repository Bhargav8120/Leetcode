/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:

    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;

            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        int count = 0;
        ListNode* countPointer = head;

        while(countPointer != NULL){
            count++;
            countPointer = countPointer->next;
        }

        k = k % count;

        if(k == 0){
            return head;
        }

        // Number of nodes in first part
        int shift = count - k;

        ListNode* temp = head;

        // Move to the LAST node of first part
        for(int i = 1; i < shift; i++){
            temp = temp->next;
        }

        // Second part starts here
        ListNode* secondHead = temp->next;

        // Break the list
        temp->next = NULL;

        // Reverse first part
        ListNode* firstHead = reverseList(head);

        // Reverse second part
        secondHead = reverseList(secondHead);

        // Connect first and second parts
        ListNode* current = firstHead;

        while(current->next != NULL){
            current = current->next;
        }

        current->next = secondHead;

        // Reverse complete list
        return reverseList(firstHead);
    }
};