#include <iostream>
#include <cstring>

const unsigned int SIZE_STACK = 7;

const int SIZE_STRING = 150;

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
		int top_stack() {
			if( isEmpty() == true) { return '\n'; }
			else { return mas[top]; }
		}
		void push(char n);
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

void DStack_L::push(char n) {
	if( isFull() == true ) { increaseStack(); }
	mas[++top] = n;
}

int DStack_L::pop() {
	if( isEmpty() == true) { return '\n'; }
	else { return mas[top--]; }
}

bool fillingStackWithBrackets(DStack_L& stack, char* str) {
	//int i = 0;
	//while(str[i] != '\0') {
	//int size = list_str.size();
	std::list<char>::iterator iter;
	for(iter = list_str.begin(); iter != list_str.end(); ++iter) {
    char temp_char;
		//if((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {
		if((*iter == ')') || (*iter == '}') || (*iter == ']')) {
		  switch(*iter) {
			  case ')':
				  temp_char = '(';			
				  break;
			  case '}':
				  temp_char = '{';
				  break;
			  case ']':
				  temp_char = '[';
				  break;
      }
      if(stack.top_stack() == temp_char) {
        stack.pop();
      } else {
        if((stack.top_stack() == '\n') || (stack.top_stack() == ')') ||
          (stack.top_stack() == '}') || (stack.top_stack() == ']')) {
          stack.push(*iter);
        } else {
          return false;
        }
      }
	  } else {
	    stack.push(*iter);	    
	  }
	}
	return true;
}

void addBracketsToStr(std::list<char>& list_str, DStack_L& stack) {
  //int len = strlen(str);
  while((stack.top_stack() == '(') || (stack.top_stack() == '{') || (stack.top_stack() == '[')) {
    char temp_char = stack.pop();
    switch(temp_char) {
      case '(':
        //str[len++] = ')';
        list_str.push_back(')');
        break;
      case '{':
        //str[len++] = '}';
        list_str.push_back('}');
        break;
      case '[':
        //str[len++] = ']';
        list_str.push_back(']');
        break;
    }
  }
  //str[len] = '\0';
  //char temp_str[SIZE_STRING];
  //int i = 0;
  std::list<char>::iterator iter = list_str.begin();
  while(stack.top_stack() != '\n') {
	  char temp_char = stack.pop();
	  switch(temp_char) {
	    case ')':
	      list_str.insert(iter, '(');
        //temp_str[i++] = '(';
        break;
	    case '}':
	      list_str.insert(iter, '{');
		    //temp_str[i++] = '{';
        break;
      case ']':
	      list_str.insert(iter, '[');
        //temp_str[i++] = '[';
        break;
    }
  }
  //temp_str[i] = '\0';
  //strcat(temp_str, str);
  //strcpy(str, temp_str);
}

bool restorationBrackets(char* str) {
  DStack_L stack(SIZE_STACK);
  if(!fillingStackWithBrackets(stack, str)) {
    return false;
  }
  addBracketsToStr();
  return true;
}

int main() {
  int size = SIZE_STRING;
  char* str = new char[size];
	return 0;
}
