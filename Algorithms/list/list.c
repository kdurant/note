#include "list.h"

static void copy_node(LinkList* l, ElemType node)
{
    (*l)->data = node;
}

bool list_init(LinkList* l)
{
#ifdef TEST
    printf("point LinkList(struct Node*) size is %llu\n", sizeof(LinkList));
    printf("Node size is %llu\n",  sizeof(ListNode));
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

bool list_test(LinkList l, int pos, ElemType node)
{
    LinkList head = l;
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

// LinkList  list_reverse(LinkList l)
struct ListNode*  list_reverse(struct ListNode* l)
{
    if(l == NULL || l->next == NULL)
        return l;
    LinkList p = l;
    LinkList q = l->next;       // 原有链表的继续
    LinkList r;
    l->next = NULL;		//
    
    while(q != NULL)
    {
        r = q->next;   // 暂存链表下一次位置, 防止丢失
        q->next = p;         // 当前节点 插入到新链表
        
        p = q;  // 改变p的位置
        q = r;  // 恢复链表位置, 继续循环操作
    }
    l = p;
    return l;
}