#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//移除链表元素

//给你一链表的头节点，和一个整数val ，删除链表中所以满足Node.val==vzl的节点，并返回新头节点


//1-->2-->6-->3-->4-->5-->6            --->     1-->2-->3-->4-->5
                                       
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct* ListNode cur = head;
//    struct* ListNode prev = NULL;
//    while (cur)
//    {
//        if (cur->val==val)
//        {
//            if (cur == head)
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//            }
//
//            else
//            {
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}


//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		if (cur->val == val && cur == head)
//		{
//			if (cur->next == NULL)
//			{
//				free(cur);
//				return NULL;
//			}
//			else
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//		}
//		else if (cur->next == NULL)
//		{
//			if (cur->val == val)
//			{
//				return NULL;
//			}
//			else 
//			{
//				return head;
//			}
//		}
//		else
//		{
//			if (cur->next->val == val)
//			{
//				struct ListNode* curr = cur->next->next;
//				if (curr == NULL)
//				{
//					free(cur->next);
//					cur->next = NULL;
//					cur = cur->next;
//				}
//				else
//				{
//					free(cur->next);
//					cur->next = curr;
//				}
//			}
//			else
//			{
//				cur = cur->next;
//			}
//		}
//	}
//	return head;
//}


//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表



//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};

//思路1
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head->next == NULL)
//    {
//        return head;
//    }
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//    while (n2)
//    {
//        n2->next = n1;
//
//        n1=n2;
//        n2 = n3;
//        if (n3 != NULL)
//        {
//            n3 = n3->next;
//        }
//    }
//    return n1;
//}


//思路2
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* cur, * next1,*newHead;
//    cur = head;
//    next1 = head->next;
//    newHead = NULL;
//   
//    while (cur)
//    {
//        cur->next = newHead;
//        newHead = cur;
//
//        cur = next1;
//
//        if (next1 != NULL)
//        {
//            next1 = next1->next;
//        }
//    }
//    return newHead;
//}

//思路2精简

//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* newHead = NULL;
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//
//        cur->next = newHead;
//        newHead = cur;
//
//        cur = next;
//    }
//    return newHead;
//}


//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//	int i = 0;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		i++;
//		cur = cur->next;
//	}
//	i = i / 2;
//	cur = head;
//	for (int j = 0; j < i; j++)
//	{
//		cur = cur->next;
//	}
//	return cur;
//    
//}

//要求只能遍历链表一次

//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow= fast = head;
//    while (fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next -> next;
//        if (fast == NULL)
//        {
//            return slow;
//        }
//    }
//    return slow;
//}


//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
//
//例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* getKthFromEnd(struct ListNode* head, int k) 
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    for (int i = 0; i < k; i++)
//    {
//        fast = fast->next;
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//
//    }
//    while (fast != NULL)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};

//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
//{
//    if (l1 == NULL)
//    {
//        return l2;
//    }
//    if (l2 == NULL)
//    {
//        return l1;
//    }
//    struct ListNode* head = NULL, * tail = NULL;
//
//    if (l1->val < l2->val)
//    {
//        head = tail = l1;
//        l1 = l1->next;
//    }
//    else
//    {
//        head = tail = l2;
//        l2 = l2->next;
//    }
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            tail->next = l1;
//            tail = l1;
//            l1 = l1->next;
//        }
//        else
//        {
//            tail->next = l2;
//            tail = l2;
//            l2 = l2->next;
//        }
//    }
//    if (l1)
//    {
//        tail->next = l1;
//        l1 = l1->next;
//    }
//    else
//    {
//        tail->next = l2;
//        l2 = l2->next;
//    }
//    return head;
//}

//思路2
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//    if (l1 == NULL)
//    {
//        return l2;
//    }
//    if (l2 == NULL)
//    {
//        return l1;
//    }
//    struct ListNode* head = NULL, * tail = NULL;
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            tail->next = l1;
//            tail = l1;
//            l1 = l1->next;
//        }
//        else
//        {
//            tail->next = l2;
//            tail = l2;
//            l2 = l2->next;
//        }
//    }
//    if (l1)
//    {
//        tail->next = l1;
//    }
//    else
//    {
//        tail->next = l2;
//    }
//    return head->next;
//}


//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前

//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//
////struct ListNode* partition(struct ListNode* head, int x) 
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//    struct ListNode* cur = head, * newHead = NULL, *next=cur->next,*tail=NULL;
//
//    if (tail == NULL)
//    {
//        cur->next = newHead;
//        newHead = cur;
//        tail = cur;
//        cur = next;
//    }
//
//    while (next)
//    {
//        next = cur->next;
//        //头插
//        if (cur->val < x)
//        {
//            cur->next = newHead;
//            newHead = cur;
//            cur = next;
//        }
//        else
//        {
//            tail->next = cur;
//            cur->next = NULL;
//            tail = cur;
//            cur = next;
//        }
//    }
//    return newHead;
//}


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};

////保持原来顺序不变
//
//struct ListNode* partition(struct ListNode* head, int x)
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//    struct ListNode* less = NULL, * cur = head, * greater = NULL, * next=cur->next ,* tailless = NULL, * tailgreater = NULL;
//    if (next == NULL)
//    {
//        return head;
//    }
//    while (next)
//    {
//        next = cur->next;
//        if (cur->val < x)
//        {
//            if (less == NULL)
//            {
//                less = cur;
//                tailless = cur;
//            }
//            else
//            {
//                cur->next = NULL;
//                tailless->next = cur;
//                tailless = cur;
//            }
//        }
//        else
//        {
//            if (greater == NULL)
//            {
//                greater = cur;
//                tailgreater = cur;
//                cur->next = NULL;
//            }
//            else
//            {
//                cur->next = NULL;
//                tailgreater->next = cur;
//                tailgreater = cur;
//            }
//        }
//        cur = next;
//    }
//    if (tailless == NULL)
//    {
//        return greater;
//    }
//    tailless->next = greater;
//    return less;
//}

//
//给定一个链表的 头节点 head ，请判断其是否为回文链表。
//
//如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的

struct ListNode
{
    int val;
    struct ListNode* next;
};

#include<stdbool.h>

//思路1
//bool isPalindrome(struct ListNode* head)
//{
//    struct ListNode* n1 = NULL, * n2, * n3, * fast = head, * slow = head;
//    if (head == NULL)
//    {
//        return true;
//    }
//    if (head->next == NULL)
//    {
//        return true;
//    }
//    while (fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == NULL)
//        {
//            n2 = slow;
//            n3 = slow->next;
//            while (n2)
//            {
//                n2->next = n1;
//
//                n1 = n2;
//                n2 = n3;
//                if (n3 != NULL)
//                {
//                    n3 = n3->next;
//                }
//            }
//            while (n1->val == head->val)
//            {
//                n1 = n1->next;
//                head = head->next;
//                if (n1 == NULL)
//                {
//                    return true;
//                }
//            }
//            return false;
//        }
//    }
//    n2 = slow;
//    n3 = slow->next;
//    while (n2)
//    {
//        n2->next = n1;
//
//        n1 = n2;
//        n2 = n3;
//        if (n3 != NULL)
//        {
//            n3 = n3->next;
//        }
//    }
//    while (n1->val == head->val)
//    {
//        n1 = n1->next;
//        head = head->next;
//        if (n1 == NULL)
//        {
//            return true;
//        }
//    }
//    return false;
//}
























































