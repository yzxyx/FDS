

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
	void erase(T data) {
		CNode<T>* temp1, *temp2;
		temp1 = this->proot;
		temp2 = this->proot;
		while (temp1 != 0) {
		    if (temp1->getData() == data) {
			std::cout << temp1->getData() << "  == " << data    << " they are equal ";
			    if (temp1 == this->proot) {
				    std::cout << "data " << temp1->getData()
						    << " is equal and is root" << std::endl;
				    temp2 = temp1->getLink(LINKS::next);
				    this->proot = temp2;
				    delete temp1;
				    temp1 = this->proot;
			    }
			    else {
				    if (temp1->getLink(LINKS::next) != 0) {
					    temp2->setLink(LINKS::next,   temp1->getLink(LINKS::next));
					    delete temp1;
					    temp1 = temp2->getLink(LINKS::next);
				    } else {
					    std::cout<<"is a final node ";
					    temp2->setLink(LINKS::next, 0);
					    delete temp1;
					    temp1=0;
				    }
			    }
			    if (temp2!=0) std::cout << "temp2 =" << temp2->getData() ;
		            else std::cout << "temp2 = 0" ;
			    if(temp1!=0) std::cout<< " temp1= "  << temp1->getData() << std::endl;
			    else std::cout<< " temp1= 0" << std::endl;
		    }
		    else {
			temp2 = temp1;
			temp1 = temp1->getLink(LINKS::next);
			 if (temp2!=0) std::cout << "temp2 =" << temp2->getData() ;
			 else std::cout << "temp2 = 0" ;
			 if(temp1!=0) std::cout<< " temp1= "  << temp1->getData() << std::endl;
			 else std::cout<< " temp1= 0" << std::endl;
		    }
	    }
	}
	bool search(T data) 
	{
		if (this->proot == 0) return false;
		 else {
			CNode<T> *temp = this->proot;
			while (temp->getLink(LINKS::next) != 0 ) 
			{
				if (temp->getData() == data) return true;
				temp = temp->getLink(LINKS::next);
			}
				return false;
			}
				
	}
	void clear() 
	{
			CNode<T> *temp = this->proot;
			while (temp) 
			{
				free(temp);
				temp = temp->getLink(LINKS::next);
			}
			
	}
	void show(std::ostream& out) {
		CNode<T> * temp = this->proot;
		while (temp->getLink(LINKS::next) != 0) {
			out << temp->getData() << " -- "; 
			temp = temp->getLink(LINKS::next);
		}
		out << temp->getData() << std::endl;
	}
};

#endif /* CLISTCIRCULAR_H_ */
