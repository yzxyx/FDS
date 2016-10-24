
#ifndef CLISTDOUBLE_H_
#define CLISTDOUBLE_H_

#include "CList.h"

template<class T>
class CListDouble: public CList<T> {
public:
	CListDouble() {
		this->proot = 0;
	}
	~CListDouble() {

	}
	void insert(T dato) {
		CDoubleNode<T> * _new = new CDoubleNode<T>(dato);
		if (this->proot == 0) {
			this->proot = _new;

		} else {
			CNode<T> *temp = this->proot;
			while (temp->getLink(LINKS::next) != 0) {
				temp = temp->getLink(LINKS::next);
			}
			temp->setLink(LINKS::next, _new);
		}
	}
	void erase(T dato) {
		CDoubleNode<T> * _new = new CDoubleNode<T>(dato);
		if (this->proot == 0) {
			return;

		} else {
			CNode<T> *temp = this->proot;
			while (temp->getLink(LINKS::next) != 0) {
				temp = temp->getLink(LINKS::next);
			}
			delete(temp);
		}
	}
	bool search(T) {

	}
	void clear() {

	}
	void show(std::ostream& out) {
		CNode<T> * temp = this->proot;
		while (temp->getLink(LINKS::next) != 0) {
			out << temp->getData(); 
			temp = temp->getLink(LINKS::next);
		}
		out << temp->getData();
	}
};

#endif /* CLISTDOUBLE_H_ */
