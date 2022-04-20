#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

typedef struct elem {
	int coef;
	int exp;
	elem* next = NULL;
} elem;

elem getexs(int index) {
	int length = 0;
	cout << "第" << index << "个多项式的个数:";
	cin >> length;
	elem* temp = new elem;
	elem* temp_1 = temp;
	for (int i = 0; i < length; i++) {
		int coef;
		int exp;
		cout << "第" << i + 1 << "项的系数:";
		cin >> coef;
		cout << "第" << i + 1 << "项的指数:";
		cin >> exp;
		elem* n = new elem;
		n->coef = coef;
		n->exp = exp;
		temp_1->next = n;
		temp_1 = n;

	}


	return *temp;
}

void printexs(elem value) {
	elem* temp = value.next;
	int target = 1;
	while (target == 1) {
		cout << temp->coef << "X^" << temp->exp;

		if (temp->next == NULL) break;
		temp = temp->next;

		cout << "+";
	}
}


void Add(elem A, elem B) {
	elem* pre = &A;
	elem* qre = &B;
	elem* p = pre->next;
	elem* q = qre->next;

	while (p != NULL && q != NULL) {

		if (p->exp < q->exp) {
			pre = p;
			p = p->next;
		}
		else if (p->exp > q->exp) {
			elem* v = q->next;
			pre->next = q;
			q->next = p;
			q = v;
		}
		else {
			p->coef = p->coef + q->coef;
			if (p->coef == 0) {
				pre->next = p->next;
				delete p;
				p = pre->next;
			}
			else {
				pre = p;
				p = p->next;
			}
			qre->next = q->next;
			delete q;
			q = qre->next;
		}
	}

	if (q != NULL)pre->next = q;

	cout << "和为:" << endl;
	printexs(A);
}


int main() {
	elem a = getexs(1);
	printexs(a);
	cout << "" << endl;
	elem b = getexs(2);
	printexs(b);
	cout << "" << endl;
	Add(a, b);
	return 0;
}