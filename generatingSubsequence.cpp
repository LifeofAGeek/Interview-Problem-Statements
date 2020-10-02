#include <iostream>
#include <vector>
using namespace std;

vector<string> result;
 
void printSubs(string input, string output){
    if(input.length()==0){  
        result.push_back(output);
        return;
    }
    // First excluding the zeroth character
    printSubs(input.substr(1), output);
    // Now including the zeroth character
    printSubs(input.substr(1), output+input[0]);
}

int main(){
    cout << "Enter a sting: ";
    string s;
    cin >> s;
    printSubs(s, "");
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
}