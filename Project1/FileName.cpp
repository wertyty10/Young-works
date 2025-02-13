#include <iostream>
#include <vector>

using namespace std;



int main()
{

    setlocale(LC_ALL, "rus");

    vector<int>v = {567, 86, 29, 2, 1967, 5678};

    vector<int>::iterator it = v.begin();

    advance(it, 2);

    v.insert(it, 678);

    for ( it = v.begin();  it != v.end(); it++)
    {
        cout << *it << endl;
    }
    
    

    advance(it = v.begin(), 3);

    v.erase(v.begin()+3);

    cout << endl;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}