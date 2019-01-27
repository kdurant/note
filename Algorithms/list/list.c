#include "list.h"

LinkList test;

static void copy_node(LinkList* l, ElemType node)
{
    (*l)->data = node;
}

bool list_init(LinkList* l)
{
#ifdef TEST
    printf("point LinkList(struct Node*) size is %llu\n", sizeof(LinkList));
    printf("Node size is %llu\n",  sizeof(Node));
#endif
    // 给头结点申请内存空间
    LinkList p = (LinkList)malloc(sizeof(ListNode));
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
    LinkList p = (LinkList)malloc(sizeof(ListNode));
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

// TODO 异常处理
bool list_insert(LinkList* l, int pos, ElemType node)
{
    LinkList head = *l;
    LinkList new = (LinkList)malloc(sizeof(ListNode));
    copy_node(&new, node);

    while(pos > 0)
    {
        head = head->next;
        pos--;
    }
    // 插入结点
    new->next = head->next;
    head->next = new;
    return true;
}

bool list_pos_delete(LinkList* l, int pos)
{
    LinkList p = (*l)->next;
    LinkList d;

    while(--pos > 0)
    {
        if(p->next == NULL)
            return false;
        else
            p = p->next;
    }
    d = p->next;
    p->next = p->next->next;

    free(d);
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

int list_find_item(LinkList l, ElemType node)
{
    int pos = 0;
    LinkList p = l->next;   // 跳过没有数据域的头结点

    while(p->data != node)
    {
        pos++;
        p = p->next;
    }
    return pos;
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
    return i;
}