# LeetCode2-两数相加

给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

## 一、思路
#### （一）、直接相加
##### 1、做题过程中出的想法：
（1）链表头部存放最低位，将两个链表从头部开始相加，对得到的和进行判断
- 和大于9，对和进行取余运算后再存入新的链表
- 和小于等于9，直接存入新的链表

（2）为实现进位功能需要设置一个进位标志位

##### 2、出现的错误：
（1）指针初始化错误
```
typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  //这句话限制了初始化必须赋值
}ListNode;

ListNode *q = new ListNode;
```
报错原因是这里需要指定参数，修改为：
```
ListNode *q = new ListNode(0);
```
（2）空指针使用next指针
```
报错1：
while (l1->next != NULL || l2->next != NULL || flag != 0)
报错2：
l1 = l1->next;
l2 = l2->next;
```
第一处出错完全是脑子短路了，本身这么写就不对。。。。

第二处欠考虑，其中一个链表为空时，不存在next指针，加上判断条件即可
##### 3、C++代码如下
```

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *l3 = NULL;
		ListNode *p;

		int sum, flag = 0;
		int a1, a2;
		while (l1 != NULL || l2 != NULL || flag != 0) {
			if (l1 == NULL)
				a1 = 0;
			else
				a1 = l1->val;
			if (l2 == NULL)
				a2 = 0;
			else
				a2 = l2->val;
			// 求和
			if (flag == 0) {
				sum = a1 + a2;
				if (sum > 9) {
					sum = sum % 10;
					flag = 1;
				}
			}
			else {
				sum = a1 + a2 + flag;
				// 复位
				flag = 0;
				if (sum > 9) {
					sum = sum % 10;
					flag = 1;
				}
			}
			// 建立链表
			ListNode *q = new ListNode(0);
			q->val = sum;
			if (l3 == NULL) {
				l3 = q;		
			}
			else {
				p->next = q;
			}
			p = q;
			if (l1 != NULL)
				l1 = l1->next;
			
			if (l2 != NULL)
				l2 = l2->next;
		}
		return l3;
	}
};
```

执行效率如下：
![执行效率](https://img-blog.csdnimg.cn/20190206230428530.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x5ZDE5OTU=,size_16,color_FFFFFF,t_70)
嗯。。。情况还不错，暂时也没有想出更好的方案了

等第二轮刷题时看看能不能想出更快的方法吧（笑）
