#include "list.h"

LinkList test;

bool list_init(LinkList* l)
{
#ifdef TEST
    printf("point LinkList(struct Node*) size is %llu\n", sizeof(LinkList));
    printf("Node size is %llu\n",  sizeof(Node));
#endif
    // 给头结点申请内存空间
    LinkList p = (LinkList)malloc(sizeof(Node));
    if(p == NULL)
        return false;
    else
    {
		
        p->next = NULL;
        *l = p;
    }

    return true;
}

bool list_append(LinkList* l, ElemType node)
{
    /**
     * @brief LinkList *q = l;
     * 
     */
	LinkList q = *l;
    LinkList p = (LinkList)malloc(sizeof(Node));
    if(p == NULL)
        return false;
    else
    {
		
        p->data = node;
        p->next = NULL;
		while ( q != NULL)
		{
			if (q->next == NULL)
				break;
			else
				q = q->next;
		}
        q->next = p;
    }

    return true;
}

void list_print(LinkList l)
{
    int i = 0;
    LinkList p = l->next;   // 跳过没有数据域的头结点
    
	while (p != NULL)
    {
        printf("list number %d is %d\n", i, p->data);
        p = p->next;
		i++;
    } 
}

int list_length(LinkList l)
{
    int i = 0;
    LinkList p = l->next;   // 跳过没有数据域的头结点
    
	while (p != NULL)
    {
        p = p->next;
		i++;
    } 
    return i+1;
}