/*
<<������ 2>>
����������� ����������� ������ � �����������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>                    // ����� ����� - ������
#include <clocale>                     // ����������� ��� ������������ �������

using namespace std;

struct node
{
	int data;                          // �������� ������ (����)
	node* prev;                        // ��������� �� ���������� �������
	node* next;						   // ��������� �� ��������� �������
};

struct list
{
	int size;                           // ���������� ��������� � ������
	node* up;                           // ��������� �� ������ �������
	node* down;                         // ��������� �� ��������� �������
};

void push_back(list *L);                // �������� ������� "���������� �������� � �����"
int pop_back(list *L);                  // �������� ������� "�������� �������� �� �����"
void push_front(list *L);               // �������� ������� "���������� �������� � ������"
int pop_front(list *L);                 // �������� ������� "�������� �������� �� ������"
void step_by_step(list *L);             // �������� �������, ���������� ��� �������� ����
void insert(list *L);					// �������� ������� "������� � ����� ����� ������"
void output(list *L);					// �������� ������� "����� ������������ ������"
void sort(list *L);

int main()
{
	setlocale(LC_ALL, "Rus");           // ������� ��� ����� �������� �����
	list List;                          // ����� c����� 
	List.size = 0;                      // ���������� ��������� ���� ��� �������
	List.up = NULL;                     // ��������� �������
	List.down = NULL;					// ��������� ����
	step_by_step(&List);
	system("pause");
	return 0;
}

void step_by_step(list *L)
{
	int n;
	cout << "������� ���������� ��������� � ������: ";
	cin >> n;
	cout << "���������� �������� � ������: " << endl;
	for (int i = 0; i < n; i++)
	{
		push_back(L);
		push_front(L);
	}
}

void push_front(list *L)				// ������� ��� ���������� �������� � ������
{
	int value;							// �������� �������� ����������
	cin >> value;						// ���� ����������
	node* value_pointer = new node;		// ��������� ������ ��� ����� ������ � ������
	value_pointer->data = value;		// ��������� ���������� �����
	value_pointer->prev = L->up;		// ����� ���������� ������ = ����� �������(������)
	L->up = value_pointer;				// ��������� ������ ��� ������� ��������, ������� ������ ��������(�����)
	L->size++;							// ���������� ��������� � ������ ����� ���������� ������
}

int pop_front(list *L)					// ������� ��� �������� �������� �� ������
{
	int value_temp = 0;					// ��������� ���������� ��� �������� �������(������)
	node *value_pointer;				// ��������� �� ���������, ������� ������
	value_pointer = L->up;				// ����� �������(������) �������������� � ��������� 
	value_temp = L->up->data;			// � ����. �������� �������� �������� ������� �� ������ �������(������)
	L->up = value_pointer->prev;		// ��������. ������� ������ ��������(�����)
	delete value_pointer;				// ����������� ������ � ������� ��������� �������(������)
	L->size--;							// ���������� ��������� � ������ ����� �������� �������
	return value_temp;					// ���������� �������� �������(������)
}

void push_back(list *L)
{
	int value;							// �������� �������� ����������
	cin >> value;						// ���� ����������
	node* value_pointer = new node;		// ��������� ������ ��� ����� ������ � ������
	value_pointer->data = value;		// ��������� ���������� �����
	value_pointer->next = L->down;		// ����� �������. ������ = ����� ����(�������)
	L->down = value_pointer;			// ��������� ������ ��� ���������� ��������, ������� ������ �����(�����)
	L->size++;							// ���������� ��������� � ������ ����� ���������� ������
}

int pop_back(list *L)
{
	int value_temp = 0;					// ��������� ���������� ��� �������� ����(�������)
	node *value_pointer;				// ��������� �� ���������, ������� ������
	value_pointer = L->down;			// ����� ����(�������) �������������� � ��������� 
	value_temp = L->down->data;			// � ����. �������� �������� �������� ���� �� ������ ����(�������)
	L->down = value_pointer->next;		// ��������� ������� ������ �����(�����)
	delete value_pointer;				// ����������� ������ � ������� ��������� ���(������)
	L->size--;							// ���������� ��������� � ������ ����� �������� �������
	return value_temp;					// ���������� �������� ����(�������)
}

void insert(list *L)
{
	//
}

void output(list *L)
{
	//
} 

void sort(list *L)
{
	//
}