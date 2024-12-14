#include <iostream>
#include <math.h>
using namespace std;

class vertex
{
public:
    int x;
    int y;
    vertex *next;
    vertex(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->next = NULL;
    }
};

vertex *addVertex(vertex *last, int x, int y)
{
    vertex *temp = new vertex(x, y);
    if (last == NULL)
    {
        last = temp;
        last->next = last;
        return last;
    }
    vertex *head = last->next;
    last->next = temp;
    temp->next = head;
    return last;
}

vertex *displayVertex(vertex *last)
{
    if (last == NULL)
    {
        cout << "Empty Linked List.\n";
        return last;
    }
    vertex *current = last->next;
    do
    {
        cout << "( " << current->x << " , " << current->y << " )" << "\t";
        current = current->next;
    } while (current != last->next);
    cout << endl;
    return last;
}

void displayEdge(vertex *last)
{
    if (last == NULL || last->next == NULL)
    {
        cout << "Not enough vertices for edge." << endl;
    }
    vertex *v1 = last;
    vertex *v2 = last->next;

    do
    {
        cout << "( " << v1->x << " , " << v1->y << " ) --> " << "( " << v2->x << " , " << v2->y << " ) " << endl;
        v1 = v1->next;
        v2 = v2->next;
    } while (v1 != last && v2 != last->next);
    cout << "----------------------------------------\n";
}

void classifyEdge(vertex *last)
{
    if (last == NULL || last->next == NULL)
    {
        cout << "Not enough vertices for edge." << endl;
    }

    vertex *v1 = last;
    do
    {
        vertex *v2 = v1->next;
        do
        {
            if (v1 != v2)
            {
                if (v1->x == v2->x && v1->y != v2->y)
                {
                    cout << "( " << v1->x << " , " << v1->y << " ) --> " << "( " << v2->x << " , " << v2->y << " ) is Vertical Edge.\n";
                }
                else if (v1->y == v2->y && v1->x != v2->x)
                {
                    cout << "( " << v1->x << " , " << v1->y << " ) --> " << "( " << v2->x << " , " << v2->y << " ) is Horizontal Edge.\n";
                }
                else if (v1->x != v2->x && v1->y != v2->y)
                {
                    cout << "( " << v1->x << " , " << v1->y << " ) --> " << "( " << v2->x << " , " << v2->y << " ) is diagonal Edge.\n";
                }
            }
            v2 = v2->next;
        } while (v2 != last->next);
        cout << "----------------------------------------\n";
        v1 = v1->next;
    } while (v1 != last);
    cout << "----------------------------------------\n";
}

int lengthOfEdge(vertex *last)
{
    if (last == NULL || last->next == NULL)
    {
        cout << "Not enough vertices for edge" << endl;
    }
    vertex *v1 = last;
    int length;
    do
    {
        vertex *v2 = v1->next;
        do
        {
            length = sqrt(pow((v2->x - v1->x), 2) + pow((v2->y - v1->y), 2));
            cout << "Length of ( " << v1->x << " , " << v1->y << " ) --> " << "( " << v2->x << " , " << v2->y << " ) is " << length << endl;
            v2 = v2->next;
        } while (v2 != last->next);
        cout << "----------------------------------------\n";
        v1 = v1->next;
    } while (v1 != last);
    cout << "----------------------------------------\n";

    return length;
}

int main()
{
    vertex *last = NULL;

    //(1) Design and Print a list storing vertices of a polygon.
    last = addVertex(last, 2, 2);
    last = addVertex(last, 8, 2);
    last = addVertex(last, 10, 4);
    last = addVertex(last, 8, 6);
    last = addVertex(last, 2, 6);
    last = addVertex(last, 0, 4);
    last = displayVertex(last);

    //(2) Identify and Print all edges(consecutive vertices)
    displayEdge(last);

    //(3) Classify Edges (Horizontal, vertical and diagonal)
    classifyEdge(last);

    //(4) Length of Edge
    lengthOfEdge(last);
    return 0;
}