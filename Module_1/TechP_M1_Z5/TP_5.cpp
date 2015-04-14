#include <iostream>
#include <cstring>

#define MESS(ch) 
//std::cout << ch << "!";




const unsigned int SIZE_STACK = 7;

typedef char my_type;

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

bool fillingStackWithBrackets(char* str, DStack_L& stack) {
	//char temp_str[80];
	//int temp_i = 0;
	//std::list<char>::reverse_iterator iter_end = str_list.rbegin();
	//while(iter_end != str_list.rend()) {
	//int length = strlen(str);
	int i = 0;
	//while(i < length) {
	while(str[i] != '\0') {
    char temp_char;
		//bool flag = true;
		//switch(*iter_end) {
		if((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) {
		  switch(str[i]) {
			  case ')':
				  temp_char = '(';
				  MESS('(');				
				  break;
			  case '}':
				  temp_char = '{';
				  MESS('}');
				  break;
			  case ']':
				  temp_char = '[';
				  MESS('[');
				  break;
			  /*default:
				  stack.push(*iter_end);
          stack.push(str[i]);
          flag = false;
          break;*/
      
      }
      if(stack.top_stack() == temp_char) {
        stack.pop();
      } else {
        if((stack.top_stack() == '\n') || (stack.top_stack() == ')') ||
          (stack.top_stack() == '}') || (stack.top_stack() == ']')) {
          stack.push(str[i]);
        } else {
          return false;
        }
      }
	  } else {
	    stack.push(str[i]);	    
	  }
		/*if(flag) {
			if(stack.top_stack() == '\n') {
			  temp_str[temp_i++] = temp_char;
				//str_list.push_back(temp_char);
				//iter_end++;
			} else {
				if(stack.top_stack() == temp_char) {
					stack.pop();
				} else {
					if(stack.top_stack() != temp_char) {
						return false;
					}
				}
			}
		}
		iter_end++;*/
		i++;
	}
	return true;
}

void addBracketsToStr(char* str, DStack_L& stack) {
  int len = strlen(str);
  while((stack.top_stack() == '(') || (stack.top_stack() == '{') || (stack.top_stack() == '[')) {
    char temp_char = stack.pop();
    switch(temp_char) {
      case '(':
        str[len++] = ')';
        break;
      case '{':
        str[len++] = '}';
        break;
      case '[':
        str[len++] = ']';
        break;
    }
  }///////'\0'
  str[len] = '\0';
  char temp_str[80];
  int i = 0;
  while(stack.top_stack() != '\n') {
	char temp_char = stack.pop();
	switch(temp_char) {
	  case ')':
        temp_str[i++] = '(';
        break;
	  case '}':
		  temp_str[i++] = '{';
        break;
      case ']':
        temp_str[i++] = '[';
        break;
    }
  }
  temp_str[i] = '\0';
  strcat(temp_str, str);
  strcpy(str, temp_str);
}

bool restorationBrackets(char* str) {
  DStack_L stack(SIZE_STACK);
  if(!fillingStackWithBrackets(str, stack)) {
    return false;
  }
  addBracketsToStr(str, stack);
  return true;
}

int main() {
	char str[80];
	std::cin >> str;
  //std::list<char> str_list;
	/*for(int i = 0; str[i] != '\0'; ++i) {
		str_list.push_back(str[i]);
	}*/
	/*for(int i = 0, size = str_list.size(); i < size; ++i) {
		std::cout << str_list.front() << std::endl;
		str_list.pop_front();
	}
	std::list<char>::reverse_iterator iter;
  for(iter = str_list.rbegin(); iter != str_list.rend(); iter++) {
		std::cout << *iter;
	}*/
  if(!restorationBrackets(str)){
		std::cout << "IMPOSSIBLE";
		return 0;
	}
	/*int size = str_list.size();
	for(int i = 0; i < size; ++i) {
		std::cout << str_list.front();
		str_list.pop_front();
	}
	std::cout << std::endl; */
	std::cout << str;
	return 0;
}
