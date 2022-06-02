#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student {
   unsigned int id;
   string name;
   string major;
   float gpa;
};

void populate_student_db_info(student std_arr[], int n, ifstream & fin);
string highest_gpa(student std_arr[], int n);
float average_gpa(student std_arr[], int n);
int cs_students(student std_arr[], int n);

int main(){
   ifstream fin;
   ofstream fout;

   fin.open("input.txt");
   if (!fin.is_open()){
      cout << "File not found!" << endl;
      return 1;
   }
   student students[50];
   int num_students;
   fin >> num_students; 
   populate_student_db_info(students, num_students, fin);  

   fout.open("output.txt");
   if (!fout.is_open()){
   	cout << "File not found!" << endl;
   	return 1;
   }
   fout << "THE STUDENT WITH THE HIGHEST GPA IS: " << highest_gpa(students, num_students) << endl;
   fout << "THE AVERAGE GPA IS: " << average_gpa(students, num_students) << endl;
   fout << "THE AMOUNT OF CS STUDENTS IS: " << cs_students(students, num_students) << endl;	
   fout.close();
   return 0;
}

void populate_student_db_info(student std_arr[], int n, ifstream & fin){
	for (int i = 0; i < n; i++){
		fin >> std_arr[i].id;
		fin >> std_arr[i].name;
		fin >> std_arr[i].major;
		fin >> std_arr[i].gpa;
	}
	fin.close();
}

string highest_gpa(student std_arr[], int n){
   	float highest = 0;
	int student = 0;
	for (int i = 0; i < n; i++){
		if (std_arr[i].gpa > highest){
		highest = std_arr[i].gpa;
		student = i;
		}
	}
	return std_arr[student].name;
}

float average_gpa(student std_arr[], int n){
   float total = 0;
   int students = n;
   for (int i = 0; i < n; i++){
      total += std_arr[i].gpa;
   }
   total = total / students;
   return total;
}

int cs_students(student std_arr[], int n){
	int total = 0;
	for (int i = 0; i < n; i++){
		if (std_arr[i].major == "CS"){
		total++;
		}
	}
	return total;
}
