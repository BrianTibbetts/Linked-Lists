/* A solution to leetcode problem 2181: Merge Nodes in Between Zeros
 * -The head of a singly linked list is given which contains a series of integers separated by 0s. For every two consecutive 0s,
 *     merge all the nodes lying between them into a single node whose value is their sum. The modified list should not contain any 0s.
 * -Return the head of the modified linked list.
 * -Contraints: The beginning and end of the list will have Node.val == 0. There are no two consecutive nodes with Node.val == 0.
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
struct ListNode* mergeNodes(struct ListNode* head);

int main(){
    // create some linked lists to test
    struct ListNode tail_1 = {0, NULL};
    struct ListNode node7_1 = {2, &tail_1};
    struct ListNode node6_1 = {5, &node7_1};
    struct ListNode node5_1 = {4, &node6_1};
    struct ListNode node4_1 = {0, &node5_1};
    struct ListNode node3_1 = {1, &node4_1};
    struct ListNode node2_1 = {3, &node3_1};
    struct ListNode head_1 = {0, &node2_1};
    
    struct ListNode tail_2 = {0, NULL};
    struct ListNode node7_2 = {2, &tail_2};
    struct ListNode node6_2 = {2, &node7_2};
    struct ListNode node5_2 = {0, &node6_2};
    struct ListNode node4_2 = {3, &node5_2};
    struct ListNode node3_2 = {0, &node4_2};
    struct ListNode node2_2 = {1, &node3_2};
    struct ListNode head_2 = {0, &node2_2};
    
    // view the contents of each linked list
    printf("Linked list 1 nodes: ");
    printList(&head_1);
    printf("Linked list 2 nodes: ");
    printList(&head_2);

    // merge the nodes of each linked list
    struct ListNode *mergedList = &head_1;
    printf("Linked list 1 merged nodes: ");
    mergedList = mergeNodes(&head_1);
    printList(mergedList);
    printf("Linked list 2 merged nodes: ");
    mergedList = mergeNodes(&head_2);
    printList(mergedList);

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



/* mergeNodes - Sums the values of 0-separated nodes in a linked list
 *   argument: head, a pointer to the head of a linked list
 *   return value: a pointer to the head of the same linked list, now merged
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *nextptr = head->next;    // A node used to traverse the linked list
    struct ListNode *sumnode = head;          // A 0-value node in the original linked list used to track a sum of 0-value separated nodes
    
    while(nextptr->next != NULL){       // Traverse the linked list, stopping at the tail

        while(nextptr->val != 0){       // Add each node's value until the next 0-value node is reached
            sumnode->val += nextptr->val;
            nextptr = nextptr->next;
        }

        if(nextptr->next != NULL){      // If there are still more nodes to merge, move on to the next group of 0-value separated nodes
            sumnode->next = nextptr;        // The node with the sum should point to the next 0-value node.
            sumnode = nextptr;		    // Set the node for the next sum to be the next 0-value node.
            nextptr = nextptr->next;        // The node which is being used to traverse the linked list should be set to the next node after the next 0-value node.
        }
        else{
            sumnode->next = NULL;       // Set the pointer to the next node after the tail to NULL to indicate the end of the merged linked list
        }
    }

    return head;
}
