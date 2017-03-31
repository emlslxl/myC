#include <stdio.h>

//定义链表结构体
struct list_node
{
    struct list_node *prev;
    struct list_node *next;
};

//初始化链表节点 均指向本身
void init_list_node(struct list_node *list)
{
    list->prev = list;
    list->next = list;
}

//在链表头前插入节点
void add_list_node_before(struct list_node *list, struct list_node *node)
{
    list->prev->next = node;
    node->prev = list->prev;

    list->prev = node;
    node->next = list;
}

//在链表头后插入节点
void add_list_node_after(struct list_node *list, struct list_node *node)
{
    list->next->prev = node;
    node->next = list->next;

    list->next = node;
    node->prev = list;
}

#define list_entry(ptr,type,member)\
        ((type *)((char *)ptr - (unsigned long)(&((type *)0)->member)))

//遍历链表
#define list_for_each_entry(pos, head, member)              \
    for (pos = list_entry((head)->next, typeof(*pos), member);  \
         &pos->member != (head);    \
         pos = list_entry(pos->member.next, typeof(*pos), member))

//定义人 基类
struct persion
{
    char *name;
    int age;
    char sex;
    void (*say_hello)(struct persion *p);
    struct list_node list;
};

//人基类拥有say_hello的方法
void say_hello(struct persion *p)
{
    printf("hello my name is %s\n", p->name);
    printf("my age is %d.\n", p->age);
    printf("my sex is %c.\n", p->sex);
}

int main(void)
{
    struct persion persion1;    //实例化人基类
    struct persion persion2;    //实例化人基类

    struct persion *ppp = NULL;

    static struct list_node list_head;  //链表头

    persion1.name = "p1";
    persion1.age = 20;
    persion1.sex = 'M';
    persion1.say_hello = say_hello;  //实现基类方法

    persion2.name = "p2";
    persion2.age = 30;
    persion2.sex = 'W';
    persion2.say_hello = say_hello;

    init_list_node(&list_head);
    add_list_node_after(&list_head, &(persion1.list));
    add_list_node_after(&list_head, &(persion2.list));

    //遍历链表
    list_for_each_entry(ppp, &list_head, list)
    ppp->say_hello(ppp);


    return 0;
}