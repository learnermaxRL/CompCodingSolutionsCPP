#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'superBitstrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY bitStrings
 */

const int MAXBITS = 18;
int maxLen;
map<std::string, int> globalMap;

vector<string> split(const string &s, char delim) 
{ 
    vector<string> elems; 
    stringstream ss(s); 
    string item; 
    while (getline(ss, item, delim)) 
        elems.push_back(item); 
  
    return elems; 
} 
 

int PowerSet(vector<int> arr,std::string bitStr)
{
    vector<string> list;

    int n = arr.size();
    for (int i = 0; i < (int)pow(2, n); i++)
    {
        string subset = "";

     
        for (int j = 0; j < n; j++)
        {
            
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        }

       
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }

    
    for (string subset : list)
    {
        string loc = bitStr;
        vector<string> arr = split(subset, '|');
       
        for (string str : arr){
            loc[std::stoi( str )] = '1';
 
            }
        globalMap.insert({loc,0});
        
    }
}

void Permute(int n)
{

    bitset<MAXBITS> binN(n);

    std::string str_bits = binN.to_string();
    str_bits.erase(0, (MAXBITS - maxLen));
    vector<int> zeroIndexes;
    for (unsigned int i = 0; i < str_bits.length(); i++)
    {
        if (str_bits.at(i) == '0')
            zeroIndexes.push_back(i);
    }
    PowerSet(zeroIndexes,str_bits);
}




int superBitstrings(int n, vector<int> bitStrings)
{

maxLen = n;
for (auto el:bitStrings){
 Permute(el);

}
}

    
 



int main()
{
    maxLen = 5;
    std::vector<int> x{10,26};
    superBitstrings(maxLen,x);
    std::cout << globalMap.size()<<"\n";
  
}
