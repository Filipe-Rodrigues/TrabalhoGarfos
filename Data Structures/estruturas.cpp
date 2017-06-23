#include "estruturas.hpp"

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////    Implementação da Excessão    ////////////////////////////

DataStructureException::DataStructureException (const char* message) {
	this -> message = message;
}

const char* DataStructureException::what () {
	return message;
}

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////      Implementação da Pilha     ////////////////////////////

Stack::Node::Node (int data, Node* next) {
	this -> data = data;
	this -> next = next;
}

Stack::~Stack () {
	empty();
}

void Stack::empty () {
	while (top != NULL) {
		Node* aux = top;
		top = top -> next;
		delete aux;
	}
}

void Stack::push (int element) {
	if (top == NULL) {
		top = new Stack::Node (element, NULL);
	} else {
		Node* aux = top;
		top = new Stack::Node (element, aux);
	}
	stackSize++;
}

int Stack::pop () {
	if (top == NULL) {
		throw DataStructureException ("A pilha está VAZIA! Não insista!");
	}
	int element = top -> data;
	Node* aux = top;
	top = top -> next;
	delete aux;
	stackSize--;
	return element;
}

string Stack::toString (int value) {
	ostringstream ss;
	ss << value;
	return ss.str();
}

string Stack::roam () {
	string result;
	if (stackSize == 0) {
		result = "Pilha vazia!";
	} else {
		Node* aux = top;
		result = "TOPO";
		while (aux != NULL) {
			result += " |> " + toString(aux -> data);
			aux = aux -> next;
		}
		result += " |> BASE";
	}
	return result;
}

Stack& Stack::operator << (const int& rhs) {
	push(rhs);
	return *this;
}

Stack& Stack::operator >> (int& rhs) {
	rhs = pop();
	return *this;
}

Stack& Stack::operator >> (string& rhs) {
	rhs = roam();
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////////