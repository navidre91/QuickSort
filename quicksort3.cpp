#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void print(vector<int> A) {
   cout << "The vector elements are : ";

   for(int i=0; i < A.size(); i++){
    cout << A[i] << ' ';
   }
};

void sanity_check(vector<int> A) {
   cout << endl << "out of order element : ";

   for(int i=1; i < A.size(); i++){
       if(A[i]-A[i-1]!=1){
           cout << A[i] << ' ';
       }
   }
   cout<<endl;
};

void input_sanity_check(vector<int> A) {
   cout << endl << "out of order element : ";

   for(int i=0; i < A.size(); i++){
       if(A[i]<1 || A[i]>10000){
           cout << A[i] << ' ';
       }
   }
   cout<<endl;
};

class Quicksort{

    public:

    vector<int> A;
    double number_of_comparisions=0;
    int len_A;

    Quicksort(vector<int> B){
        A=B;
        len_A = A.size();
    }

    void quick_sort(vector<int>& A, int pvt_ind , int start_ind, int end_ind){
        if (start_ind>=end_ind){
            return;
        }
        number_of_comparisions = number_of_comparisions+(end_ind-start_ind);
        int i=start_ind;
        int j=start_ind+1;
        int temp = A[start_ind];
        A[start_ind]=A[pvt_ind];
        A[pvt_ind]=temp;
        while(j<=end_ind){
            if (A[j]>=A[start_ind]){
                j++;
            }
            if (A[j]<A[start_ind] && j<=end_ind){
                i++;
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                j++;
            }
        }
        temp=A[i];
        A[i]=A[start_ind];
        A[start_ind]=temp;

        quick_sort(A, i-1 , start_ind, i-1);
        quick_sort(A, end_ind , i+1, end_ind);

    }
};


int main(){
    string STRING;
    ifstream infile;
    vector<int> A;
    infile.open ("G:\\My Drive\\course\\Algorithm\\QuickSort\\nums.txt");
    while (!infile.eof()){
        getline(infile,STRING);
        A.push_back(stoi(STRING));
    }
    infile.close();
    cout<<A.size()<<endl;
    //input_sanity_check(A);
    Quicksort quicksorter = Quicksort(A);
    quicksorter.quick_sort(A, A.size()-1 , 0 , A.size()-1);
    print(A);
    sanity_check(A);
    cout.precision(100);
    cout<<quicksorter.number_of_comparisions;
    
    return 0;
}