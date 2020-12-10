#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Polyomial
{
	float coef;
	int exp;
	struct Polyomial *next;
}*Poly, Polyomial;               //Poly为结点指针类型

void Insert(Poly p, Poly h){//插入结点
	if (p->coef == 0)
		free(p);       //系数为0时释放结点
	else{
		Poly q1, q2;
		q1 = h;
		q2 = h->next;
		while (q2 && p->exp < q2->exp){   //查找插入位置
			q1 = q2;
			q2 = q2->next;
		}
		if (q2 && p->exp == q2->exp){     //将指数相同相合并
			q2->coef += p->coef;
			free(p);
			if (!q2->coef){             //系数为0的话释放结点
				q1->next = q2->next;
				free(q2);
			}
		}
		else{                          //指数为新时将结点插入
			p->next = q2;
			q1->next = p;
		}
	}
}

Poly CreatePoly(Poly head, int m){//建立一个头指针为head、项数为m的一元多项式
	int i;
	Poly p;
	p = head = (Poly)malloc(sizeof(struct Polyomial));
	head->next = NULL;
	for (i = 0; i < m; i++){
		p = (Poly)malloc(sizeof(struct Polyomial));//建立新结点以接收数据
		printf("输入第%d项的系数与指数:", i + 1);
		scanf("%f %d", &p->coef, &p->exp);
		Insert(p, head);   //调用Insert函数插入结点
	}
	return head;
}

void DestroyPoly(Poly p){//销毁多项式p
	Poly q1, q2;
	q1 = p->next;
	q2 = q1->next;
	while (q1->next){
		free(q1);
		q1 = q2;//指针后移
		q2 = q2->next;
	}
}

void PrintPoly(Poly P){//输出多项式
	Poly q = P->next;
	int flag = 1;//项数计数器
	if (!q) { //若多项式为空，输出0
		putchar('0');
		printf("\n");
		return;
	}
	while (q){
		if (q->coef > 0 && flag != 1)
			putchar('+'); //系数大于0且不是第一项
		if (q->coef != 1 && q->coef != -1){//系数非1或-1的普通情况
			printf("%g", q->coef);
			if (q->exp == 1)
				putchar('X');
			else if (q->exp)
				printf("X^%d", q->exp);
		}
		else{
			if (q->coef == 1){
				if (!q->exp)
					putchar('1');
				else if (q->exp == 1)
					putchar('X');
				else
					printf("X^%d", q->exp);
			}
			if (q->coef == -1){
				if (!q->exp)
					printf("-1");
				else if (q->exp == 1)
					printf("-X");
				else
					printf("-X^%d", q->exp);
			}
		}
		q = q->next;
		flag++;
	}
	printf("\n");
}

int compare(Poly a, Poly b){//比较a与b中的指数
	if (a && b){
		if (!b || a->exp > b->exp)
			return 1;
		else if (!a || a->exp < b->exp)
			return -1;
		else
			return 0;
	}
	else if (!a && b)
		return -1;//a多项式已空，但b多项式非空
	else
		return 1;//b多项式已空，但a多项式非空
}

Poly AddPoly(Poly pa, Poly pb){//求解并建立多项式a+b，返回其头指针
	Poly qa = pa->next;
	Poly qb = pb->next;
	Poly headc, hc, qc;
	hc = (Poly)malloc(sizeof(struct Polyomial));//建立头结点
	hc->next = NULL;
	headc = hc;
	while (qa || qb){
		qc = (Poly)malloc(sizeof(struct Polyomial));
		switch (compare(qa, qb)){
		case 1:
		{
				  qc->coef = qa->coef;
				  qc->exp = qa->exp;
				  qa = qa->next;
				  break;
		}
		case 0:
		{
				  qc->coef = qa->coef + qb->coef;
				  qc->exp = qa->exp;
				  qa = qa->next;
				  qb = qb->next;
				  break;
		}
		case -1:
		{
				   qc->coef = qb->coef;
				   qc->exp = qb->exp;
				   qb = qb->next;
				   break;
		}
		}
		if (qc->coef != 0){
			qc->next = hc->next;
			hc->next = qc;
			hc = qc;
		}
		else
			free(qc);//当相加系数为0时，释放该结点
	}
	return headc;
}

Poly SubtractPoly(Poly pa, Poly pb){  //求解并建立多项式a-b，返回其头指针
	Poly h = pb;
	Poly p = pb->next;
	Poly pd;
	while (p){//将pb的系数取反
		p->coef *= -1;
		p = p->next;
	}
	pd = AddPoly(pa, h);
	for (p = h->next; p; p = p->next)    //恢复pb的系数
		p->coef *= -1;
	return pd;
}

void menu(){
	printf("*****************************\n");
	printf("******1、输出多项式a,b!******\n");
	printf("******2、输出多项式a+b!******\n");
	printf("******3、输出多项式a-b!******\n");
	printf("******4、退出！        ******\n");
	printf("*****************************\n");
}

int main(){
	int m, n, flag = 0;
	//float x;
	Poly pa = 0, pb = 0, pc, pd;//定义各式的头指针，pa与pb在使用前初值NULL
	printf("输入a的项数:");
	scanf("%d", &m);
	pa = CreatePoly(pa, m);//建立多项式a
	printf("输入b的项数:");
	scanf("%d", &n);
	pb = CreatePoly(pb, n);//建立多项式b
	menu();
	for (;; flag = 0){
		printf("-->请选择执行的操作:");
		scanf("%d", &flag);
		if (flag == 1){
			printf("多项式a：");
			PrintPoly(pa);
			printf("多项式b：");
			PrintPoly(pb);
			continue;
		}
		if (flag == 2){
			pc = AddPoly(pa, pb);
			printf("多项式a+b：");
			PrintPoly(pc);
			DestroyPoly(pc);
			continue;
		}
		if (flag == 3){
			pd = SubtractPoly(pa, pb);
			printf("多项式a-b：");
			PrintPoly(pd);
			DestroyPoly(pd);
			continue;
		}
		if (flag == 4)
			break;
		if (flag<1 || flag>4)
			printf("输入错误，请重新输入!\n");
		continue;
	}
	DestroyPoly(pa);
	DestroyPoly(pb);
	system("pause");
	return 0;
}
