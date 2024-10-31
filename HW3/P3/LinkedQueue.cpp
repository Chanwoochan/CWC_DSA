/*
	큐: 알고리즘 구현(C++) -- 단순연결리스트
		파일명: LinkedQueue.cpp
			- 스택 생성.소멸	: LinkedQueue, ~LinkedQueue
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: front, back
			- 전체 데이터 출력	: printQueue
*/

#include <iostream>
#include "LinkedNode(template).cpp"		// SNode
using namespace std;

// #pragma once
#ifndef __LinkedQueue_Template_H__
#define __LinkedQueue_Template_H__

// 클래스 설계: LinkedQueue
template <typename T>
class LinkedQueue {
public:
	LinkedQueue();				// 빈 큐 생성
	~LinkedQueue();				// 큐 삭제: 모든 노드 삭제
	bool	empty(void) const;		// 빈 큐 여부
	int	size(void) const;		// 큐의 원소 개수
	void	push(const T& data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	front(void) const;		// 첫번째 노드의 데이터 반환
	T	back(void) const;		// 마지막 노드의 데이터 반환
	void	printQueue(void) const;		// 큐의 전체 데이터 출력
private:
	SNode<T>* front_;		// 첫번째 노드
	SNode<T>* rear_;			// 마지막 노드
	int		count_;			// 큐의 원소 개수
};

template <typename T>
LinkedQueue<T>::LinkedQueue():front_(nullptr), rear_(nullptr), count_(0) {}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	SNode<T>* dNode = front_;
	while (dNode)
	{
		front_ = front_->link_;
		delete dNode;
		dNode = front_;
	}
}

template <typename T>
bool LinkedQueue<T>::empty(void) const
{
	return front_ == nullptr;
}
template <typename T>
int LinkedQueue<T>::size(void) const
{
	return count_;
}

template <typename T>
void LinkedQueue<T>::push(const T& data)
{
	SNode<T>* newNode = new SNode<T>(data);
	if (empty())
	{
		front_ = newNode;
		rear_ = newNode;
	}
	else
	{
		rear_->link_ = newNode;
		rear_ = rear_->link_;
	}
	++count_;
}

template <typename T>
void LinkedQueue<T>::pop(void)
{
	if (empty())
		return;
	SNode<T>* old = front_;
	front_ = old->link_;
	if (!front_)
		rear_ = nullptr;
	delete old;
	--count_;
}

template <typename T>
T LinkedQueue<T>::front(void) const
{
	return front_->getData();
}

template <typename T>
T LinkedQueue<T>::back(void) const
{
	return rear_->getData();
}

template <typename T>
void LinkedQueue<T>::printQueue(void) const
{
	SNode<T>* tNode = front_;
	cout << "QUEUE [ ";
	while (tNode)
	{
		cout << tNode->getData() << " ";
		tNode = tNode->link_;
	}
	cout << "]\n";
}

#endif
