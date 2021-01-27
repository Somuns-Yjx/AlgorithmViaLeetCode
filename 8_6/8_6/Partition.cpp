#include "Partition.h"

/* Name:	 Partition(ListNode* head, int x)
*  Function: Given a linked list and a specific value x, divide the linked list so
*		     that all nodes less than x are before nodes greater than or equal to x. 
*			 You should remember to keep the initial relative position,      
*  Example:  Input1 = 1, 4, 3, 2, 5, 2
*			 Input2 = 3
*			 Output = 1, 2, 2, 4, 3, 5
*  Return:	 ListNode*
*/
ListNode* Partition(ListNode* head, int x)
{
	vector<int> min;								/*存放小于x*/
	vector<int> max;								/*存放大于x*/
	ListNode* temp = head;
	while (temp != NULL)							/*遍历链表*/
	{
		if (temp->val < x)
			min.push_back(temp->val);
		else
			max.push_back(temp->val);

		temp = temp->next;
	}
	temp = head;
	for (int i = 0, size = (int)min.size(); i < size; i++)/*重新为链表赋Value(<x)*/
	{
		temp->val = min[i];
		temp = temp->next;
	}
	for (int i = 0, size = (int)max.size(); i < size; i++)/*重新为链表赋Value(>x)*/
	{
		temp->val = max[i];
		temp = temp->next;
	}
	return head;
}