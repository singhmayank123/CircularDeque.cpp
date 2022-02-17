/** This code is written in C++ and can be tested on any IDE that supports C++ 5.11 compiler versions **/

#include<iostream>
using namespace std;

typedef int Elem;
/** CircularSequence class that uses circular fashion to implement its functionalities **/
class CircularSequence{
	
	private:
		
		Elem* arr; // stores CircularSequence contents 
		int size; // stores maximum capacity of the CircularSequence
		int front; // points to the front element of the CircularSequence
		int rear; // points to the rear element of the CircularSequence 
		int elemCounts; // stores current number of elements 
	
	/** A method that doubles the size of the CircularSequence in case of overflow condition **/	
	
        void expandTheArray(){
        	
        	cout << "Extending the array......."<<endl;
        	
        	int j = 1; 
        	
        	// double the size 
        	int newSize = size * 2;
        	// create new array of double size 
        	Elem *newArr = new Elem[newSize];
        	
        	// copy the contents of old array to the new array 
	        for(int i = (front+1) % size; i != (rear+1)%size; i = (i+1) % size)
	            newArr[j++] = arr[i];
	        
			// deallocate the space for the old array    
	        delete []arr;
	        
	        // re-initialize the size 
	        size =  newSize;
	        // make a reference of old array to the new array 
	        arr = newArr;
	        
	        // set the front to 0
	        front = 0;
	        
	        // rear at j-1
	        rear = j-1;
	          	
		}
	
	
	public:
		
		// default constructor for default size of the CircularSequence 
		CircularSequence(): CircularSequence(5){}
		
		// parameterized constructor for user-defined size of the CircularSequence 
		CircularSequence(int n){
			size = n;
	        front = 0;
	        rear = 0;
	        arr = new Elem[size];
		}
		// checks whether the CircularSequence is full or not 	
		bool isFull(){
			
			if(front == ((rear + 1) % size))
            	return true;
        	return false;
		}
		
		// checks whether the CircularSequence is empty or not 
		bool isEmpty(){
			
			if(front == rear)
            	return true;
        	return false;
		}
		
		// returns the count of available elements in the CircularSequence
		int Size(){
			return size;
		}
		
		// returns the front pointer value 
		int begin(){
			return front;
		}
		
		// returns the rear pointer value 
		int end(){
			return rear;
		}
   	
   		
   		// inserts an element at the front 
        void insertFront(int data){
        	
        
        	if(isFull()){
      	// if CircularSequence is full then expand the array to double size of its original size   		
        		expandTheArray();
			}
		// copy the data at front  		
	        arr[front] = data;
	    // decrement the front pointer in circular fashion     
	        front = (front - 1) % size;
	        
	        if(front < 0)
	        	front += size;
	         // increment the count by 1
	        elemCounts++;
		}
	// function that inserts an element at the back 	
		void insertBack(int data){
			
		// if array is full 	
			if(isFull()){
			// extend the array 	
				expandTheArray();
			// increment the rear to insert 
	            rear = (rear + 1) % size;
	        // insert the element 
	            arr[rear] = data;
	            
			}
          // no need to extend the array when array is not full   
	        else{
	        	
	            rear = (rear + 1) % size;
	            arr[rear] = data;
			}
			
			elemCounts++;
       	}

	// function that removes the element from the back side 	
		void erase(int ind){
		
		// update ind in order to delete the element in a circular way
			
			ind = ((front + ind) % size + 1) % size;

		// check for valid indices 	
			if(ind < 0 || ind > size){
				cout << "Index out of bound error!!"<<endl;
				return;
			}			
		// check for emptiness 	
			if(isEmpty())
            	cout << "empty sequence!!" << endl;
            	
        // if all okay, then remove the element from index i 
        	else{
 				
 				// for loop to shift the elements by one position to the left 
 				for(int i = ind; i != rear%size; i = (i+1) % size){				
 					arr[i] = arr[(i+1) % size];
				}
				
				// decrement the rear by 1 position in circular way 
				rear = (rear - 1) % size;
			}
			
        // decrement the element counts     
            elemCounts--;
		}
		
		/** function that returns the element present at index i **/
		
		Elem atIndex(int i){
			if(i >= 0 && i < elemCounts)
				return arr[i];
			else
				cout << "Index out of bound error!!"<<endl;
		}
	
		/** function that returns the index of element e **/	
		int IndexOf(const Elem& e){
			
			for(int i = 0; i < elemCounts; i++)
			{
				if(arr[i] == e)
					return i;
			}
			
			return -1;
		}
		
     // function to display the contents of the queue   
		void display(){
		
			cout << "\nDisplaying sequence contents: ";
			for(int i = (front+1) % size; i != (rear+1)%size; i = (i+1) % size)
				cout << arr[i] <<" ";
			
			cout << endl;
		} 
};

// main driver function to test the class Deque functionalities 
        
int main()

{
	CircularSequence cseq(5);

	cseq.display();
	cseq.insertFront(13);
	cseq.display();
	cseq.insertFront(15);
	cseq.display();
	cseq.insertFront(18);
	cseq.display();
	cseq.insertBack(19);
	cseq.display();
	cseq.insertBack(13);
	cseq.display();
	cseq.insertFront(15);
	cseq.display();
	cseq.insertBack(13);
	cseq.display();
	cseq.insertFront(15);
	cseq.display();

	cseq.erase(2);
	cseq.display();
	cseq.erase(0);
	cseq.display();
	cseq.erase(2);
	cseq.display();
	cseq.erase(1);
	cseq.display();	
	cseq.erase(1);
	cseq.display();
	cseq.erase(0);
	cseq.display();
	
}
