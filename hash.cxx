#include <iostream>
#include <vector>

enum{E,D,F};
struct hashfield
{
    int status;
    int content;
};

int insert(int k, int m, int pow, std::vector<hashfield>& t)
{
    std::vector<int> tries;
    if( pow == 1 )
    {
        int n = 0;
        int i;
        for(i = (k+n) % m; t.at(i).status != E; ++i)
        {
            if(t.at(i).status == D)
            {
                t.at(i).content = k;
                t.at(i).content = F;
            }
            tries.push_back(i);
            if(i == m)
                i = 0;
        }

        t.at(i).content = k;
        t.at(i).content = F;

        return i;
    }

    if( pow == 2 )
    {
        bool inserted = false;
        int n = 0;
        int i,c1,c2;
        std::cout << "Give me two constants: ";
        std::cin >> c1 >> c2;
        for(i = ( k + c1*n + c2*n^2 ) % m; t.at(i).status != E; ++i)
        {
            if(t.at(i).status == D)
            {
                t.at(i).content = k;
                t.at(i).status = F;
                inserted = true;
            }
            tries.push_back(i);
            if(i == m)
                i = 0;
        }

        if (inserted == false)
        {
            t.at(i).content = k;
            t.at(i).status = F;
        }

        return i;
    }

    std::cout << "Sequence of tries:";
    for(int i = 0; i < tries.size(); ++i)
        std::cout << " " << tries[i];
}
/*
bool delete(int k, int m, int pow, std::vector<hashfield>& t)
{
    std::vector<int> tries;
    if( pow == 1 )
    {
        int n = 0;
        int i;
        for(i = (k+n) % m; t.at(i).status != E; ++i)
        {
            if(t.at(i).status == D)
            {
                t.at(i).content = k;
                t.at(i).content = F;
            }
            tries.push_back(i);
            if(i == m)
                i = 0;
        }
        return i;
    }

    if( pow == 2 )
    {
        int n = 0;
        int i,c1,c2;
        std::cout << "Give me two constants: ";
        std::cin >> c1 >> c2;
        for(i = ( k + c1*n + c2*n^2 ) % m; t.at(i).status != E; ++i)
        {
            if(t.at(i).status == D)
            {
                t.at(i).content = k;
                t.at(i).content = F;
            }
            tries.push_back(i);
            if(i == m)
                i = 0;
        }
        return i;
    }

    std::cout << "Sequence of tries:";
    for(int i = 0; i < tries.size(); ++i)
        std::cout << " " << tries[i];
}
*/

int main()
{
    int h,pow,m;
    
    std::cout << "Power of hashing: ";
    std::cin >> pow;
    std::cout << "Size of hash table: ";
    std::cin >> m;

    std::vector<hashfield> hashtable (m);


}