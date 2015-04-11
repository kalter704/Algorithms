#include <iostream>

const unsigned int SIZE_STACK = 7;

struct DStack_L {
	private:
		char* mas;
		int top, sizeBuffer;
		bool isFull();
		bool isEmpty();
		void increaseStack();
	public:
		DStack_L(int n): top(-1), sizeBuffer(n) {
			mas = new char[sizeBuffer];
		}
		~DStack_L() {
			delete[] mas;
		}
		void push(int n);
		int pop();
};

bool DStack_L::isFull() {
	return (top == (sizeBuffer - 1));
}

bool DStack_L::isEmpty() {
	return (top == -1);
}

void DStack_L::increaseStack() {
	int lastSize = sizeBuffer;
	sizeBuffer *= 2;
	char* temp = new char[sizeBuffer];
	int count = 0;
	while(count <= top){
		temp[count] = mas[count];
		count++;
	}
	delete[] mas;
	mas = temp;
}

void DStack_L::push(int n) {
	if( isFull() == true ) { increaseStack(); }
	mas[++top] = n;
}

int DStack_L::pop() {
	if( isEmpty() == true) { return '\n'; }
	else { return mas[top--]; }
}

bool fillingStack(DStack_L &stackL, DStack_L &stackSec) { // «аполнение стека и проверка на правильность рассположени€ скобок
	bool possible = true;
	char ch,
		 temp;
  ch = std::cin.get();
	//while(((ch = getchar()) != '\n') && (possible == true)) {
	while((ch != '\n') && (possible == true)) {
		switch(ch) {
			case '{':
				stackL.push(ch);
				stackSec.push(ch);
				break;
			case '(':
				stackL.push(ch);
				stackSec.push(ch);
				break;
			case '[':
				stackL.push(ch);
				stackSec.push(ch);
				break;
			case '}':
				temp = stackSec.pop();
				if((temp == ']') || (temp == ')') || (temp == '}')) {
					stackL.push(ch);
					stackSec.push(temp);
					stackSec.push(ch);
				} else {
					if(temp == '\n'){
						stackL.push(ch);
						stackSec.push(ch);
					} else {
						if(temp == '{') {
							stackL.push(ch);
						} else {
							possible = false;
						}
					}
				}
				break;
			case ')':
				temp = stackSec.pop();
				if((temp == ']') || (temp == ')') || (temp == '}')) {
					stackL.push(ch);
					stackSec.push(temp);
					stackSec.push(ch);
				} else {
					if(temp == '\n'){
						stackL.push(ch);
						stackSec.push(ch);
					} else {
						if(temp == '(') {
							stackL.push(ch);
						} else {
							possible = false;
						}
					}
				}
				break;
			case ']':
				temp = stackSec.pop();
				if((temp == ']') || (temp == ')') || (temp == '}')) {
					stackL.push(ch);
					stackSec.push(temp);
					stackSec.push(ch);
				} else {
					if(temp == '\n'){
						stackL.push(ch);
						stackSec.push(ch);
					} else {
						if(temp == '[') {
							stackL.push(ch);
						} else {
							possible = false;
						}
					}
				}
				break;
		}
		ch = std::cin.get();
	}
	return possible;
}

void addStack(DStack_L &stackL, DStack_L &stackSec) {		//ƒобавление скобок
	DStack_L stackTemp(SIZE_STACK);
	char ch = stackSec.pop();
	while((ch != '\n') && (ch != ')') && (ch != '}') && (ch != ']')) {
		switch(ch) {
			case '(':
				stackL.push(')');
				break;
			case '[':
				stackL.push(']');
				break;
			case '{':
				stackL.push('}');
				break;
		}
		ch = stackSec.pop();
	}
	char ch2 = stackL.pop();
	while(ch2 != '\n') {
		stackTemp.push(ch2);
		ch2 = stackL.pop();
	}
	stackL.push(ch);
	ch = stackSec.pop();
	while(ch != '\n') {
		stackL.push(ch);
		ch = stackSec.pop();
	}
	ch = stackL.pop();
	while(ch != '\n') {
		switch(ch) {
			case ')':
				stackTemp.push('(');
				break;
			case ']':
				stackTemp.push('[');
				break;
			case '}':
				stackTemp.push('{');
				break;
		}
		ch = stackL.pop();
	}
	ch = stackTemp.pop();
	while(ch != '\n') {
		stackSec.push(ch);
		ch = stackTemp.pop();
	}
	ch = stackSec.pop();
	while(ch != '\n') {
		stackL.push(ch);
		ch = stackSec.pop();
	}
}

int main() {
	DStack_L stackL(SIZE_STACK),
			 stackSec(SIZE_STACK);
	if(fillingStack(stackL, stackSec) == false) {
		std::cout << "IMPOSSIBLE";
		return 0;
	}
	addStack(stackL, stackSec);
	char ch;
	while((ch = stackL.pop()) != '\n') {
		std::cout << ch;
	}
	return 0;
}
