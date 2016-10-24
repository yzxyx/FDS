

#ifndef CLISTCIRCULAR_H_
#define CLISTCIRCULAR_H_

#include "CList.h"

template<class T>
class CListCircular: public CList<T> {
public:
	CListCircular() {
		this->proot = 0;
	}
	~CListCircular() {

	}
	void insert(T dato) {
		CSimpleNode<T> * _new = new CSimpleNode<T>(dato);
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
		CSimpleNode<T> * _new = new CSimpleNode<T>(dato);
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

#endif /* CLISTCIRCULAR_H_ */
