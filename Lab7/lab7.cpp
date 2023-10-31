#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


template<typename T>
class BSTNode {

public:
	// Constructors, etc.
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
	BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
	BSTNode& operator= (BSTNode&); // copy assignment operator
	
	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);
	
	// Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }

	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;

    //
    void listify(list<T>&) const;
	
	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
		{ b.preOrderDisplay(out); return out; }
	
private:
	T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
	
	// private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
//	cout << "BSTNode<T>::insert called with data == " << data << endl;

	auto ptr = new BSTNode<T>(data);
    if(data < this->_data){
        if(_left == nullptr){
            _left = ptr;
        }else{
            _left->insert(data);
        }
    }else{
        if(_right == nullptr){
            _right = ptr;
        }else{
            _right->insert(data);
        }
    }
}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
	if (_left != nullptr) {
	    _left->inOrderDisplay(out);
	    out << ", ";
	}
	out << _data;
	if (_right != nullptr) {
	    out << ", ";
	    _right->inOrderDisplay(out);
	}
}


template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	out << _data;
	if (_left != nullptr) {
		out << ", ";
		_left->preOrderDisplay(out);
	}
	if (_right != nullptr) {
		out << ", ";
		_right->preOrderDisplay(out);
	}
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
//	cout << "BSTNode<T>::postOrderDisplay called\n";
    if (_left != nullptr) {
        _left->postOrderDisplay(out);
        out << ", ";
    }
    if (_right != nullptr) {
        _right->postOrderDisplay(out);
        out << ", ";
    }
    out << _data;
}

template <typename T>
void BSTNode<T>::listify(list<T> & rootList) const {
    if (_left != nullptr) {
        _left->listify(rootList);
    }
    rootList.push_back(_data);
    if (_right != nullptr) {
        _right->listify(rootList);
    }
}

int main(void) {
    BSTNode<int> iroot(100);
    iroot.insert(10);
    iroot.insert(20);
    iroot.insert(200);
    iroot.insert(300);
    cout << "iroot == " << iroot << endl;
    list<int> irootList;
    iroot.listify(irootList);
    // forward iterator
    for (auto li = irootList.begin(); li != irootList.end(); li++) {
        cout << *li << " ";
    }
    cout << endl;
    // reverse iterator
    for (auto li = irootList.rbegin(); li != irootList.rend(); li++) {
        cout << *li << " ";
    }
    cout << endl;
    // ranged for loop
    for (auto num: irootList) {
        cout << num << " ";
    }
    cout << endl;

    BSTNode<string> sroot("Sunday");
    sroot.insert("Monday");
    sroot.insert("Tuesday");
    sroot.insert("Wednesday");
    sroot.insert("Thursday");
    sroot.insert("Friday");
    sroot.insert("Saturday");
    cout << "sroot == " << sroot << endl;
    list<string> srootList;
    sroot.listify(srootList);
    for (auto li = srootList.begin(); li != srootList.end(); li++) {
        cout << *li << " ";
    }
    cout << endl;
    // reverse iterator
    for (auto li = srootList.rbegin(); li != srootList.rend(); li++) {
        cout << *li << " ";
    }
    cout << endl;
    // ranged for loop
    for (auto num: srootList) {
        cout << num << " ";
    }
    cout << endl;
    BSTNode<int> iroot4(1000);
    iroot4.insert(2000);
    iroot4.insert(3000);
    iroot4.insert(4000);
    iroot4.insert(5000);
    list<int> iroot4List;
    iroot4.listify(iroot4List);
    map<string, list<int>> mi;
    mi.insert(make_pair("irootList", irootList));
    mi.insert(make_pair("iroot4List", iroot4List));
    for(const auto& [str,list]: mi){
        cout << str << ":";
        for(auto item: list){
            cout << " " << item;
        }
        cout << endl;
    }

#ifdef debug
>>>>>>> origin/dev
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;
	
	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;
  #endif
	
	return 0;
}
