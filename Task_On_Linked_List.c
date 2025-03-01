#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node* next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
int len=0;
struct Node* Create_A_Node(int val){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->val=val;
	newnode->next=NULL;
	return newnode;
}
void Insert_To_List(int val){
	struct Node* nn=Create_A_Node(val);
	if(head==NULL){
		head=nn;
		tail=nn;
		return ;
	}
	tail->next=nn;
	tail=nn;
	return ;
	
}
void Ask_Initial_Linked_List(){
	printf("Enter Number of Nodes (>=3)\n");
	int n;
	scanf("%d",&n);
	len=n;
	while(1){
		if(n>=3){
			break;
		}
		printf("Enter Number of Nodes (>=3)\n");
		scanf(" %d",&n);
	}
	printf("Enter %d values\n",n);
	for(int i=0; i<n; i++){
		int val;
		scanf("%d",&val);
		Insert_To_List(val);
	}
	return ;
}
void Cur_Linked_List(){
	printf("The Current Linked List is\n");
	printf("----------------------------------------------------------\n");
	struct Node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->next;
	}
	printf("\n");
}

void Display_Menu(){
	printf("----------------------------------------------------------\n");
	printf("----------------------MENU--------------------------------\n");
	printf("----------------------------------------------------------\n");
	printf("1.Insert New Value At Head\n");
	printf("2.Insert New Value At Tail\n");
	printf("3.Insert New Value At a Position\n");
	printf("4.Delete Value At Head\n");
	printf("5.Delete Value At Tail\n");
	printf("6.Delete Value At a Position\n");
	printf("7.Exit\n");
	printf("----------------------------------------------------------\n");
	return ;
}
void Insert_At_Head(){
	int val;
	printf("Enter The Value\n");
	scanf("%d",&val);
	struct Node* nn=Create_A_Node(val);
		nn->next=head;
		head=nn;
	Cur_Linked_List();
	len++;
	return ;
}
void Insert_At_Tail(){
	int val;
	printf("Enter The Value\n");
	scanf("%d",&val);
	struct Node *nn=Create_A_Node(val);
	tail->next=nn;
	tail=nn;
	Cur_Linked_List();
	len++;
	return ;
}
void Insert_At_Pos(){
	int pos;
	printf("Enter the Position (>=2 <=%d)\n",len);
	scanf("%d",&pos);
	while(1){
		if(pos>=2 && pos<=len){
			break;
		}
		printf("Enter the Position (>=2 <=%d)\n",len);
		scanf("%d",&pos);	
	}
	int val;
	printf("Enter The Value\n");
	scanf("%d",&val);
	struct Node * temp=head;
	int cnt=1;
	while(1){
		if(cnt==(pos-1)){
			break;
		}
		temp=temp->next;
		cnt++;
	}
	struct Node* nn=Create_A_Node(val);
	nn->next=temp->next;
	temp->next=nn;
	Cur_Linked_List();
	len++;
	return ;
}
void Delete_At_Head(){
	head=head->next;
	Cur_Linked_List();
	len--;
	return ;
}
void Delete_At_Tail(){
	struct Node * temp=head;
	int cnt=1;
	while(1){
		if(cnt==(len-1)){
			break;
		}
		temp=temp->next;
		cnt++;
	}
	temp->next=NULL;
	tail=temp;
	Cur_Linked_List();
	len--;
	return ;
}
void Delete_At_Pos(){
	int pos;
	printf("Enter the Position (>=2 <=%d)\n",len);
	scanf("%d",&pos);
	while(1){
		if(pos>=2 && pos<=len){
			break;
		}
		printf("Enter the Position (>=2 <=%d)\n",len);
		scanf("%d",&pos);	
	}
	struct Node * temp=head;
	int cnt=1;
	while(1){
		if(cnt==(pos-1)){
			break;
		}
		temp=temp->next;
		cnt++;
	}
	temp->next=temp->next->next;
	Cur_Linked_List();	
	len--;
	return ;
}

int main(){
	Ask_Initial_Linked_List();
	Cur_Linked_List();
	while(1){
		Display_Menu();
		printf("Enter Your Option\n");
		int opt;
		scanf("%d",&opt);
		switch(opt){
			case 1:
				Insert_At_Head();
				break;
			case 2:
				Insert_At_Tail();
				break;
			case 3:
				Insert_At_Pos();
				break;
			case 4:
				Delete_At_Head();
				break;
			case 5:
				Delete_At_Tail();
				break;
			case 6:
				Delete_At_Pos();
				break;
			default :
				Cur_Linked_List();
				printf("The Process Excuted Successfully\n");
				break;
		}
		if(opt>=7){
			break;
		}
		
	}
	return 0;	
}







