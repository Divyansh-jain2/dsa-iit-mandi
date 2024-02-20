//q2


// #include<iostream>
// using namespace std;


// void generatefibonacci(int n){
//     for(int i=0;i<n;i++){
//         int array1[n];
//         if(i==0 or i==1){
//             array1[i]=i;
//         }
//         else{
//             array1[i]=array1[i-1]+array1[i-2];
//         }
//         cout<<array1[i]<<" ";
//     }
// }
// int main(){
//     try{
//         int n;
        
//         cout<<"enter the number of terms you want int the fibonacci series"<<endl;
//         cin>>n;
//         if(n<0){
//             throw(n);
//         }
//         generatefibonacci(n);
//         throw(n);
//     }
//     catch(...){
//         cout<<"please provide a valid input"<<endl;
//     }   
// }



//q3



// #include<iostream>
// using namespace std;

// int calculateArea(int l,int w){
//     return (l*w);
// }
// int calculatePerimeter(int l,int w){
//     return 2*(l+w);
// }
// int main(){
//     try{
//         int l;
//         int w;
//         cout << "enter the value of length" << endl;
//         cin >> l;
//         cout << "enter the value of width" << endl;
//         cin >> w;
//         if (l > 0 and w > 0) {
//             cout << calculateArea(l, w) << endl;
//             cout << calculatePerimeter(l, w) << endl;    
//         } 
//         else {
//             throw ("Invalid input");
//         }
//     }
//     catch(...){
//         cout<<"please provide a valid input"<<endl;
//     }

// }



// q4


// Q4: Write a C/C++ program to calculate the volume and surface area of a cylinder. Implement functions calculateVolume and calculateSurfaceArea that take the radius and height of the cylinder as parameters and return the volume and surface area, respectively. The program should take user input for the radius and height of the cylinder and output the calculated volume and surface area.    Requirements: 1. Use functions (calculateVolume and calculateSurfaceArea) to perform calculations. 2. The program should handle positive values for the radius and height. 3. Validate user input to ensure that positive values are entered. 4. Use appropriate variable types and error checking. 

// #include<iostream>
// #include<cmath>
// using namespace std;
// int calculateVolume(int r,int h){
//     return (M_PI*r*r*h);
// }

// int calculateSurfaceArea(int r,int h){
//     return (2*M_PI*r*(r+h));
// }

// int main(){
//     int r;
//     int h;
//     cout<<"enter the value of r:"<<endl;
//     cin>>r;
//     cout<<"enter the value of h:"<<endl;
//     cin>>h;
//     if (r>=0 && h>0){
//         cout<<calculateSurfaceArea(r,h)<<endl;
//         cout<<calculateVolume(r,h)<<endl;
//     }
//     else{
//         cout<<"enter valid input";
//     }

// }



// #include<iostream>
// #include<cmath>
// #include<limits>
// using namespace std;

// double calculateVolume(int r,int h){
//     return (M_PI*r*r*h);
// }

// double calculateSurfaceArea(int r,int h){
//     return (2*M_PI*r*(r+h));
// }

// int main(){
//     int r;
//     int h;
//     cout<<"enter the value of r:"<<endl;
//     if (!(cin >> r)) {
//         cout << "Invalid input. Please enter an integer." << endl;
//         cin.clear(); // clear the error state
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the line
//         return 1; // exit the program
//     }
//     cout<<"enter the value of h:"<<endl;
//     if (!(cin >> h)) {
//         cout << "Invalid input. Please enter an integer." << endl;
//         cin.clear(); // clear the error state
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the line
//         return 1; // exit the program
//     }
//     if (r>=0 && h>0){
//         cout<<"Surface Area: "<<calculateSurfaceArea(r,h)<<endl;
//         cout<<"Volume: "<<calculateVolume(r,h)<<endl;
//     }
//     else{
//         cout<<"enter valid input";
//     }
//     return 0;
// }






// Q5: Write a C/C++ program that takes an input for the total number of days and calculates the corresponding day, month, and year. It also checks whether the calculated year is a leap year or not.  

// #include<iostream>
// using namespace std;

// int main(){
//     int days;
//     cout<<"enter the number of days"<<endl;
//     cin>>days;
//     int year=0;
//     int month=0;
//     int day=0;
//     if(days>365){
//         year=days/365;
//         days=days%365;
//     }
//     if(days>30){
//         month=days/30;
//         days=days%30;
//     }
//     day=days;
//     cout<<"year: "<<year<<endl;
//     cout<<"month: "<<month<<endl;
//     cout<<"day: "<<day<<endl;
//     if(year%4==0){
//         cout<<"leap year"<<endl;
//     }
//     else{
//         cout<<"not a leap year"<<endl;
//     }
//     return 0;
// }





// q6


// #include<iostream>
// using namespace std;


// int main(){
//     string a;
//     cout<<"enter the string"<<endl;
//     cin>>a;
//     string b="";
//     int length=0;
//     cout<<b<<endl;
//     while (a[length]!='\0'){
//         length++;
//     }
//     for (int i=0;i<length;i++){
//         b[i]=a[length-1-i];
//     }
//     cout<<b<<endl;
//     if (b==a){
//         cout<<"yes its a palindromw"<<endl;
//     }   
//     else{
//         cout<<"no its not a palindrome"<<endl;
//     }
//     return 0;
// }



// Write a program in C/C++ for the split function to split a sentence (as a char array) then split and store its words into another array of character arrays. 



// #include<iostream>
// using namespace std;

