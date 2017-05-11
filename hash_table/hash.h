#include "syntax.h"
class element {
public:
    int argc;
    NTL::ZZ *argv;
    element &operator=(const element &np);
    element():argc(0), argv(NULL){} 
    virtual ~element();
	    
    // element operator=(const element &np) const;
private:
    /* so what? */
};


/**
 * class hash: lonely hash table.
 *  function:
 *	pop();
 *	push();
 *	search();
 *  
 *	note: fixed size: 10071 elements;(temporarily define)
 *	
 */
class hash {
public:
    hash ();
    virtual ~hash ();
    
   /* public function */
    element *pop();
    int push (element  &tmp);
    element *search(int key);
    element *search(std::string val);

private:
    // hashing function 
   int hashing(int arg); 
};
