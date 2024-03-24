#pragma once
#include <QPainter>
#include <QPoint>

class Body
{
private:

	struct BodyPart
	{
		QPoint position;
		BodyPart* next;
		BodyPart* previous;

		BodyPart(QPoint const& pos, BodyPart* next = nullptr, BodyPart* previous = nullptr)
			: position{ pos }
			, next{ next }
			, previous{ previous }
		{}
		~BodyPart() = default;
	};

public:

	class Iterator
	{
	public:
		Iterator() : Iterator(nullptr) {}
		Iterator(BodyPart* refBodyPart) : mRefBodyPart{ refBodyPart } {}
		Iterator(Iterator const&) = default;
		Iterator& operator=(Iterator const&) = default;
		~Iterator() = default;

		Iterator& operator++() { // pre-incrementation
			if (mRefBodyPart) {
				mRefBodyPart = mRefBodyPart->next;
			}
			return *this;
		}

		Iterator operator++(int) { // post-incrementation
			Iterator temp(*this);
			++(*this);
			return temp;
		}

		Iterator& operator--() { // pre-decrementation
			if (mRefBodyPart) {
				mRefBodyPart = mRefBodyPart->previous;
			}
			return *this;
		}

		QPoint& operator*() { return mRefBodyPart->position; }
		QPoint* operator->() { return &mRefBodyPart->position; }

		bool operator==(Iterator const& other) const {
			return mRefBodyPart == other.mRefBodyPart;
		}
		bool operator!=(Iterator const& other) const {
			return !operator==(other);
		}
	private:

		BodyPart* mRefBodyPart;
	};

	Body();
	Body(QPoint initPos);
	~Body();
	bool isEmpty() const;
	size_t size() const;
	QPoint* first() const;
	QPoint* last() const;
	void addFirst(QPoint position);
	void addLast(QPoint position);
	void add(size_t index, QPoint position);
	void removeFirst();
	void removeLast();
	void remove(size_t index);
	void clear();
	void swap(size_t index0, size_t index1);
	void swap(Body& otherBody);
	void rotate(int indexFrom);
	bool isColliding(QPoint const& position) const;
	void draw(QPainter& painter);

	Iterator begin() { return Iterator(mHead); }
	Iterator end() { return Iterator(); }

private:
	size_t mSize;
	BodyPart* mHead;
	BodyPart* mTail;

};