#include <iostream>

using namespace std;

class Stack
{
    private:
        int *arr;
        int top;   
        int ssize;
    public:
        Stack(int n)
        {
            arr = new int[n];
            top = -1; 
            ssize = n;
        }

        void Push(int x) 
        {
            if(top == ssize - 1) { 
                cout<<"Error: Stack Overflow when trying to push "<<x<<endl;
                return;
            }
            arr[++top] = x;
        }
 
        void Pop() 
        {
            if(top == -1) { 
                cout<<"Error: No element to pop"<<endl;
                return;
            }
            top--;
        }
 
        int Top() 
        {
            return arr[top];
        }
 
        int IsEmpty()
        {
            if(top == -1) {
                return 1;
            }
            return 0;
        }

        void Print() {
            int i;
            cout<<"Stack: ";
            for(i = 0; i <= top; i++) {
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
};

// Main Function
int main()
{
    Stack S(3);
    S.Push(2);
    S.Print();
    S.Push(5);
    S.Print();
    S.Push(10);
    S.Print();
    S.Push(12);
    S.Pop();
    S.Print();
    S.Push(12);
    S.Print();
}
