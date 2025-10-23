#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int info;
    struct btree *left;
    struct btree *right;
};

struct btree *insert(struct btree *root, struct btree *new);
void inorder(struct btree *root);
void preorder(struct btree *root);
void postorder(struct btree *root);
struct btree *createNode(int data);

int main()
{
    struct btree *root = NULL;
    struct btree *new;
    char ch;
    int data;

    do
    {
        printf("Enter data: ");
        scanf("%d", &data);
        new = createNode(data);
        if (root == NULL)
            root = new;
        else
            root = insert(root, new);

        printf("Do you want to insert more? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

struct btree *createNode(int data)
{
    struct btree *new = (struct btree *)malloc(sizeof(struct btree));
    new->info = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct btree *insert(struct btree *root, struct btree *new)
{
    char ch;
    if (root == NULL)
        return new;

    printf("Insert to left/right of %d (L/R): ", root->info);
    scanf(" %c", &ch);

    if (ch == 'L' || ch == 'l')
        root->left = insert(root->left, new);
    else if (ch == 'R' || ch == 'r')
        root->right = insert(root->right, new);
    else
        printf("Invalid choice!\n");

    return root;
}

void inorder(struct btree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct btree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct btree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}
