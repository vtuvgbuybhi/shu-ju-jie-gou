#define _CRT_SECURE_NO_WARNINGS


//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};


//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null

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

//暴力的解法
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


// 思路2-->看尾巴
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
////思路2 精简
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


//给你一个链表的头节点 head ，判断链表中是否有环

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


//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

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



//复制带随机指针的链表
//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//复制链表中的指针都不应指向原链表中的节点 。

//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//    struct ListNode* random;
//};
//
//struct Node* copyRandomList(struct Node* head) 
//{
//    //拷贝一个新节点，链接在旧节点后面
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
//        copy->val = cur->val;
//
//        copy->next = cur->next;
//        cur = copy->next;
//    }
//    //根据原节点，出来copy处的random
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
//    //断开节点，将copy链接  ，原链表缝合
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


















































