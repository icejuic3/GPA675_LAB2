#include "Body.h"

Body::Body()
	: mHead{}
	, mTail{}
	, mSize{}
{
}

Body::~Body()
{
	delete mHead;
}

bool Body::isEmpty() const
{
	return mSize == 0ull;
}

size_t Body::size() const
{
	return mSize;
}

QPoint* Body::first() const
{
	if (mSize == 0) {
		return nullptr;
	}
	else {
		return &mHead->position;
	}
}

QPoint* Body::last() const
{
	if (mSize == 0) {
		return nullptr;
	}
	else {
		return &mTail->position;
	}
}

void Body::addFirst(QPoint position)
{
	mHead = new BodyPart(position, mHead, nullptr);
	++mSize;
}

void Body::addLast(QPoint position)
{
	if (mHead == nullptr) { // la liste est vide
		addFirst(position);
	}
	else {
		mTail = new BodyPart(position, nullptr, mTail);
		++mSize;
	}
}

void Body::add(size_t index, QPoint position)
{
}

void Body::removeFirst()
{
	if (!mHead) {
		return;
	}
	BodyPart* temp{ mHead };
	mHead = mHead->next;
	temp->next = nullptr;
	delete temp;
	--mSize;
}

void Body::removeLast()
{
	if (!mTail) {
		return;
	}
	BodyPart* temp{ mTail };
	mTail = mTail->previous;
	temp->previous = nullptr;
	delete temp;
	--mSize;
	
}

void Body::remove(size_t index)
{
	if (index > mSize) {
		return;
	}
	if (index == 1) {
		removefirst();
	}
	if (index == mSize) {
		removeLast();
	}

	if (index < mSize) {
		BodyPart* removed = mHead;
		for (size_t i{}; i < index; ++i) {
			++removed;
		}	
	}
	else{
		BodyPart* removed = mTail;
		for (size_t i{}; i < mSize-index; ++i) {
			--removed;
		}
	}
	BodyPart* previous = --removed;
	BodyPart* next = ++removed;
	previous->next = next;
	next->previous = previous;
	removed->next = nullptr;
	removed->previous = nullptr;
	delete removed;
}

void Body::clear()
{
	delete mHead;
	mHead = nullptr;
	mSize = 0ull;
}

void Body::swap(size_t index0, QPoint position)
{
}

void Body::swap(Body& otherBody)
{
	std::swap(mHead, otherBody.mHead);
	std::swap(mSize, otherBody.mSize);
}

void Body::rotate(int indexFrom)
{
	if (indexFrom > mSize / 2) {
		//parcour par la fin
		BodyPart* tail{ mTail };
		for (int i{ 0 }; i < (mSize - indexFrom); ++i) {
			
		}
	}
	else {
		//parcour par le debut
	}
}

bool Body::isColliding(QPoint const& position) const
{
	return false;
}

void Body::draw(QPainter& painter)
{
	painter.setPen(Qt::NoPen);
}
