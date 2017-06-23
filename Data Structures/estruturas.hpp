#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

#include <string>
#include <sstream>
#include <exception>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////      Definição das Classes      ////////////////////////////

class DataStructureException : public std::exception {
	
	private:
		const char* message;

	public:
		DataStructureException(const char* message);
		virtual const char* what ();

};

class Stack {

	private:
		class Node {
			friend class Stack;
			private:
				int data;
				Node* next;
			public:
				Node (int data, Node* next);
		} *top;
		int stackSize;

		void empty ();
		void push (int element);
		int pop ();
		string roam ();
		string toString (int value);

	public:
		Stack () {top = NULL; stackSize = 0;}
		~Stack();
		int size ();
		Stack& operator << (const int& rhs);
		Stack& operator >> (int& rhs);
		Stack& operator >> (string& rhs);

};

/////////////////////////////////////////////////////////////////////////////////////
//////////////////// ATENÇÃO! CÓDIGO AINDA NÃO IMPLEMENTADO! ////////////////////////

class List {

	private:
		class Node {
			friend class List;
			private:
				int data;
				Node* next;
				Node* prev;
			public:
				Node (int data, Node* next, Node* prev);
		};
		Node* first;
		Node* last
		int listSize;

		void empty ();
		void insertFirst (int element);
		string roam ();
		string toString (int value);

	public:
		List () {top = NULL; stackSize = 0;}
		~List();
		int size ();
		void insertL (int element);
		void insertR (int element);
		int pull (int position);
		int peek (int position);
		List& operator >> (string& rhs);

};

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

#endif