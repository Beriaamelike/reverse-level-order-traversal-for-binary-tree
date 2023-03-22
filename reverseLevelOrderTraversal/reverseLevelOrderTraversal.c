//C program to print binary tree reverse level order traversal
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




//A binary tree node has data, pointer to left and right child
struct treeNode{
	
  int data;
  struct treeNode* leftptr;
  struct treeNode* rightptr;

};


//Function prototypes
void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);



bool IsEmptyStack(int top){  // if stack is empty return true, else return false.
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}

int Push(struct treeNode* root, int top, struct treeNode* arr[]){  // add reference of root node to stack
	top = top +1;
	arr[top] = root;
	return top;
}


int Pop(int top){   // delete last element from stack
	if(top == -1){
	  return 0;
	}
	else{
	top = top-1;
    }
    return top;
}


struct treeNode* Top(int top, struct treeNode* arr[]){ // return top element of stack
	return arr[top];
}







bool IsEmptyQueue(int front, int rear){  // if queue is empty return true, else return false
	if(front==-1 && rear==-1){
		return true;
	}
	else{
		return false;
	}
}



bool Enqueue(struct treeNode* root, int front, int rear, struct treeNode* arr[]){  
	if(IsEmptyQueue(front, rear)){
		return true;  // if queue is empty return true. Because both of front and rear well be zero.
	}
	else{
		
		return false;  
	}
}


bool Dequeue(int front, int rear, struct treeNode* arr[]){
	if(IsEmptyQueue(front, rear)){
		return true;
	}
	else if(front == rear){
		return true;
	}
	else{
		return false;
	}
}

//Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode* root){   

	if(root == NULL){
		return;  
	}
	else{
		    // create stack and queue
			struct treeNode* stack[10];
			struct treeNode* queue[10];
			
			int i;
			int newdata;
			
			
			int top = -1;  // for stack
			int front = -1;  // index of front of queue
			int rear = -1;   // index of rear of quque
			
			
			
			if(Enqueue(root, front, rear, queue)){
			
				rear = front = 0;  // if queue is empty, rear and front will equal to zero.
				
			}
			else{
				rear=rear +1;
			}
			queue[rear]=root;
				
			
			
			while(!IsEmptyQueue(front, rear)){
				root = queue[front];
				if(Dequeue(front, rear, queue)){    // delete first element from queue (FIFO)
					
					front = rear = -1;
				}
				else{
				    
					front = front +1;
				}
				top = Push(root, top, stack);   // add this element to stack
				
				
				// add root->rightptr to queue
				if(root->rightptr!=NULL){     
					if(Enqueue(root->rightptr, front, rear, queue)){
				        rear = front = 0;
				
			        }
			        else{
				        rear=rear +1;
			        }
		        	queue[rear]=root->rightptr;
				}
				
				
				// add root->leftptr to queue
				if(root->leftptr!=NULL){  
					if(Enqueue(root->leftptr, front, rear, queue)){  
				        rear = front = 0;
				
			        }
			        else{
				        rear=rear +1;
			        }
		        	queue[rear]=root->leftptr;
				}
				
		   	}
		   	
		   	
		   	// print stack 
			while(!IsEmptyStack(top)){  
				root = Top(top,stack);
				printf("%d ",root->data);
				top = Pop(top);
			}
		   
		
		
	}
	
	
}





//Insert new node to the binary tree
struct treeNode* newNode(int data){
	
    struct treeNode* treeNode = (struct treeNode*) malloc(sizeof(struct treeNode));
    treeNode->data = data;
    treeNode->leftptr = NULL;
    treeNode->rightptr = NULL;
    
	return(treeNode);
}




int main(){
	
	
    struct treeNode *root = newNode(9);
    root->leftptr = newNode(12);
    root->rightptr = newNode(21);
    root->leftptr->leftptr = newNode(15);
    root->leftptr->rightptr = newNode(8);
    root->rightptr->leftptr = newNode(7);
    root->rightptr->rightptr = newNode(11);
    printf("Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);
    
    return 0;
}





