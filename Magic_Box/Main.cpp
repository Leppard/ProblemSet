#include <iostream>
#include <vector>
using namespace std;

int check(vector<char> &color,int x,int y,int z,int max);

int main(void)
{
    int max = 0;
    int x,y,z;
    cin >>x>>y>>z;
    
    char input[20000] = {'\0'};
    cin >>input;
    
    vector<char> color;
    
    for(int n = 0; input[n]!='\0';n++)
    {
        color.push_back(input[n]);
        max = check(color,x,y,z,max);
    }
    
    if(0 != color.size())
    {
        if(max < color.size())max = color.size();
    }
    cout<<max<<endl;
    return 0;
    
}

int check(vector<char> &color,int x,int y,int z,int max)
{
    int cr = 0,cy = 0,cb = 0;
    for(int n = 0;n<color.size();n++)
    {
        switch (color[n])
        {
            case 'R':
                cr++;
                break;
            case 'Y':
                cy++;
                break;
            case 'B':
                cb++;
                break;
            default:
                break;
        }
    }
    
    int fx = cr-cy,fy = cy-cb,fz = cb-cr;
    if(fx<0)fx = 0-fx;
    if(fy<0)fy = 0-fy;
    if(fz<0)fz = 0-fz;
    
    if((fx == x && fy == y && fz == z) || (fx == x && fy == z && fz == y) ||
       (fx == z && fy == y && fz == x) || (fx == y && fy == x && fz == z) ||
       (fx == y && fy == z && fz == x) || (fx == z && fy == x && fz == y))
    {
        if(max >= color.size())
        {
            color.clear();
        }
        else
        {
            max = color.size();
            color.clear();
        }
    }
    
    return max;
}