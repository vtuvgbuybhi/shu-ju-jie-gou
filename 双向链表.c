#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//
////                           单                   双
//                    
//
////                  带头                                          不带头
//                    
//
////             循环                                                     非循环
//
////总共有8种结构的链表     --》最常见的就是  单项无头非循环链表（经常在笔试、OJ题中常见）
//   //          双向带头循环链表（最主要用于存储数据）
//
//
//typedef int LTDataType;
//
//typedef struct ListNode 
//{
//    LTDataType data;
//    struct ListNode* next;
//    struct ListNode* prev;
//}LTNode;
//
//LTNode* ListInit()
//{
//    LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
//    if (phead == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    phead->next = phead;
//    phead->prev = phead;
//    return phead;
//}
//
//
//LTNode* BuyListNode(LTDataType x)
//{
//    LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
//    if (newnode == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    newnode->data = x;
//    newnode->next = NULL;
//    newnode->prev = NULL;
//    return newnode;
//}
//
//
////pos位置之前插入
//void ListInsert(LTNode* pos, LTDataType x)
//{
//    assert(pos);
//    LTNode* newnode = BuyListNode(x);
//    LTNode* posprev = pos->prev;
//
//    posprev->next = newnode;
//    newnode->prev = posprev;
//    newnode->next = pos;
//    pos->prev = newnode;
//}
//
//
//
//void ListPushBack(LTNode* phead, LTDataType x)
//{
//    assert(phead);
//    //LTNode* tail = phead->prev;
//    //LTNode* newnode = BuyListNode(x);
//
//    //phead->prev = newnode;
//    //newnode->next = phead;
//    //newnode->prev = tail;
//    //tail->next = newnode;
//
//    ListInsert(phead, x);
//}
//
//void ListPopBack(LTNode* phead)
//{
//    assert(phead);
//    LTNode* Popprev = phead->prev;
//    if (Popprev != phead)
//    {
//        Popprev = Popprev->prev;
//        free(phead->prev);
//        Popprev->next = phead;
//        phead->prev = Popprev;
//    }
//}
//
//void ListPushFront(LTNode* phead,LTDataType x)
//{
//    assert(phead);
//    //LTNode* newnode = BuyListNode(x);
//
//    //LTNode* Pushnext = phead->next;
//
//    //phead->next = newnode;
//    //newnode->prev = phead;
//    //newnode->next = Pushnext;
//    //Pushnext->prev = newnode;
//
//
//    ListInsert(phead->next, x);
//}
//
//void ListPopFront(LTNode* phead)
//{
//    assert(phead);
//    LTNode* Popnext = phead->next;
//    if (Popnext != phead)
//    {
//        Popnext = Popnext->next;
//        free(phead->next);
//        phead->next = Popnext;
//        Popnext->prev = phead;
//    }
//}
//
//
//void ListPrint(LTNode* phead)
//{
//    assert(phead);
//    LTNode* cur = phead->next;
//    while (cur != phead)
//    {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    printf("\n");
//}
//
//
//LTNode* ListFind(LTNode* phead, LTDataType x)
//{
//    assert(phead);
//    LTNode* cur = phead->next;
//    while (cur != phead)
//    {
//        if (cur->data == x)
//        {
//            return cur;
//        }
//        cur = cur->next;
//    }
//    return NULL;
//}
//
//
//
////删除pos位置
//void ListErase(LTNode* pos)
//{
//    assert(pos);
//    LTNode* posprev = pos->prev;
//    LTNode* posnext = pos->next;
//
//    free(pos);
//
//    posprev->next = posnext;
//    posnext->prev = posprev;
//}
//
//
//void TestList1()
//{
//    LTNode* plist = ListInit();
//    ListPushBack(plist,1);
//    ListPushBack(plist, 2);
//    ListPushBack(plist,3);
//
//    ListPrint(plist);
//
//    ListPopBack(plist);
//    ListPopBack(plist);
//    ListPopBack(plist);
//    
//    ListPrint(plist);
//
//    ListPushBack(plist, 5);
//    ListPrint(plist);
//
//}
//
//void TestList2()
//{
//    LTNode* plist = ListInit();
//    ListPushBack(plist, 2);
//    ListPushBack(plist, 3);
//    ListPushBack(plist, 4);
//
//    ListPrint(plist);
//
//    ListPushFront(plist, 1);
//
//    ListPrint(plist);
//
//    ListPopFront(plist);
//    ListPopFront(plist);
//    ListPopFront(plist);
//    ListPopFront(plist);
//
//    ListPrint(plist);
//    ListPushBack(plist, 4);
//    ListPrint(plist);
//
//}
//
//void TestList3()
//{
//    LTNode* plist = ListInit();
//    ListPushBack(plist, 1);
//    ListPushBack(plist, 2);
//    ListPushBack(plist, 3);
//    ListPushBack(plist, 4);
//
//    ListPrint(plist);
//
//    LTNode* pos = ListFind(plist, 1);
//    ListErase(pos);
//
//    ListPrint(plist);
//
//}
//
//
//int main()
//{
//    //TestList1();
//    //TestList2();
//    TestList3();
//
//
//    return 0;
//}



















