// int main(){
//     string a;
//     cout<<"enter the string"<<endl;
//     cin>>a;
//     string b="";
//     int length=0;
//     cout<<b<<endl;
//     while (a[length]!='\0'){
//         length++;
//     }
//     for (int i=0;i<length;i++){
//         b[i]=a[length-1-i];
//     }
//     cout<<b<<endl;
//     if (b==a){
//         cout<<"yes its a palindromw"<<endl;
//     }   
//     else{
//         cout<<"no its not a palindrome"<<endl;
//     }
//     return 0;
// }



// q1

// #include<iostream>
// using namespace std;

// int gcd(int a,int b){
//     while(b!=0){
//         int c=a%b;
//         a=b;
//         b=c;
//     }
//     return a;
// }
// int main(){
//     int a;
//     int b;
//     do{
//         cout<<"enter the larger value"<<endl;
//         if (!(cin>>a)){
//             cout<<"invalid input. please enter an integer"<<endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             continue;
//         }
//         cout<<"enter the smaller value"<<endl;
//         if(!(cin>>b)){
//             cout<<"invalid input please enter an integer"<<endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             continue;
//         }
//     }
//     while(a<0 or b<0);
//     // cout<<gcd(a,b);
//     return 0;
// }




// #include<iostream>
// #include<limits>
// using namespace std;

// int gcd(int a,int b){
//     while(b!=0){
//         int c=a%b;
//         a=b;
//         b=c;
//     }
//     return a;
// }

// int main(){
//     int a;
//     int b;
//     while(true){
//         cout<<"enter the larger value"<<endl;
//         if (!(cin>>a)){
//             cout<<"invalid input. please enter an integer"<<endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             continue;
//         }
//         cout<<"enter the smaller value"<<endl;
//         if(!(cin>>b)){
//             cout<<"invalid input please enter an integer"<<endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');
//             continue;
//         }
//         if(a>=0 && b>=0 && a>b) {
//             break; // break the loop if valid input is received
//         }
//         else{
//             cout<<"enter a valid input"<<endl;
//             continue;
//         }
//     }
//     cout<<gcd(a,b);
//     return 0;
// }



// #include<iostream>
// using namespace std;

// class leap_year{
//     int leap_year_days=366;
    
//     int jan=31;
//     int feb=29;
//     int march=31;
//     int april=30;
//     int may=31;
//     int june=30;
//     int july=31;
//     int aug=31;
//     int sept=30;
//     int oct=31;
//     int nov=30;
//     int dec=31;
//     string getmonth(int i){
//         string months_name[12]={"jan","feb","march","april","may","june","july","aug","sept","oct","nov","dec"};
//         return months_name[i];

//     }
// };
// class normal_year{
//     int normal_year_days=365;
   
//     int jan=31;
//     int feb=28;
//     int march=31;
//     int april=30;
//     int may=31;
//     int june=30;
//     int july=31;
//     int aug=31;
//     int sept=30;
//     int oct=31;
//     int nov=30;
//     int dec=31;
//     string getmonth(int i){
//         string months_name[12]={"jan","feb","march","april","may","june","july","aug","sept","oct","nov","dec"};
//         return months_name[i];

//     }
// };
// // void calculate(int input_days){
// //     int days=0;
// //     int month=0;
// //     int year=0;
// // }

// int main(){
//     // enum normal_year{jan,feb,march,,31,};
//     // string months_name[12]={"jan","feb","march","april","may","june","july","aug","sept","oct","nov","dec"};
//     int days=0;
//     int month=0;
//     int year=0;
//     int input_days;
//     cout<<"days?"<<endl;
//     cin>>input_days;
//     // for(int i=1;i<=input_days;i++){
//         if (year%4==0){
//             leap_year obj_leap_year;
//             while(true){
//                 int i=0;
//                 string month=months_name[i];
//                 if (input_days>=obj_leap_year.(obj_leap_year.getmonth(i))){
//                     // code here
//                 }
//             }
//         }
// }





//q1 final answer



// #include<iostream>
// using namespace std;
// int main(){
//     string months_name[12]={"jan","feb","march","april","may","june","july","aug","sept","oct","nov","dec"};
//     int year=0;
//     int months=0;
//     bool leap_year_bool;
//     int input_days;
//     cout<<"days?"<<endl;
//     cin>>input_days;
    
//     while(input_days>=365){
//         if (year%400==0 or (year%4==0 && year%100!=0)){
//             leap_year_bool=true;
//         }
//         else{
//             leap_year_bool=false;
//         }
//         if(input_days>=366 &&(leap_year_bool==1)){
//             input_days=input_days-366;
//             year++;
//             continue;
//         }
//         else if(input_days>=365 &&(leap_year_bool==0)){
//             input_days=input_days-365;
//             year++;
//             continue;
//         }
//         break;
//     }
//     while(input_days<=365){
//         if (input_days>=31 &&(months==0 or months==2 or months==4 or months==6 or months==7 or months==9 or months==11)){
//             input_days=input_days-31;
//             months++;
//             continue;
//         }
//         else if(input_days>=30 &&(months==3 or months==5 or months==8 or months==10)){
//             input_days=input_days-30;
//             months++;
//             continue;
//         }
//         else if(input_days>=29 &&(months==1)){
//             if (leap_year_bool==1){
//                 input_days=input_days-29;
//                 months++;    
//             }
//             else{
//                 input_days=input_days-28;
//                 months++;    
//             }
//             continue;
//         }
//         break;
//     }
//     if (input_days==0){
//         input_days++;
//     };


//     cout<<"no of years compleated:"<<year<<endl;

//     // cout<<"no of months compleated"<<months<<endl;
//     // cout<<"no of days completed"<<input_days<<endl; 

//     cout<<"current date:"<<input_days<<" "<<months_name[months]<<" "<<year<<" "<<"AD"<<endl;
// }


