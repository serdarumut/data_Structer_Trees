#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node * kok_Dugum_Olusturma(int data){                                 // Binary Tree kok dugum olusturma
	struct node * root = (struct node *) malloc (sizeof(struct node));
	
	root->data = data;
	root->left = NULL;                                          
	root->right = NULL;

	return root;
}

struct node * eleman_Ekleme(struct node *root, int data)                     // Kok dugume eleman ekleme
{
	if (root == NULL){
		root = kok_Dugum_Olusturma(data);
	}
	else{
		if(data < root-> data)
		root -> left = eleman_Ekleme(root->left, data);
		else
		root -> right = eleman_Ekleme(root->right, data);
	}
	return root;
}

void preorder(struct node * root){                                          // Root Left Right   (Basta Kok)
	if(root!=NULL){
		printf("%d - ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node * root){                                          // Left Root Right   (Ortada Kok)
	if(root!=NULL){
		inorder(root->left);
		printf("%d - ", root->data);
		inorder(root->right);
	}
}
 
void postorder(struct node * root){                                       //   Left Right Root   (Sonda Kok)
	if(root!=NULL){
		
		postorder(root->left);
		postorder(root->right);
		printf("%d - ", root->data);
	}
}


int main(int argc, char *argv[]) {
	
	struct node * eleman = NULL;
	
	int sayi;
	int i= 0;
	
	while (i<7){                                   // 7 elemanli agac girdisi alimi ve ekleme
		
		printf("Sayi Giriniz : ");
		scanf("%d", &sayi);
		eleman = eleman_Ekleme(eleman, sayi);
		i++;
	}
	
	// dizilim cesitlerine gore yazdirma islemleri
	
	printf("\nPreorder : ");
	preorder(eleman);
	
	printf("\nInorder : ");
	inorder(eleman);
	
	printf("\nPostorder : ");
	postorder(eleman);
	
	
	
	return 0;
}
