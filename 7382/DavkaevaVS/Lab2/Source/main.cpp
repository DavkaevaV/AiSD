#include <iostream>
#include <cstdlib>
#include "l_interfc.h"

namespace h_list
{
	lisp head (const lisp s){    // s isn't null
		if (s != NULL) 
			if (!isAtom(s))	
				return s->node.pair.hd;
			else{
				std::cerr << "Error: Head is atom \n";
				exit(1); 
			}
		else{ 
			std::cerr << "Error: Head is null \n";
			exit(1);
		}
	}
	
	bool isAtom (const lisp s){	
		if(s == NULL) 
			return false;
		else 
			return (s -> tag);
	}

	bool isNull (const lisp s){ 
		return s==NULL;
	}

	lisp tail (const lisp s){    // s isn't null
		if (s != NULL) 
			if (!isAtom(s))	
				return s->node.pair.tl;
			else{
				std::cerr << "Error: Tail is atom \n";
				exit(1);
			}
		else{
			std::cerr << "Error: Tail is null \n";
			exit(1);
		}
	}

	lisp cons (const lisp h, const lisp t){  
	lisp p;
	if (isAtom(t)){   
		std::cerr << "Error: Tail is null) \n";
		exit(1);
	}
	else{	
		p = new s_expr; 
		if ( p == NULL){
			std::cerr << "Memory not enough\n";
			exit(1);
		} 	
		else {
			p->tag = false;
			p->node.pair.hd = h;
			p->node.pair.tl = t;
			return p;	
		}
	}
	}

	lisp make_atom (const base x){
		lisp s;
		s = new s_expr;
		s -> tag = true;
		s->node.atom = x;
		return s;
	}


	void destroy (lisp s){
	if ( s != NULL) {
		if (!isAtom(s)) {
			destroy ( head (s));
			destroy ( tail(s));
		}
		delete s;
		// s = NULL;
	}
}

	base getAtom (const lisp s){
		if (!isAtom(s)){ 
			std::cerr << "Error: getAtom(s) for !isAtom(s) \n";
			exit(1);
		}
		else 
			return (s->node.atom);
	}

	
	void read_lisp ( lisp& y){	// enter list from console

		base x;
		do{
			std::cin >> x;
		}while (x==' ');
		read_s_expr ( x, y);
	} //end read_lisp

	void read_s_expr (base prev, lisp& y){    //prev - early read character
		if ( prev == ')' ) {
			std::cerr << "Error! prev = ')', it's impossible " << std::endl;
			exit(1);
		} 
		else if ( prev != '(' ) {
			y = make_atom (prev);
		}
		else{ 
			read_seq (y);
		}
	} //end read_s_expr

	void read_seq ( lisp& y) 
	{	base x; 
		lisp p1, p2;

		if (!(std::cin >> x)){
			std::cerr << " Error! x wasn't read " << std::endl;
			exit(1);
		}
		else {
			while( x==' ' ) 
				std::cin >> x;
			if ( x == ')' ){ 
				y = NULL;
			}
			else {
				read_s_expr ( x, p1);
				read_seq ( p2);
				y = cons (p1, p2);
			} 
		}
	} //end read_seq


	void write_lisp (const lisp x){		//a list with brackets framing
	if (isNull(x)) 
		std::cout << " ()";// if list is empty write '()'
	else if (isAtom(x)) 
		std::cout << ' ' << x->node.atom;
	else  { //non-empty list
			std::cout << " (" ;
			write_seq(x);
			std::cout << " )";
		}
	} // end write_lisp

void write_seq (const lisp x)  {	//sequence of elements of the list without bracikets framing 
	if (!isNull(x)) {
		write_lisp(head (x)); 
		write_seq(tail (x));
	}
}
} // end of namespace h_list

using namespace h_list;
void printTabs (int count);
void deleteHead (lisp s_cur, lisp tmpAtom);
void deleteTail (lisp s_cur, lisp tmpAtom);
void throwing_pointers (lisp s_cur, lisp s_prev);
void deleteAtom (lisp s_prev, lisp s_cur, base element, int flag, int count);// delete function

