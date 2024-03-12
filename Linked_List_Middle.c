/* A solution to leetcode problem 876: Middle of the Linked List
 * -Given the head of a singly linked list, return the middle node of the linked list.
 * -If there are two middle nodes, return the second middle node.
 */
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;		    // val = [1, 100]
    struct ListNode *next;  // pointer to next node in the linked list, # of nodes = [1, 100]
};

void printList(struct ListNode *head);
int countNodes(struct ListNode *head);
struct ListNode *middleNode(struct ListNode *head);

int main(){
    // create some linked lists to test
    struct ListNode tail_1 = {5, NULL};
    struct ListNode node4_1 = {4, &tail_1};
    struct ListNode node3_1 = {3, &node4_1};
    struct ListNode node2_1 = {2, &node3_1};
    struct ListNode head_1 = {1, &node2_1};
    
    struct ListNode tail_2 = {6, NULL};
    struct ListNode node5_2 = {5, &tail_2};
    struct ListNode node4_2 = {4, &node5_2};
    struct ListNode node3_2 = {3, &node4_2};
    struct ListNode node2_2 = {2, &node3_2};
    struct ListNode head_2 = {1, &node2_2};

    // view the contents of each linked list
    printf("Linked list 1 nodes: ");
    printList(&head_1);
    printf("Linked list 2 nodes: ");
    printList(&head_2);
    
    // count the nodes of each linked list
    printf("Linked list 1 has %d nodes\n", countNodes(&head_1));
    printf("Linked list 2 has %d nodes\n", countNodes(&head_2));

    // find the middle node of each linked list
    struct ListNode *midnode = &head_1;
    printf("Linked list 1 middle nodes: ");
    midnode = middleNode(&head_1);
    printList(midnode);
    printf("Linked list 2 middle nodes: ");
    midnode = middleNode(&head_2);
    printList(midnode);

    return 0;
}

/* printList - Prints the contents of a linked list
 *   argument: head, a pointer to the head of a linked list
 */
void printList(struct ListNode *head){
    struct ListNode *nextptr = head;
    while (nextptr->next != NULL){	
        printf("%d -> ", nextptr->val); // Print all node contents except for the last node
        nextptr = nextptr->next;
    }
    printf("%d\n", nextptr->val);	// Print the last node's contents
}

/* countNodes - Counts the number of nodes in a linked list
 *   argument: head, a pointer to the head of a linked list
 *   return value: the number of nodes in the linked list
 */
int countNodes(struct ListNode *head){
    struct ListNode *nextptr = head;
    int nodecount = 0;
    while (nextptr != NULL){
        nodecount++;
        nextptr = nextptr->next;
    }
    return nodecount;
}

/* middleNode - Finds the middle node of a linked list
 *   argument: head, a pointer to the head of a linked list
 *   return value: a pointer to the middle node
 */
struct ListNode *middleNode(struct ListNode *head) {
    struct ListNode *mid = head;
    // int divide the number of nodes by 2 to find the number of nodes to advance until the middle node is reached
    int middlecount = countNodes(head) / 2;
    
    // advance through the linked list until reaching the middle and return that node
    while(middlecount > 0){
        mid = mid->next;
        middlecount--;
    }
    return mid;
}
