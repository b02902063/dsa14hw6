#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "avl_ntudsa.h"

struct student{
	char ID[15];
	int HW1;
	int HW2;
	int HW3;
	int HW4;
	int HW5;
};

int string_compare(const void *pa, const void *pb){
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

int score_compare(const void *pa, const void *pb, void *param){
	struct student* a = (struct student *)pa;
	struct student* b = (struct student *)pb;
	int ave_a = (a->HW1 + a->HW2 + a->HW3 + a->HW4 + a->HW5) / 5;
	int ave_b = (b->HW1 + b->HW2 + b->HW3 + b->HW4 + b->HW5) / 5;
	if(ave_a > ave_b){
		return -1;
	}else if(ave_a < ave_b){
		return 1;
	}else{
		if(a->HW2 > b->HW2){
			return -1;
		}else if(a->HW2 < b->HW2){
			return 1;
		}else{
			if(a->HW3 > b->HW3){
				return -1;
			}else if(a->HW3 < b->HW3){
				return 1;
			}else{
				if(a->HW5 > b->HW5){
					return -1;
				}else if(a->HW5 < b->HW5){
					return 1;
				}else{
					if(a->HW4 > b->HW4){
						return -1;
					}else if(a->HW4 < b->HW4){
						return 1;
					}else{
						if(a->HW1 > b->HW1){
							return -1;
						}else if(a->HW1 < b->HW1){
							return 1;
						}else{
							return string_compare(a->ID , b->ID);
						}
					}
				}
			}
		}
	}
}

int inorder_student_avl(struct avl_node *node, int first, int target){
	static int i;
	if(first){
		i = 0;
	}
	if(node->avl_link[0] != NULL)
	if(inorder_student_avl(node->avl_link[0], 0, target))
		return 1;
	if(node == NULL){
		return 0;
	}else{
		i++;
		if(i == target){
			printf("%s\n", ((struct student *)node->avl_data)->ID);
			return 1;
		}
	}
	if(node->avl_link[1] != NULL)
	if(inorder_student_avl(node->avl_link[1], 0, target))
		return 1;
	return 0;
}

int main(){
	char command[10];
	struct avl_table *tree;
	tree = avl_create (score_compare, NULL, NULL);
	while(scanf("%s", command) != EOF){
		if(strcmp(command , "push") == 0){
			struct student *new = (struct student *)malloc(sizeof(struct student));
			scanf("%s", new->ID);
			scanf("%d%d%d%d%d", &(new->HW1) , &(new->HW2) , &(new->HW3) , &(new->HW4) , &(new->HW5));
			avl_probe(tree, new);
		}else if(strcmp(command , "search") == 0){
			int target;
			scanf("%d", &target);
			inorder_student_avl(tree->avl_root , 1, target);
		}else{
			printf("Wrong Command\n");
		}
	}
}