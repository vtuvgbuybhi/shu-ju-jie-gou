#define _CRT_SECURE_NO_WARNINGS


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};


//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null

        //                    -----         ------
        //                   |     |  ----->|     |   ------ 
        //                    ------         -----          |
        //                                                  |     -------             -------
        //                                                   -->  |     |     -->     |     |
        //                                                   -->  |     |     -->     |     |
        //                                                  |     -------             -------
        // ------         ------             ------         |
        //|      |  -->   |    |  -->       |      |  ------
        //-------         -----              ------


#include<stdio.h>

//�����Ľⷨ
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
//{
//    struct ListNode* curA = headA, * curB = headB;
//    while (curA)
//    {
//        curB = headB;
//        while (curB)
//        {
//            if (curA == curB)
//            {
//                return curA;
//            }
//            else
//            {
//                curB = curB->next;
//            }
//        }
//        curA = curA->next;
//    }
//    return NULL;
//}


// ˼·2-->��β��
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lengthA = 1;
//    int lengthB = 1;
//    while(tailA->next)
//    {
//        lengthA++;
//        tailA = tailA->next;
//    }
//    while (tailB->next)
//    {
//        lengthB++;
//        tailB = tailB->next;
//    }
//
//    if (tailA == tailB)
//    {
//        if (lengthA == lengthB)
//        {
//            while (headA != headB)
//            {
//                headA = headA->next;
//                headB = headB->next;
//            }
//            return headA;
//        }
//        else
//        {
//            if (lengthA > lengthB)
//            {
//                for (int i = 0; i < lengthA - lengthB; i++)
//                {
//                    headA = headA->next;
//                }
//                while (headA != headB)
//                {
//                    headA = headA->next;
//                    headB = headB->next;
//                }
//                return headA;
//            }
//            else
//            {
//                for (int i = 0; i < lengthB - lengthA; i++)
//                {
//                    headB = headB->next;
//                }
//                while (headA != headB)
//                {
//                    headA = headA->next;
//                    headB = headB->next;
//                }
//                return headA;
//            }
//        }
//    }
//    else
//    {
//        return NULL;
//    }
//}

//#include<math.h>
//
////˼·2 ����
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lengthA = 1;
//    int lengthB = 1;
//    while(tailA->next)
//    {
//        lengthA++;
//        tailA = tailA->next;
//    }
//    while (tailB->next)
//    {
//        lengthB++;
//        tailB = tailB->next;
//    }
//
//    int gap = abs(lengthA - lengthB);
//    struct ListNode* longList = headA;
//    struct ListNode* shortList = headB;
//
//    if (lengthA < lengthB)
//    {
//        longList = headB;
//        shortList = headA;
//    }
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//    return longList;
//}


//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л�

#include<stdbool.h>


//bool hasCycle(struct ListNode* head) 
//{
//    struct ListNode* slow = head, * fast = head;
//    if (head == NULL)
//    {
//        return false;
//    }
//    if (head->next==NULL)
//    {
//        return false;
//    }
//    while (fast->next!=NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == NULL)
//        {
//            return false;
//        }
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//}


//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

//struct ListNode* detectCycle(struct ListNode* head) 
//{
//    struct ListNode* slow = head, * fast = head, * meetNode = NULL, *gohead=head;
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    if (head->next == NULL)
//    {
//        return NULL;
//    }
//    while (fast->next != NULL)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == NULL)
//        {
//            return false;
//        }
//        if (fast == slow)
//        {
//            meetNode = fast;
//            while (gohead != meetNode)
//            {
//                gohead = gohead->next;
//                meetNode = meetNode->next;
//            }
//            return gohead;
//        }
//    }
//    return NULL;
//}



//���ƴ����ָ�������
//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
//�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
//���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��

//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//    struct ListNode* random;
//};
//
//struct Node* copyRandomList(struct Node* head) 
//{
//    //����һ���½ڵ㣬�����ھɽڵ����
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
//        copy->val = cur->val;
//
//        copy->next = cur->next;
//        cur = copy->next;
//    }
//    //����ԭ�ڵ㣬����copy����random
//    cur = head;
//    while (cur)
//    {
//        struct ListNode* copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = copy->next;
//    }
//    //�Ͽ��ڵ㣬��copy����  ��ԭ������
//    struct ListNode* copyhead = NULL, * copytail = NULL;
//    cur = head;
//    while (cur)
//    {
//        struct ListNode* copy = cur->next;
//        struct ListNode* next = copy->next;
//        if (copyhead == NULL)
//        {
//            copyhead = copytail = copy;
//        }
//        else
//        {
//            copytail->next = copy;
//            copytail = copy;
//        }
//        cur->next = next;
//        cur = next;
//    }
//    return copyhead;
//}


















