int main(){
	
	lisp s_prev, s_cur, fict_head;// s_prev - pointer on Atom ; fict_head - pointer on fictitious head for delete the true head of list; s_cur - poinet on true list
	base element;
	std::cout << std::boolalpha;
	std::cout << "Enter list:" << std::endl;
	read_lisp (s_cur);
	
	std::cout << "Entered list: " << std::endl;
	write_lisp (s_cur);
	std::cout << std::endl;
	
	s_prev = make_atom('S');//atom creation
	fict_head = cons(s_prev, s_cur);//merging the list with a fictitious head
	
	std::cout << "Enter atom that you want to delete" << std::endl;
	std::cin >> element;
	
	deleteAtom(fict_head, s_cur, element, 0, 0);
	
	std::cout << "destroy list: " << std::endl;
	write_lisp(tail(fict_head));
	destroy (fict_head);
	
	std::cout << std::endl << "end of programm " << std::endl;
	return 0;
}                                                     
void deleteTail(lisp s_cur, lisp tmpAtom){            
	tmpAtom = head(s_cur);                           
	s_cur -> node.pair.hd = NULL;                     
	delete tmpAtom;                                   
}                                                     
                                                     
void deleteHead(lisp s_cur, lisp tmpAtom){            
	tmpAtom = head(s_cur);                                  
	s_cur -> node.pair.hd = NULL;                     
	delete tmpAtom;                                   
}                                                     

void printTabs(int count){                            //show recursion
	for(int i = 0; i < count; i++)
		std::cout << '\t';
}

void deleteAtom(lisp s_prev, lisp s_cur, base element, int flag, int count){//s_prev - pointer on previous element of list
	printTabs(count);                                                       //s_cur - pointer on current element of list
	std::cout << "call deleteAtom" << std::endl;
	count++;
	if(s_cur == NULL)
		return;
	lisp tmpAtom = NULL; //variable to store an atom
	while(s_cur!= NULL)
	{
		if(isAtom(head(s_cur)))//if head is atom 
		{
			if(getAtom(head(s_cur)) == element)  //check atom 
			{	
				if(isAtom(head(s_prev)) || (flag==1))
				{
					if(tail(s_cur) == NULL)//to delete the tail of list
					{
						deleteTail(s_cur, tmpAtom);
						s_prev -> node.pair.tl = NULL;
						delete s_cur;
						s_cur = NULL;
					}
					else                  //to delete the any correct element expect tail
					{
						deleteTail(s_cur, tmpAtom);
						s_prev -> node.pair.tl = s_cur -> node.pair.tl;
						tmpAtom = s_cur -> node.pair.tl;
						delete s_cur;
						s_cur = tmpAtom;						
					}	
				}
				else
				{
					flag = 1;
					if(tail(s_cur) == NULL)//to delete the tail of list on next level
					{
						deleteHead(s_cur, tmpAtom);
						s_prev -> node.pair.hd = NULL;
						delete s_cur;
						s_cur = NULL;
					}
					else
					{
						deleteHead(s_cur, tmpAtom);
						tmpAtom = tail(s_cur);
						s_prev -> node.pair.hd = tmpAtom;
						delete s_cur;
						s_cur = tmpAtom;
					}
				}
			}
			else{                          //throwing pointers to move through the list
				s_prev = s_cur;
				s_cur = s_cur -> node.pair.tl;
			}
		}
		else if(!isAtom(head(s_cur))){     //call deleteAtom for next level
			flag = 0;
			deleteAtom(s_cur, s_cur->node.pair.hd, element, flag, count);
			flag = 1;
			s_prev = s_cur;
			s_cur = s_cur->node.pair.tl;
		}
	}
	printTabs(count-1);
	std::cout << "return deleteAtom" <<std::endl;
}
