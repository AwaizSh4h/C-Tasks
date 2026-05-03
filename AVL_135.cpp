#include <iostream>
using namespace std;

struct TreeNodeData
{
    int value;
    TreeNodeData* left;
    TreeNodeData* right;
    int height;
};

TreeNodeData* rotateLeftSimple(TreeNodeData* root)
{
    TreeNodeData* tempa = root;
    root = root->right;
    TreeNodeData* tempb = root->left;
    root->left = tempa;
    tempa->right = tempb;
    return root;
}

TreeNodeData* rotateRightSimple(TreeNodeData* root)
{
    TreeNodeData* tempa = root;
    root = root->left;
    TreeNodeData* tempb = root->right;
    root->right = tempa;
    tempa->left = tempb;
    return root;
}

TreeNodeData* mainRoot = NULL;

int maxValue(int left, int right)
{
    if (left > right)
        {
            return left;
        }
    else
       {
        return right;
       }
}

int checkHeight(TreeNodeData* node)
{
    if (node == NULL)
        {
            return -1;
        }
        else
        {
          return node->height;
        }
}

TreeNodeData* leftRightCase(TreeNodeData* node)
{
    node->left = rotateLeftSimple(node->left);
    return rotateRightSimple(node);
}

TreeNodeData* rightLeftCase(TreeNodeData* node)
{
    node->right = rotateRightSimple(node->right);
    return rotateLeftSimple(node);
}

TreeNodeData* insertValue(TreeNodeData* node, int value)
{
    if (node == NULL)
    {
        TreeNodeData* newNode = new TreeNodeData();
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }

    if (value < node->value)
    {
        node->left = insertValue(node->left, value);

        if (checkHeight(node->left) - checkHeight(node->right) == 2)
        {
            if (value < node->left->value)
                {
                    node = rotateRightSimple(node);
                }
            else
              {
                  node = leftRightCase(node);
              }
        }
    }

    if (value > node->value)
    {
        node->right = insertValue(node->right, value);

        if (checkHeight(node->right) - checkHeight(node->left) == 2)
        {
            if (value > node->right->value)
                {
                    node = rotateLeftSimple(node);
                }
            else
                {
                    node = rightLeftCase(node);
                }
        }
    }

    node->height = maxValue(checkHeight(node->left), checkHeight(node->right)) + 1;
    return node;
}

TreeNodeData* searchValue(TreeNodeData* node, int value)
{
    while (node != NULL)
    {
        if (value == node->value)
        {
            cout << "Value Found!" << endl;
            return node;
        }

        if (value < node->value)
           {
             node = node->left;
           }
        else
            {
                node = node->right;
            }
    }

    cout << "Value not found." << endl;
    return NULL;
}

TreeNodeData* deleteValue(TreeNodeData* node, int value, int &flag)
{
    if (node == NULL)
        return NULL;

    if (value < node->value)
        {
            node->left = deleteValue(node->left, value, flag);
        }

    else if (value > node->value)
        {
            node->right = deleteValue(node->right, value, flag);
        }

    else
    {
        flag = 1;

        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }
        else if (node->left == NULL)
        {
            TreeNodeData* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            TreeNodeData* temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            TreeNodeData* temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;

            node->value = temp->value;
            node->right = deleteValue(node->right, temp->value, flag);
        }
    }

    node->height = maxValue(checkHeight(node->left), checkHeight(node->right)) + 1;

    if (checkHeight(node->left) - checkHeight(node->right) == 2)
    {
        if (checkHeight(node->left->left) >= checkHeight(node->left->right))
            {
                node = rotateRightSimple(node);
            }
        else
            {
                node = leftRightCase(node);
            }
    }
    else if (checkHeight(node->right) - checkHeight(node->left) == 2)
    {
        if (checkHeight(node->right->right) >= checkHeight(node->right->left))
            {
                node = rotateLeftSimple(node);
            }
        else
            {
                node = rightLeftCase(node);
            }
    }

    return node;
}

void preorder(TreeNodeData* node)
{
    if (node != NULL)
    {
        cout << node->value << " -> ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder (TreeNodeData* node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " -> ";
    }
}

void inorder(TreeNodeData* node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->value << " -> ";
        inorder(node->right);
    }
}

int main()
{
    int choice, num;

    while (true)
    {
       cout << "\n1.Insert value." << endl;
       cout << "2.Search." << endl;
       cout << "3.Delete." << endl;
       cout << "4.Pre-Order. " << endl;
       cout << "5.Post-Order. " << endl;
       cout << "6.In-Order." << endl;
       cout << "7.Exit" << endl;
       cout << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Value: ";
            cin >> num;
            mainRoot = insertValue(mainRoot, num);
        }
        else if (choice == 2)
        {
            cout << "Enter Value: ";
            cin >> num;
            searchValue(mainRoot, num);
        }
        else if (choice == 3)
        {
            cout << "Enter Value: ";
            cin >> num;
            int flag = 0;
            mainRoot = deleteValue(mainRoot, num, flag);
            if (flag)
            {
                cout << "Value has been Deleted. " << endl;
            }
            else 
            {
                cout << "Value Does Not exist to Delete." << endl;
            }
        }
        else if (choice == 4)
        {
            preorder(mainRoot);
            cout << endl;
        }
        else if (choice == 5)
        {
            postorder(mainRoot);
            cout << endl;
        }
        else if (choice == 6)
        {
            inorder(mainRoot);
            cout << endl;
        }
        else if (choice == 7)
        {
            cout << "Exit Done." << endl;
            break;
        }
        else
        {
            cout << "Wrong choice. " << endl;
        }
    }

    return 0;
}