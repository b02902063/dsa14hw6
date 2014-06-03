#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"
#include "avl.h"
#include "rb.h"

void preorder_string_bst(struct bst_node *node){
	if(node == NULL)
		return;
	printf("%s ", (char*)node->bst_data);
	if(node->bst_link[0] != NULL || node->bst_link[1] != NULL){
		putchar('(');
		preorder_string_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_bst(node->bst_link[1]);
		putchar(')');
	}
}
void preorder_string_avl(struct avl_node *node){
	if(node == NULL)
		return;
	printf("%s ", (char*)node->avl_data);
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL){
		putchar('(');
		preorder_string_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_avl(node->avl_link[1]);
		putchar(')');
	}
}
void preorder_string_rb(struct rb_node *node){
	if(node == NULL)
		return;
	printf("%s ", (char*)node->rb_data);
	if(node->rb_link[0] != NULL || node->rb_link[1] != NULL){
		putchar('(');
		preorder_string_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_rb(node->rb_link[1]);
		putchar(')');
	}
}

int string_compare(const void *pa, const void *pb, void *param){
	char* a = (char *)pa;
	char* b = (char *)pb;
	int la = strlen(a);
	int lb = strlen(b);
	int i = 0;
	while(i <= la && i <= lb){
		if(a[i] < b[i]) return -1;
		if(a[i] > b[i]) return 1;
		i++;
	}
	if(la < lb) return -1;
	if(la > lb) return 1;
	return 0;
}
int main(){
	void **p;
	struct bst_table *bsttree;
	struct avl_table *avltree;
	struct rb_table *rbtree;
	bsttree = bst_create(string_compare, NULL , NULL);	
	avltree = avl_create(string_compare, NULL , NULL);
	rbtree = rb_create(string_compare, NULL , NULL);
	char name[32][30]= {"Chuang", "Chou", "Chang", "Chao", "Chen", "Cheng", "Chu", "Fu", "Fuh", "Hsiang", "Hsu", "Hsueh",
"Hung", "Jang", "Kao", "Kuo", "Lai", "Lee", "Liao", "Lin", "Liou", "Liu", "Lu", "Lyuu", "Ouhyoung", "Oyang",
"Shih", "Tsai", "Tseng", "Wang", "Wu", "Yang"};
	int i;
	for(i = 0;i < 32;i++){
		char* element = (char*)malloc(sizeof(char)*30);
		strcpy(element, name[i]);
		void **p = bst_probe(bsttree, element);	
	}
	preorder_string_bst(bsttree->bst_root);
	puts("");
	for(i = 0;i < 32;i++){
		char* element = (char*)malloc(sizeof(char)*30);
		strcpy(element, name[i]);
		void **p = avl_probe(avltree, element);	
	}
	preorder_string_avl(avltree->avl_root);
	puts("");
	for(i = 0;i < 32;i++){
		char* element = (char*)malloc(sizeof(char)*30);
		strcpy(element, name[i]);
		void **p = rb_probe(rbtree, element);	
	}
	preorder_string_rb(rbtree->rb_root);
	puts("");
	return 0;
}