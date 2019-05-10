#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> temps;
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    string TEMPS; // the N temperatures expressed as integers ranging from -273 to 5526
    getline(cin, TEMPS);
    string::size_type sz;
    
    if(TEMPS == ""){
        TEMPS = "0";
    }
    
    int index = 0;
    string TempString;
    
    do{
        int i_dec = stoi(TEMPS,&sz);
        temps.push_back(i_dec);
        TEMPS = TEMPS.substr(sz);
        cerr << TEMPS << endl;
    }while(TEMPS != "");

    do{
        if(abs(temps[0]) < abs(temps[1])){
            swap(temps[0], temps[1]);
        }else if(abs(temps[0]) == (abs(temps[1]))){
            if(temps[0] > temps[1]){
                swap(temps[0], temps[1]);
            }
        }
        temps.erase(temps.begin());
    }while(temps.size() > 1);

    cout << temps.front() << endl;
}
