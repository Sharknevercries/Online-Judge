/* 9248771 536 Tree Recovery Accepted C++ 0.008 2011-09-11 14:59:10 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEFT 1
#define RIGHT 2
struct tree{
	struct tree *left;
	struct tree *right;
	char data;
};
typedef struct tree TREE;
TREE *root;
char pre[100];
char in[100];
int pre_index;
void post_order(TREE *node){
	if(node->left!=NULL)
		post_order(node->left);
	if(node->right!=NULL)
		post_order(node->right);
	printf("%c",node->data);
	free(node);
}
void make_tree(int start,int end,int way,TREE *father){
	int i,j;
	for(i=start;i<=end;i++)
		if(pre[pre_index]==in[i])
			break;
	if(i>end)
		return ;

	TREE *new_node=(TREE*)malloc(sizeof(TREE));
	new_node->data=pre[pre_index++];
	new_node->left=NULL;
	new_node->right=NULL;

	if(root==NULL){
		root=new_node;	
		make_tree(start,i-1,LEFT,root);
		make_tree(i+1,end,RIGHT,root);
	}
	else{
		if(way==LEFT)
			father->left=new_node;
		else
			father->right=new_node;
		make_tree(start,i-1,LEFT,new_node);
		make_tree(i+1,end,RIGHT,new_node);
	}	
}
void initial(){
	root=NULL;
}
int main(){
	while(scanf("%s%s",pre,in)==2){
		int len=strlen(in);
		pre_index=0;
		make_tree(0,len-1,LEFT,root);
		post_order(root);
		putchar('\n');
	}
	return 0;
}
/*

Little Valentine liked playing with binary trees very much. Her favorite game was constructing randomly looking binary trees with capital letters in the nodes.
 
This is an example of one of her creations: 

                                    D
                                   / \
                                  /   \
                                 B     E
                                / \     \
                               /   \     \ 
                              A     C     G
                                         /
                                        /
                                       F

 To record her trees for future generations, she wrote down two strings for each tree: a preorder traversal (root, left subtree, right subtree) and an inorder traversal (left subtree, root, right subtree).
 
For the tree drawn above the preorder traversal is DBACEGF and the inorder traversal is ABCDEFG.
 
She thought that such a pair of strings would give enough information to reconstruct the tree later (but she never tried it).
 
Now, years later, looking again at the strings, she realized that reconstructing the trees was indeed possible, but only because she never had used the same letter twice in the same tree.
 
However, doing the reconstruction by hand, soon turned out to be tedious. 

So now she asks you to write a program that does the job for her! 

Input Specification  

The input file will contain one or more test cases. Each test case consists of one line containing two strings preord and inord, representing the preorder traversal and inorder traversal of a binary tree. Both strings consist of unique capital letters. (Thus they are not longer than 26 characters.)
 
 Input is terminated by end of file. 
 
Output Specification  

For each test case, recover Valentine's binary tree and print one line containing the tree's postorder traversal (left subtree, right subtree, root).
 
Sample Input  

DBACEGF ABCDEFG
BCAD CBAD

 Sample Output  

ACBFGED
CDAB

*/