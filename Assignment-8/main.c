#include"functions.h"
int main()
{
    bst *root=NULL;
    char str[50];
     printf("\nEnter Name: ");
    scanf(" %[^\n]",str);
    while(strcmp(str,"0")!=0)
    {
        root=insert(str,root);
        printf("\nEnter Name: ");
        scanf(" %[^\n]",str);
    }
    printf("\nDISPLAYING IN ALPHABETICAL ORDER...\n");
    inorder(root);
    printf("\n\nEnter a name to find Grandparent: ");
    scanf(" %[^\n]",str);
    gp(str,root);
    printf("\n\nEnter a name to find Grandparent: ");
    scanf(" %[^\n]",str);
    gp(str,root);
    printf("\n\nEnter a name to find Grandchildren: ");
    scanf(" %[^\n]",str);
    gc(str,root);
    printf("\n\nEnter a name to find sibling: ");
    scanf(" %[^\n]",str);
    sibling(str,root);
    printf("\n\nEnter a name to find sibling: ");
    scanf(" %[^\n]",str);
    sibling(str,root);
    printf("\n\nEnter a name to Delete: ");
    scanf(" %[^\n]",str);
    del(str,root);
    printf("\n\nInorder traversal of tree after deletion...\n\n");
    inorder(root);
    return 0;
}
