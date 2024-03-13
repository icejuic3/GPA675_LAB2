#include "Body.h"

Body::Body()
	: mHead{}
	, mTail{}
	, mSize{ 0 }
{
	QPoint initPos = QPoint(0, 0);
	addFirst(initPos);
	mTail = nullptr;
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
	if (index > mSize) {
		return;
	}
	if (index == 1) {
		addFirst(position);
		return;
	}
	if (index == mSize) {
		addLast(position);
		return;
	}

	BodyPart* next{ nullptr };
	if (index < mSize / 2) {
		next = mHead;
		for (size_t i{}; i < index; ++i) {
			++next;
		}
	}
	else {
		next = mTail;
		for (size_t i{}; i < mSize - (index + 1); ++i) {
			--next;
		}
	}
	BodyPart* previous = next->previous;		// a verfifier si removed se decremente lui-meme
	BodyPart* added = new BodyPart(position, previous, next);
	next->previous = added;
	previous->next = added;
	++mSize;
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
		removeFirst();
		return;
	}
	if (index == mSize) {
		removeLast();
		return;
	}

	BodyPart* removed{ nullptr };

	if (index < mSize / 2) {
		removed = mHead;
		for (size_t i{}; i < index; ++i) {
			++removed;
		}
	}
	else {
		removed = mTail;
		for (size_t i{}; i < mSize - (index + 1); ++i) {
			--removed;
		}
	}
	BodyPart* previous = removed->previous;
	BodyPart* next = previous->next;
	previous->next = next;
	next->previous = previous;
	removed->next = nullptr;
	removed->previous = nullptr;
	delete removed;								// verifier s'il delete tout le reste apres
}

void Body::clear()
{
	delete mHead;
	mHead = nullptr;
	mTail = nullptr;
	mSize = 0ull;
}

void Body::swap(size_t index0, size_t index1)
{
	BodyPart* firstIndex = nullptr;
	BodyPart* secondIndex = nullptr;
	if (index0 < mSize / 2) {
		firstIndex = mHead;
		for (size_t i{}; i < index0; ++i) {
			++firstIndex;
		}
	}
	else {
		firstIndex = mTail;
		for (size_t i{}; i < mSize - (index0 + 1); ++i) {
			--firstIndex;
		}
	}
	if (index1 < mSize / 2) {
		secondIndex = mHead;
		for (size_t i{}; i < index1; ++i) {
			++secondIndex;
		}
	}
	else {
		secondIndex = mTail;
		for (size_t i{}; i < mSize - (index1 + 1); ++i) {
			--secondIndex;
		}
	}
	std::swap(firstIndex->previous, secondIndex->previous);
	std::swap(firstIndex->next, secondIndex->next);
	std::swap(firstIndex->position, secondIndex->position);
}

void Body::swap(Body& otherBody)
{
	std::swap(mHead, otherBody.mHead);
	std::swap(mSize, otherBody.mSize);
}

void Body::rotate(int indexFrom)
{
	BodyPart* newHead = nullptr;
	if (indexFrom < mSize / 2) {
		newHead = mHead;
		for (size_t i{}; i < indexFrom; ++i) {
			++newHead;
		}
	}
	else {
		newHead = mTail;
		for (size_t i{}; i < mSize - (indexFrom + 1); ++i) {
			--newHead;
		}
	}
	BodyPart* newTail = newHead->previous;
	mHead->previous = mTail;
	newTail->next = nullptr;
	newHead->previous = nullptr;
	mTail->next = mHead;
	mHead = newHead;
	mTail = newTail;
}

bool Body::isColliding(QPoint const& position) const
{
	return false;
}

void Body::draw(QPainter& painter)
{
	painter.setPen(Qt::NoPen);
}