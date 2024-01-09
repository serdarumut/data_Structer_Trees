#include <stdio.h>
#include <stdlib.h>

struct node{   // NODE YAPISI TANIMLAMA
	
	int data;
	struct node *left;
	struct node *right;
};

	typedef struct node BTREE;       // BTREE ADIYLA TYPEDEF YAPTIK
	
BTREE *new_node(int data){   // DUGUM OLUSTURDUK
	
	BTREE * p = (BTREE*) malloc (sizeof(BTREE));
	p-> data = data;
	p-> left = NULL;
	p-> right = NULL;
	return p;
}

BTREE *insert (BTREE * root, int data){   // AGACA YENI DUGUM EKLEME BOLGESI
	if(root != NULL){
		if(data < root->data)
		root -> left = insert(root-> left, data);
		else
		root -> right = insert(root-> right, data);
	}
	else
		root = new_node(data);
	return root;
}

void preorder(BTREE * root){       // ROOT - LEFT - RÝGHT
	if(root != NULL){
		printf("%3d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BTREE * root){     // LEFT - ROOT - RÝGHT
	if(root != NULL){
		inorder(root->left);
		printf("%3d", root->data);
		preorder(root->right);
	}
}

void postorder(BTREE * root){   // LEFT - RÝGHT - ROOT
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%3d", root->data);
	}
}

int main(int argc, char *argv[]) {
	
	BTREE *myroot = NULL; // AGAC BASTA BOS
	int i = 0;
	
	do{   // DO WHILE DONGUSU ILE -1 GIRILENE KADAR ISLEM YAPMAYA DEVAM ETTIK
		printf("\n\nAgaca veri eklemek icin sayi girisi yapiniz...   \nSayi : ");
		scanf("%d", &i);
		if(i != -1)
			myroot = insert(myroot, i);    // VERI EKLEME
	} while(i != -1);
	
	// TEK TEK SIRALAMA SEANSI
	preorder(myroot);
	printf("\n");
	inorder(myroot);
	printf("\n");
	postorder(myroot);
	
	
	return 0;
}
