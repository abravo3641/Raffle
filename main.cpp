#include <iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<time.h>
using namespace std;

void fillVector(vector<int>&);
void printVector(const vector<int>&);
void version1(vector<int>&);
void version2(vector<int>&);
void collectV(vector<int>&);



int main() {

    vector<int> random;
    fillVector(random);
    printVector(random);
    for(int i=0;i<20;i++) {

    collectV(random);
    printVector(random);

    }



    return 0;
}

void fillVector(vector<int>& random) {
    int start,end;
    cout << "Enter range: ";
    cin >> start >> end;
    for(int i=start;i<end+1;i++) {
        random.push_back(i);
    }
}

void printVector(const vector<int>& random) {
    for(int i=0;i<random.size();i++) {
        cout << random[i] << " ";
    }
    cout << endl;
}

void collectV(vector<int>& random) {
    int version;
    cout << "Which version: ";
    cin >> version;
    if(version == 1) {
        version1(random);
    }
    else if(version==2) {
        version2(random);
    }
    else {
        collectV(random);
    }

}

void version1(vector<int>& random) {

        int times;
        cout << "How many people leaving?: ";
        cin>>times;
       if(times==-1) {
           return;
       }
       cout << "Type number of the person: ";
       bool valid = false;
       int number;
       cin >> number;
       if(number==-1) {
           return;
       }
        while(times>0 || !valid) {

            if(valid == true) {
                cout << "type number of the person: ";
                cin >> number;
                valid = false;
                if(number==-1) {
                    break;
                }
            }
            //cout << "Type number to remove: ";

            for(int i=0; i<random.size();i++) {
                if(random[i] == number) {
                    random.erase(random.begin()+i);
                    valid = true;
                }
            }

            if(valid == true) {
                times--;
            }
            else {
                cout << "Did not find try again: ";
                cin >> number;
                if(number==-1) {
                    break;
                }
            }
        }
        if(number == -1) {
            return;
        }
}

void version2(vector<int>& random) {

    srand(time(0));

    size_t k = rand()%(random.size());
    cout << "Winner: " <<random[k] << endl;
    char answer;
    cout << "Do you want to remove this number?";
    cin>>answer;
    if(answer=='y') {
        random.erase(random.begin()+k);
    }
    if(answer == 'q') {
        return;
    }

}





















