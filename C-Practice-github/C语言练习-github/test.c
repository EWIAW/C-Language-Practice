//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* PrevCreate(char* pstr, int* pi)
{
    if (pstr[(*pi)++] == '#')
    {
        return NULL;
    }

    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newnode == NULL)
    {
        printf("malloc false\n");
        exit(-1);
    }
    newnode->val = pstr[(*pi)++];
    newnode->left = PrevCreate(pstr, pi);
    newnode->right = PrevCreate(pstr, pi);

    return newnode;
}

void InOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char str[100];
    scanf("%s", str);

    int i = 0;
    TreeNode* root = PrevCreate(str, &i);

    InOrder(root);
    return 0;
}