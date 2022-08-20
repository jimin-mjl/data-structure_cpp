#include <iostream>

#include "DataStructures/List.h"
#include "DataStructures/Queue.h"
#include "DataStructures/Stack.h"
#include "DataStructures/Vector.h"

int main()
{
    Vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        std::cout << v[i] << " " << v.size() << " " << v.capacity() << std::endl;
    }

    for (int i = 0; i < 50; i++)
    {
        v.pop_back();
        std::cout << v[i] << " " << v.size() << " " << v.capacity() << std::endl;
    }

    v.clear();

    std::cout << "-------------------------" << std::endl;

    List<int> li;

    li.push_back(1);
    li.push_front(2);
    li.pop_back();
    li.insert(li.begin(), 3);

    std::cout << (* (li.begin()) == 3) << std::endl;

    li.erase(li.begin());
    li.clear();

    std::cout << "-------------------------" << std::endl;

    Stack<int> sk;

    sk.push(1);
    sk.push(2);
    int top = sk.top();
    sk.pop();

    std::cout << top << std::endl;
    std::cout << sk.empty() << std::endl;

    std::cout << "-------------------------" << std::endl;

    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << (q.front() == 1) << std::endl;

    q.pop();
    std::cout << (q.front() == 2) << std::endl; 
}
