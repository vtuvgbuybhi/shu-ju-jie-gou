#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Ƴ�����Ԫ��

//����һ�����ͷ�ڵ㣬��һ������val ��ɾ����������������Node.val==vzl�Ľڵ㣬��������ͷ�ڵ�


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


//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������



//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};

//˼·1
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


//˼·2
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

//˼·2����

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


//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
//
//����������м��㣬�򷵻صڶ����м��㡣


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

//Ҫ��ֻ�ܱ�������һ��

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


//����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
//
//���磬һ�������� 6 ���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������ 1��2��3��4��5��6���������ĵ����� 3 ���ڵ���ֵΪ 4 �Ľڵ㡣


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


//����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ��������


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

//˼·2
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


//����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ

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
//        //ͷ��
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

////����ԭ��˳�򲻱�
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
//����һ������� ͷ�ڵ� head �����ж����Ƿ�Ϊ��������
//
//���һ�������ǻ��ģ���ô����ڵ����д�ǰ���󿴺ʹӺ���ǰ������ͬ��

struct ListNode
{
    int val;
    struct ListNode* next;
};

#include<stdbool.h>

//˼·1
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
























































