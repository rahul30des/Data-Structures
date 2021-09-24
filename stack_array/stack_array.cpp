#include <iostream>

using namespace std;

class Stack
{
    private:
        int top;
        int *arr;
        int ssize;
    public:
        Stack(int n)
        {
            ssize = n;
            top = -1;
            arr = new int[n];
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
 
        void Print() {
            for(int i = 0; i <= top; i++) {
                cout<<arr[i]<<"\t";     
            }
        }
};

// Main Function
int main()
{
    Stack S(3);
    S.Push(2);
    S.Print();
    cout<<endl;
    S.Push(5);
    S.Print();
    cout<<endl;
    S.Push(10);
    S.Print();
    cout<<endl;
    S.Push(12);
    S.Pop();
    S.Print();
    cout<<endl;
    S.Push(12);
    S.Print();
    cout<<endl;
}
