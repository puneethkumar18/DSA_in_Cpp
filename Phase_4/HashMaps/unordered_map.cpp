#include<iostream>
//#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;

    //insertion
    //type1
    pair<string, int> pair("ramesh",10);
    m.insert(pair);

    //2
    //pair<string, int> pair1 = make_pair("suresh",10);
    // m.insert(pair1);

    //type 3
    m["ravi"] = 30;
    m["raju"] = 40;

    //Access 
    cout<<m["ramesh"]<<" "<<endl;
    cout<<m["ravi"]<<endl;
    //access using at
    cout<<m.at("raju")<<endl;

    //count function gives whether data is present or not if present return 1 otherwise return 0;
    cout<<m.count("ravi")<<endl;
    cout<<m.count("bro")<<endl;

    //differnce in at and direct access
    //which is not inserted to the map
    //cout<<m.at("peter")<<endl;// it will give an error of key not found
    cout<<m["john"]<<endl;// :- it won't give any error instead it gives 0 as answer

    //iterate over map
    //1
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();

     while(it != m.end()){
         cout<<it->first<<" "<<it->second<<endl;
         it++;
     }

    return 0;
}