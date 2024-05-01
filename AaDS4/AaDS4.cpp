#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node* l, * r;
};

void show(Node*& Tree)
{
    if (Tree != NULL)
    {
        show(Tree->l);
        cout << Tree->x << '\t';
        show(Tree->r);
    }
}

void PrintTree(Node* leaf, int& n)
{
    if (leaf != NULL)
    {
        n++;
        PrintTree(leaf->l, n);
        for (int i = 1; i <= n; i++) cout << " ";
        cout << leaf->x << endl;
        PrintTree(leaf->r, n);
        n--;
    }
}

void add_node(int x, Node*& MyTree)
{
    if (NULL == MyTree)
    {
        MyTree = new Node;
        MyTree->x = x;
        MyTree->l = MyTree->r = NULL;
    }

    if (x < MyTree->x)
    {
        if (MyTree->l != NULL) add_node(x, MyTree->l);
        else
        {
            MyTree->l = new Node;
            MyTree->l->l = MyTree->l->r = NULL;
            MyTree->l->x = x;
        }
    }

    if (x > MyTree->x)
    {
        if (MyTree->r != NULL) add_node(x, MyTree->r);
        else
        {
            MyTree->r = new Node;
            MyTree->r->l = MyTree->r->r = NULL;
            MyTree->r->x = x;
        }
    }
}

int getTreeDepth(Node* tree) {
    if (tree == nullptr) {
        return 0;
    }
    else {
        int leftDepth = getTreeDepth(tree->l);
        int rightDepth = getTreeDepth(tree->r);
        return 1 + max(leftDepth, rightDepth);
    }
}

// Перше і друге завдання по рекурсії
#include <cmath>

int countDigits(int number) {
    if (number < 10) {
        return 1;
    }

    return 1 + countDigits(number / 10);
}

void getDigitsFromNumber(int number, int* digitsArray, int size) {
    if (number < 10) {
        digitsArray[size - 1] = number;
        return;
    }

    int lastDigit = number % 10;
    int remaining = number / 10;

    digitsArray[size - 1] = lastDigit;
    getDigitsFromNumber(remaining, digitsArray, size - 1);
}

bool isDigitInNumber(int k, int N) {
    if (N == k) return true;

    if (N < 10) return false;


    if (N % 10 == k)
        return true;

    return isDigitInNumber(k, N / 10);

}


int main()
{
    // Перше завдання

    int inputNumber;
    cout << "Enter number: ";
    cin >> inputNumber;

    int digitsCount = countDigits(inputNumber);
    int* digitsArray = new int[digitsCount];

    getDigitsFromNumber(inputNumber, digitsArray, digitsCount);

    cout << "Returned digits:" << endl;
    for (int i = 0; i < digitsCount; i++) {
        cout << digitsArray[i] << endl;
    }

    delete[] digitsArray;

    // Друге завдання

    int k, N;
    cout << "Enter k digit: ";
    cin >> k;
    cout << "Enter N number: ";
    cin >> N;

    string result = isDigitInNumber(k, N) ? " is in " : " is not in ";

    cout << "Digit " << k << result << N << endl;

    // Третє завдання

    Node* Tree = NULL;
    int x, kol;

    cout << "Enter the number of elements in the tree: ";
    cin >> kol;

    cout << "Enter " << kol << " elements for the tree:" << endl;
    for (int i = 0; i < kol; i++)
    {
        cin >> x;
        add_node(x, Tree);
    }

    cout << "\nBinary tree from user input: \n";
    PrintTree(Tree, kol);

    int depth = getTreeDepth(Tree);
    cout << "\nTree depth: " << depth << endl;

    delete Tree;

    return 0;
}
